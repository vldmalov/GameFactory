#pragma once

#include "IGameObjectComponent.h"

namespace GameFactory {
using ComponentUpdateOrder = unsigned short;
const ComponentUpdateOrder DefaultUpdateOrder = 10;

class GameObjectBase;

class GameObjectComponent : public IGameObjectComponent {
public:
	explicit GameObjectComponent(GameObjectBase* owner, ComponentUpdateOrder updateOrder = DefaultUpdateOrder);
	~GameObjectComponent() override;

	void Update(float deltaTime) override {};

private:
	void RegisterComponent();
	void UnregisterComponent();

protected:
	GameObjectBase* mOwner;
	ComponentUpdateOrder mUpdateOrder;
};
}