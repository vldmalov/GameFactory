#include "GameScene/GameScene.h"

#include <iostream>

namespace GameFactory {

GameScene::GameScene(IRenderManager& renderManager, IInputProcessor& inputProcessor)
	: mRenderManager(renderManager)
	, mInputProcessor(inputProcessor) {
}

void GameScene::Init(const sf::Vector2u& windowSize) {
	InitGameObjects(windowSize);
}

void GameScene::Deinit() {
	mObjects.clear();
}

void GameScene::Update(float deltaTime) {
	PreUpdate(deltaTime);
	UpdateObjects(deltaTime);
	PostUpdate(deltaTime);
}

void GameScene::UpdateObjects(float deltaTime) {
	for (auto& object : mObjects) {
		object.second->Update(deltaTime);
	}
}

void GameScene::PreUpdate(float deltaTime) {
	// Empty. Might be implemented in derived class
}

void GameScene::PostUpdate(float deltaTime) {
	// Empty. Might be implemented in derived class
}

GameObjectId GameScene::AddGameObject(std::unique_ptr<IGameObject>&& object) {
	// TODO: In case when during the update loop object was added
	// It should go to separate data structure
	// Also we have to check if some objects should be removed/destroyed (pg 40)
	mObjects[++mLastUsedObjectId] = std::move(object);
	return mLastUsedObjectId;
}

void GameScene::RemoveGameObject(GameObjectId id) {
	if (mObjects.find(id) != mObjects.end()) {
		mObjects.erase(id);
	} else {
		std::cerr << "GameScene::RemoveGameObject: Object id = " << id << "does not exist" << std::endl;
	}
}

void GameScene::InitGameObjects(const sf::Vector2u& windowSize) {
	for (auto& object : mObjects) {
		object.second->Init();
	}
}

void GameScene::OnResize(const sf::Vector2u& windowSize) {

}

}