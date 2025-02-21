#include "GameObjects/SpaceShipObject.h"

#include "GameObjects/GameObjectComponents/PlayerInputComponent.h"
#include "GameScene/GameObjects/GameObjectComponents/MovementComponents/KinematicsComponent.h"
#include "GameScene/GameObjects/GameObjectComponents/SpriteComponent.h"

SpaceShipObject::SpaceShipObject(
	GameFactory::IGameScene* sceneOwner,
	GameFactory::IRenderManager& renderManager,
	GameFactory::IInputProcessor& inputProcessor,
	const sf::Texture& texture)
	: GameObjectBase(sceneOwner) {
	AddComponent<GameFactory::SpriteComponent>(this, renderManager, texture, GameFactory::DefaultUpdateOrder);
	auto* kinematicsComponent = AddComponent<GameFactory::KinematicsComponent>(this, GameFactory::DefaultUpdateOrder);
	// kinematicsComponent->SetVelocity({2.f, 5.f});
	AddComponent<PlayerInputComponent>(this, inputProcessor, *kinematicsComponent);
}

void SpaceShipObject::Init() {
}

void SpaceShipObject::Deinit() {
}

void SpaceShipObject::PreUpdate(float deltaTime) {

}

void SpaceShipObject::PostUpdate(float deltaTime) {

}
