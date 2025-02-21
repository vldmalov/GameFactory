#pragma once

#include "GameScene/GameObjects/IGameObject.h"

#include <SFML/System/Vector2.hpp>
#include <SFML/Window/Event.hpp>
#include <memory>

namespace GameFactory {

class IGameScene {
public:
	virtual ~IGameScene() = default;

	virtual void Init(const sf::Vector2u& windowSize) = 0;
	virtual void Deinit() = 0;

	virtual void Update(float deltaTime) = 0;

	virtual GameObjectId AddGameObject(std::unique_ptr<IGameObject>&& object) = 0;
	virtual void RemoveGameObject(GameObjectId id) = 0;

	virtual void OnResize(const sf::Vector2u& windowSize) = 0;

protected:
	virtual void InitGameObjects(const sf::Vector2u& windowSize) = 0;
	virtual void PreUpdate(float deltaTime) = 0;
	virtual void PostUpdate(float deltaTime) = 0;
};
}