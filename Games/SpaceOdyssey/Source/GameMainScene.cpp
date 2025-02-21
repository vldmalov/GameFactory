#include "GameMainScene.h"

#include <iostream>

#include "GameObjects/BackgroundObject.h"
#include "GameObjects/SpaceShipObject.h"
#include "GameObjects/EnemySpaceShipObject.h"
#include "Resources/IResourceManager.h"

GameMainScene::GameMainScene(
	GameFactory::IRenderManager& renderManager,
	GameFactory::IInputProcessor& inputProcessor,
	GameFactory::IResourceManager& resourceManager)
	:GameFactory::GameScene(renderManager, inputProcessor)
	, mResourceManager(resourceManager) {
}

void GameMainScene::Init(const sf::Vector2u& windowSize) {
	if (!mResourceManager.HasTexture("SpaceShip.png") ||!mResourceManager.HasTexture("StarsSky.jpg")) {
		std::cerr << "GameMainScene::Init. Failed to load essential resources" << std::endl;
		return;
	}
	std::unique_ptr<GameFactory::GameObjectBase> background = std::make_unique<BackgroundObject>(
		this,
		GetRenderManager(),
		mResourceManager.GetTexture("StarsSky.jpg"));
	background->SetPosition(sf::Vector2f(windowSize.x/2, windowSize.y/2));
	background->SetScale(0.33f);
	AddGameObject(std::move(background));

	std::unique_ptr<GameFactory::GameObjectBase> spaceShip = std::make_unique<SpaceShipObject>(
		this,
		GetRenderManager(),
		GetInputProcessor(),
		mResourceManager.GetTexture("SpaceShip.png"));
	spaceShip->SetPosition(sf::Vector2f(windowSize.x/2, windowSize.y/2));
	spaceShip->SetRotation( -M_PI / 2.f );
	spaceShip->SetScale(0.6f);
	AddGameObject(std::move(spaceShip));

	std::unique_ptr<GameFactory::GameObjectBase> enemySpaceShip = std::make_unique<EnemySpaceShipObject>(
		this,
		GetRenderManager(),
		mResourceManager.GetTexture("SpaceShip.png"));
	enemySpaceShip->SetScale(0.4f);
	AddGameObject(std::move(enemySpaceShip));

	GameScene::Init(windowSize); // TODO: Refactoring. Why it's called at the end of the method? Confusing..
}