#include "GameObjects/BackgroundObject.h"

#include "GameScene/GameObjects/GameObjectComponents/SpriteComponent.h"

BackgroundObject::BackgroundObject(
	GameFactory::IGameScene* sceneOwner,
	GameFactory::IRenderManager& renderManager,
	const sf::Texture& texture)
	: GameObjectBase(sceneOwner) {
	AddComponent<GameFactory::SpriteComponent>(this, renderManager, texture, GameFactory::DefaultUpdateOrder);
}

void BackgroundObject::Init() {
}

void BackgroundObject::Deinit() {
}

void BackgroundObject::PreUpdate(float deltaTime) {

}

void BackgroundObject::PostUpdate(float deltaTime) {

}
