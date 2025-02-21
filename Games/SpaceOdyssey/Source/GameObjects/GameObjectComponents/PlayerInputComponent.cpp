#include "GameObjects/GameObjectComponents/PlayerInputComponent.h"

#include "../../../../../GameFactoryLib/Include/GameScene/GameObjects/GameObjectComponents/MovementComponents/KinematicsComponent.h"
#include "GameScene/GameObjects/GameObjectBase.h"

#include <SFML/System/Vector2.hpp>

PlayerInputComponent::PlayerInputComponent(
	GameFactory::GameObjectBase* owner,
	GameFactory::IInputProcessor& inputProcessor,
	GameFactory::KinematicsComponent& kinematicsComponent)
	: GameFactory::InputComponent(owner, inputProcessor)
	, mKinematicsComponent(kinematicsComponent) {
}

bool PlayerInputComponent::OnKeyPressed(const sf::Event::KeyPressed* eventData) {
	if (eventData->scancode == sf::Keyboard::Scancode::Right) {
		float rotation = mOwner->GetRotation();
		rotation += 0.05f;
		mOwner->SetRotation(rotation);
		return false;
	}
	if (eventData->scancode == sf::Keyboard::Scancode::Left) {
		float rotation = mOwner->GetRotation();
		rotation -= 0.05f;
		mOwner->SetRotation(rotation);
		return false;
	}
	if (eventData->scancode == sf::Keyboard::Scancode::Up) {
		// TODO: Move it away from here to object's class
		const sf::Vector2f velocity = mKinematicsComponent.GetVelocity();
		const float rotation = mOwner->GetRotation();
		sf::Vector2f objectDirection = sf::Vector2(4.f, sf::radians(rotation));
		const sf::Vector2f newVelocity = velocity + objectDirection; // TODO: We need delta time here
		mKinematicsComponent.SetVelocity(newVelocity);

		return false;
	}
	if (eventData->scancode == sf::Keyboard::Scancode::Down) {
		// TODO: Move it away from here to object's class
		const sf::Vector2f velocity = mKinematicsComponent.GetVelocity();
		const float rotation = mOwner->GetRotation();
		sf::Vector2f objectDirection = sf::Vector2(4.f, sf::radians(rotation));
		const sf::Vector2f newVelocity = velocity - objectDirection; // TODO: We need delta time here
		mKinematicsComponent.SetVelocity(newVelocity);
		return false;
	}

	return false;
}

bool PlayerInputComponent::OnKeyReleased(const sf::Event::KeyReleased* eventData) {
	return false;
}

void PlayerInputComponent::OnMouseMoved(const sf::Vector2i& from, const sf::Vector2i& to) {

}

void PlayerInputComponent::OnMouseButtonPressed(const sf::Vector2i& mousePos) {

}

void PlayerInputComponent::OnMouseButtonReleased(const sf::Vector2i& mousePos) {

}