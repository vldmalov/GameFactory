#pragma once

#include "GameScene/GameObjects/GameObjectBase.h"

namespace sf {
class Texture;
}

class EnemySpaceShipObject : public GameFactory::GameObjectBase {
public:
	EnemySpaceShipObject(
		GameFactory::IGameScene* sceneOwner,
		GameFactory::IRenderManager& renderManager,
		const sf::Texture& texture);
	void Init() override;
	void Deinit() override;

protected:
	void PreUpdate(float deltaTime) override;
	void PostUpdate(float deltaTime) override;
};