#pragma once

#include <SFML/Window/Event.hpp>
#include <SFML/System/Vector2.hpp>

namespace GameFactory {

class InputComponent;

class IInputProcessor {
public:
	virtual ~IInputProcessor() = default;

	virtual void Init() = 0;
	virtual void Deinit() = 0;

	virtual bool OnKeyPressed(const sf::Event::KeyPressed* eventData) = 0;
	virtual bool OnKeyReleased(const sf::Event::KeyReleased* eventData) = 0;
	virtual void OnMouseMoved(const sf::Vector2i& from, const sf::Vector2i& to) = 0;
	virtual void OnMouseButtonPressed(const sf::Vector2i& mousePos) = 0;
	virtual void OnMouseButtonReleased(const sf::Vector2i& mousePos) = 0;

	virtual void AddInputComponent(InputComponent* inputComponent) = 0;
	virtual void RemoveInputComponent(InputComponent* inputComponent) = 0;
};

}