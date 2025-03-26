#pragma once

#include "IAppUpdater.h"
#include "AppUpdater/AppUpdaterFrame.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

namespace GameFactory {

class IAppDelegate;

class AppUpdater : public IAppUpdater {
public:
	explicit AppUpdater(IAppDelegate& appDelegate);
	~AppUpdater() override = default;

	void Init(sf::Vector2u windowSize, const sf::String& windowTitle, unsigned int frameRate) override;
	void Deinit() override;

	void RunMainLoop() override;

private:
	void SetFrameRate(unsigned short fps);

	void ProcessEvents();
	void Update(float deltaTime);
	void Render();

	void UpdateViewport(const sf::Vector2u& newSize);

	void OnKeyPressed(const sf::Event::KeyPressed* event);
	void OnKeyReleased(const sf::Event::KeyReleased* event);
	void OnMouseMoved(const sf::Event::MouseMoved* event);
	void OnMouseButtonPressed(const sf::Event::MouseButtonPressed* event);
	void OnMouseButtonReleased(const sf::Event::MouseButtonReleased* event);
	void OnResize(const sf::Event::Resized* event);

	sf::RenderWindow mWindow;

	uint mFrameRate{};
	AppUpdaterFrame mAppUpdaterFrame{};

	sf::Vector2i mMousePos{}; // TODO: Should it be here?
};
}