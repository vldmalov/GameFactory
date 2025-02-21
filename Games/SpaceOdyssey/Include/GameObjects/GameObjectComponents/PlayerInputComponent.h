#pragma once

#include "../../../../../GameFactoryLib/Include/GameScene/GameObjects/GameObjectComponents/MovementComponents/KinematicsComponent.h"
#include "GameScene/GameObjects/GameObjectComponents/InputComponent.h"

namespace GameFactory {
class IInputProcessor;
class KinematicsComponent;
}

class PlayerInputComponent final : public GameFactory::InputComponent {
public:
	PlayerInputComponent(
		GameFactory::GameObjectBase* owner,
		GameFactory::IInputProcessor& inputProcessor,
		GameFactory::KinematicsComponent& kinematicsComponent);
	~PlayerInputComponent() override = default;

	bool OnKeyPressed(const sf::Event::KeyPressed* eventData) override;
	bool OnKeyReleased(const sf::Event::KeyReleased* eventData) override;
	void OnMouseMoved(const sf::Vector2i& from, const sf::Vector2i& to) override;
	void OnMouseButtonPressed(const sf::Vector2i& mousePos) override;
	void OnMouseButtonReleased(const sf::Vector2i& mousePos) override;

private:
	GameFactory::KinematicsComponent& mKinematicsComponent;
};