#include "AppUpdater.h"

#include <iostream>

#include "IAppDelegate.h"

#include <optional>
#include <ostream>

namespace GameFactory {
static const unsigned DefaultFrameRate = 30;

AppUpdater::AppUpdater(IAppDelegate& appDelegate)
: IAppUpdater(appDelegate) {
	SetFrameRate(DefaultFrameRate);
}

void AppUpdater::Init(sf::Vector2u windowSize, const sf::String& windowTitle) {
	srand(static_cast<unsigned int>(time(0)));

	mWindow.create(sf::VideoMode(windowSize), windowTitle);
	mAppDelegate.Init(mWindow);
}

void AppUpdater::Deinit() {
	mAppDelegate.Deinit();
}

void AppUpdater::Run() {
	RunMainLoop();
}

void AppUpdater::SetFrameRate(unsigned short fps) {
	mFrameRate = fps;
	mWindow.setFramerateLimit(fps);

	mTimePerFrame = 1.0f / fps;
}

void AppUpdater::RunMainLoop() {
	sf::Clock timer;
	while (mWindow.isOpen() && !mAppDelegate.IsFinished()) {
		const auto deltaTime = timer.restart().asSeconds();
		mTotalElapsedTime += deltaTime;
		mTotalSimulationTime += mTimePerFrame;
		std::cout << "Delta Time: " << deltaTime << " Calculated delta time: " << mTimePerFrame << std::endl;
		std::cout << "Elapsed Time: " << mTotalElapsedTime << " Simulation Time: " << mTotalSimulationTime << std::endl;

		EventHandler();
		Update(mTimePerFrame);
		Render();
	}
}

void AppUpdater::EventHandler() {
	while (const std::optional<sf::Event> event = mWindow.pollEvent()) {
		if (event->is<sf::Event::Closed>()) {
			mWindow.close();
		}
		else if (const auto* eventInfo = event->getIf<sf::Event::KeyPressed>()) {
			OnKeyPressed(eventInfo);
		}
		else if (const auto* eventInfo = event->getIf<sf::Event::KeyReleased>()) {
			OnKeyReleased(eventInfo);
		}
		else if (const auto* eventInfo = event->getIf<sf::Event::MouseMoved>()) {
			OnMouseMoved(eventInfo);
		}
		else if (const auto* eventInfo = event->getIf<sf::Event::MouseButtonPressed>()) {
			OnMouseButtonPressed(eventInfo);
		}
		else if (const auto* eventInfo = event->getIf<sf::Event::MouseButtonReleased>()) {
			OnMouseButtonReleased(eventInfo);
		}
		else if (const auto* eventInfo = event->getIf<sf::Event::Resized>()) {
			OnResize(eventInfo);
		}
	}
}

void AppUpdater::Update(float deltaTime) {
	mAppDelegate.Update(deltaTime);
}

void AppUpdater::Render() {
	mWindow.clear();
	mAppDelegate.Render(mWindow);
	mWindow.display();
}

void AppUpdater::OnKeyPressed(const sf::Event::KeyPressed* event) {
	if (event->scancode == sf::Keyboard::Scancode::Escape) {
		mWindow.close();
	}

	mAppDelegate.OnKeyPressed(event);
}

void AppUpdater::OnKeyReleased(const sf::Event::KeyReleased* event) {
	mAppDelegate.OnKeyReleased(event);
}

void AppUpdater::OnMouseMoved(const sf::Event::MouseMoved* event) {
	if (mMousePos != event->position) {
		mAppDelegate.OnMouseMoved(mMousePos, event->position);
	}
	mMousePos = event->position;
}

void AppUpdater::OnMouseButtonPressed(const sf::Event::MouseButtonPressed* event) {
	mAppDelegate.OnMouseButtonPressed(event->position);
}

void AppUpdater::OnMouseButtonReleased(const sf::Event::MouseButtonReleased* event) {
	mAppDelegate.OnMouseButtonReleased(event->position);
}

void AppUpdater::OnResize(const sf::Event::Resized* event) {
	//const sf::Vector2u windowSize = mWindow.getSize();
	//UpdateViewport(event->size);
	mAppDelegate.OnResize(event->size);
}

void AppUpdater::UpdateViewport(const sf::Vector2u& newSize) {
	sf::View view = mWindow.getView();
	const float viewRatio = view.getSize().x / view.getSize().y;
	const float windowRatio = static_cast<float>(newSize.x) / newSize.y;

	sf::Vector2f size{1.f, 1.f};
	sf::Vector2f position{0.f, 0.f};

	const bool horizontalSpacing = windowRatio > viewRatio;
	if (horizontalSpacing) {
		size.x = viewRatio / windowRatio;
		position.x = 0.5f * (1.f - size.x);
	} else {
		size.y = windowRatio / viewRatio;
		position.y = 0.5f * (1.f - size.y);
	}

	view.setViewport(sf::FloatRect({position.x, position.y}, {size.x, size.y}));
	mWindow.setView(view);
}


}