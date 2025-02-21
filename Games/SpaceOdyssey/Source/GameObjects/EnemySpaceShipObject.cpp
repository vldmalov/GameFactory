#include "GameObjects/EnemySpaceShipObject.h"

#include "GameScene/GameObjects/GameObjectComponents/MovementComponents/CircleMovementComponent.h"
#include "GameScene/GameObjects/GameObjectComponents/SpriteComponent.h"

EnemySpaceShipObject::EnemySpaceShipObject(
	GameFactory::IGameScene* sceneOwner,
	GameFactory::IRenderManager& renderManager,
	const sf::Texture& texture)
	: GameObjectBase(sceneOwner) {
	AddComponent<GameFactory::SpriteComponent>(this, renderManager, texture, GameFactory::DefaultUpdateOrder);

	// TODO: Read properties from file
	AddComponent<GameFactory::CircleMovementComponent>(
		this,
		GameFactory::DefaultUpdateOrder,
		sf::Vector2f(512.f, 384.f),
		350.f,
		-0.4,
		M_PI,
		true);
}

void EnemySpaceShipObject::Init() {
}

void EnemySpaceShipObject::Deinit() {
}

void EnemySpaceShipObject::PreUpdate(float deltaTime) {

}

void EnemySpaceShipObject::PostUpdate(float deltaTime) {

}
