#pragma once

#include "GameScene/GameObjects/GameObjectBase.h"

namespace sf {
class Texture;
}

class BackgroundObject : public GameFactory::GameObjectBase {
public:
	BackgroundObject(
		GameFactory::IGameScene* sceneOwner,
		GameFactory::IRenderManager& renderManager,
		const sf::Texture& texture);
	void Init() override;
	void Deinit() override;

protected:
	void PreUpdate(float deltaTime) override;
	void PostUpdate(float deltaTime) override;
};