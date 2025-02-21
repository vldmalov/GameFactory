#pragma once

#include "GameScene/GameScene.h"

namespace GameFactory {
	class IRenderManager;
	class IInputProcessor;
	class IResourceManager;
}

class GameMainScene : public GameFactory::GameScene {
public:
	explicit GameMainScene(
		GameFactory::IRenderManager& renderManager,
		GameFactory::IInputProcessor& inputProcessor,
		GameFactory::IResourceManager& resourceManager);
	~GameMainScene() override = default;

	void Init(const sf::Vector2u& windowSize) override;

private:
	GameFactory::IResourceManager& mResourceManager;
	// void UpdateSpacecraftLocation(float deltaTime);

	// Common::Text mTitleText;
	// sf::Sprite mSpacecraftSprite;
	// sf::Sprite mMoonSprite;

	// sf::Vector2f mMoonPos{ 0.f, 0.f };
	// float mMoonRadius{ 0.f };
	// float mSpacecraftOrbitDistance{ 50.f };
	// float mSpacecraftOrbitAngle{ 0.f };
	// float mSpacecraftSpeed{ 100.f };

};