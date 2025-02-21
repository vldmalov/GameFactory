#pragma once

#include "GameScene/GameObjects/GameObjectBase.h"

namespace sf {
class Texture;
}

class SpaceShipObject : public GameFactory::GameObjectBase {
public:
	SpaceShipObject(
		GameFactory::IGameScene* sceneOwner,
		GameFactory::IRenderManager& renderManager,
		GameFactory::IInputProcessor& inputProcessor,
		const sf::Texture& texture);
	void Init() override;
	void Deinit() override;

protected:
	void PreUpdate(float deltaTime) override;
	void PostUpdate(float deltaTime) override;
};