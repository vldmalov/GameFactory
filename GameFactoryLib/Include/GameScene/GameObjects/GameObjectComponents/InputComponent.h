#pragma once

#include "GameObjectComponent.h"

#include <SFML/Window/Event.hpp>
#include <SFML/System/Vector2.hpp>

namespace GameFactory {

class IInputProcessor;

class InputComponent : public GameObjectComponent {
public:
	InputComponent(GameObjectBase* owner, IInputProcessor& inputProcessor);
	~InputComponent() override;

	virtual bool OnKeyPressed(const sf::Event::KeyPressed* eventData) { return false; };
	virtual bool OnKeyReleased(const sf::Event::KeyReleased* eventData) { return false; };
	virtual void OnMouseMoved(const sf::Vector2i& from, const sf::Vector2i& to) {};
	virtual void OnMouseButtonPressed(const sf::Vector2i& mousePos) {};
	virtual void OnMouseButtonReleased(const sf::Vector2i& mousePos) {};

protected:
	IInputProcessor& mInputProcessor;
};
}