#pragma once

#include <memory>
#include <unordered_map>

#include "GameScene/GameObjects/IGameObject.h"
#include "IGameScene.h"

namespace GameFactory {

class IRenderManager;
class IInputProcessor;

class GameScene : public IGameScene{
public:
	GameScene(IRenderManager& renderManager, IInputProcessor& inputProcessor);
	~GameScene() override = default;

	void Init(const sf::Vector2u& windowSize) override;
	void Deinit() override;
	void Update(float deltaTime) override;

	GameObjectId AddGameObject(std::unique_ptr<IGameObject>&& object) override;
	void RemoveGameObject(GameObjectId id) override;

	void OnResize(const sf::Vector2u& windowSize) override;

protected:
	void InitGameObjects(const sf::Vector2u& windowSize) override final;

	void PreUpdate(float deltaTime) override;
	void PostUpdate(float deltaTime) override;

	IRenderManager& GetRenderManager() { return mRenderManager; };
	IInputProcessor& GetInputProcessor() { return mInputProcessor; };

private:
	void UpdateObjects(float deltaTime);

	IRenderManager& mRenderManager;
	IInputProcessor& mInputProcessor;
	std::unordered_map<GameObjectId, std::unique_ptr<IGameObject>> mObjects{};
	GameObjectId mLastUsedObjectId{ 0 };
};
}