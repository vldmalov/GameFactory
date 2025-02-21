#pragma once

#include "IAppUpdater.h"

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>

namespace GameFactory {

class IAppDelegate;

class AppUpdater : public IAppUpdater {
public:
	explicit AppUpdater(IAppDelegate& appDelegate);
	~AppUpdater() override = default;

	void Init(sf::Vector2u windowSize, const sf::String& windowTitle) override;
	void Deinit() override;

	void Run() override;
	void SetFrameRate(unsigned short fps) override;

private:
	void RunMainLoop();
	void EventHandler();
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
	float mTimePerFrame{};

	float mTotalElapsedTime{}; // TODO: Should it be here?
	float mTotalSimulationTime{};

	sf::Vector2i mMousePos{}; // TODO: Should it be here?
};
}