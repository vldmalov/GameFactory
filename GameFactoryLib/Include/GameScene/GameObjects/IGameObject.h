#pragma once

namespace GameFactory {
using GameObjectId = unsigned int;

class IGameObject {
public:
	virtual ~IGameObject() = default;

	virtual void Init() = 0;
	virtual void Deinit() = 0;
	virtual void Update(float deltaTime) = 0;

protected:
	virtual void PreUpdate(float deltaTime) = 0;
	virtual void PostUpdate(float deltaTime) = 0;
};
}