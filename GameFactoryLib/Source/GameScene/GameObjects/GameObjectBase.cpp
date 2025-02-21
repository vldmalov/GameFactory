#include "GameScene/GameObjects/GameObjectBase.h"

namespace GameFactory {
GameObjectBase::GameObjectBase(IGameScene* sceneOwner)
	: mSceneOwner(sceneOwner) {
}

void GameObjectBase::Update(float deltaTime) {
	PreUpdate(deltaTime);
	UpdateComponents(deltaTime);
	PostUpdate(deltaTime);
};

void GameObjectBase::UpdateComponents(float deltaTime) {
	for (auto& component : mComponents) {
		component->Update(deltaTime);
	}
}

}