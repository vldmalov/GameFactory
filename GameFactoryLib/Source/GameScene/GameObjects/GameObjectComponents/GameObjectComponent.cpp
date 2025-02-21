#include "GameScene/GameObjects/GameObjectComponents/GameObjectComponent.h"
#include "GameScene/GameObjects/GameObjectBase.h"

namespace GameFactory {
GameObjectComponent::GameObjectComponent(GameObjectBase* owner, ComponentUpdateOrder updateOrder)
	: mOwner(owner)
	, mUpdateOrder(updateOrder) {
	RegisterComponent();
}

GameObjectComponent::~GameObjectComponent() {
	UnregisterComponent();
}

void GameObjectComponent::RegisterComponent() {

}

void GameObjectComponent::UnregisterComponent() {

}
}