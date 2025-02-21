#pragma once

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/System/Vector2.hpp>

namespace GameFactory {

class IAppDelegate {
public:
	virtual ~IAppDelegate() = default;

	virtual void Init(sf::RenderTarget& renderTarget) = 0;
	virtual void Deinit() = 0;

	virtual void Update(float deltaTime) = 0;
	virtual void Render(sf::RenderTarget& renderTarget) = 0;

	virtual void OnResize(const sf::Vector2u& windowSize) = 0;
	virtual bool OnKeyPressed(const sf::Event::KeyPressed* eventData) = 0;
	virtual bool OnKeyReleased(const sf::Event::KeyReleased* eventData) = 0;
	virtual void OnMouseMoved(const sf::Vector2i& from, const sf::Vector2i& to) = 0;
	virtual void OnMouseButtonPressed(const sf::Vector2i& mousePos) = 0;
	virtual void OnMouseButtonReleased(const sf::Vector2i& mousePos) = 0;

	virtual bool IsFinished() const = 0;
};

}