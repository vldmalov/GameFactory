#pragma once

#include "GameScene/GameObjects/GameObjectComponents/IGameObjectComponent.h"
#include "GameScene/GameScene.h"
#include "IGameObject.h"
#include "ITransform.h"

#include <vector>
#include <memory>
#include <cassert>

namespace GameFactory {

// TODO: Do we really need IGameObject interface?
class GameObjectBase : public IGameObject, public ITransform {
public:
	explicit GameObjectBase(IGameScene* sceneOwner);
	virtual ~GameObjectBase() = default;

	void Update(float deltaTime) override final;

	// ITransform
	void SetPosition(const sf::Vector2f& position) override { mPosition = position; }
	void SetRotation(float rotation) override { mRotation = rotation; }
	void SetScale(float scale) override { mScale = scale; }

	sf::Vector2f GetPosition() const override { return mPosition; }
	float GetRotation() const override { return mRotation; }
	float GetScale() const override { return mScale; }

	// Components
	template <typename COMPONENT_TYPE, typename... Args>
	COMPONENT_TYPE* AddComponent(Args&&... args);
	template <typename COMPONENT_TYPE>
	bool HasComponent() const;
	template <typename COMPONENT_TYPE>
	const COMPONENT_TYPE* GetComponent() const;
	template <typename COMPONENT_TYPE>
	bool RemoveComponent();

protected:
	void PreUpdate(float deltaTime) override {};
	void PostUpdate(float deltaTime) override {};

private:
	void UpdateComponents(float deltaTime);

protected:
	IGameScene* mSceneOwner{ nullptr };
	sf::Vector2f mPosition{};
	float mRotation{ 0.f };
	float mScale{ 1.f };

	std::vector<std::unique_ptr<IGameObjectComponent>> mComponents;
};

template <typename COMPONENT_TYPE, typename... Args>
COMPONENT_TYPE* GameObjectBase::AddComponent(Args&&... args) {
	static_assert(std::is_base_of<IGameObjectComponent, COMPONENT_TYPE>::value,
		"COMPONENT_TYPE must be derived from IGameObjectComponent");

	for (const auto& component : mComponents) {
		if (dynamic_cast<COMPONENT_TYPE*>(component.get())) {
			// TODO: Fix asserts for NDEBUG
			assert("GameObject::AddComponent: Component of this type already exists!");
			return nullptr;
		}
	}

	std::unique_ptr<COMPONENT_TYPE> component = std::make_unique<COMPONENT_TYPE>(std::forward<Args>(args)...);
	COMPONENT_TYPE* rawPtr = component.get();
	mComponents.push_back(std::move(component));
	return rawPtr;
}

template <typename COMPONENT_TYPE>
bool GameObjectBase::HasComponent() const {
	static_assert(std::is_base_of<IGameObjectComponent, COMPONENT_TYPE>::value,
		"COMPONENT_TYPE must be derived from IGameObjectComponent");

	for (const auto& component : mComponents) {
		if (dynamic_cast<COMPONENT_TYPE*>(component.get())) {
			return true;
		}
	}
	return false;
}

template <typename COMPONENT_TYPE>
const COMPONENT_TYPE* GameObjectBase::GetComponent() const {
	static_assert(std::is_base_of<IGameObjectComponent, COMPONENT_TYPE>::value,
		"COMPONENT_TYPE must be derived from IGameObjectComponent");

	for (const auto& component : mComponents) {
		if (auto ptr = dynamic_cast<COMPONENT_TYPE*>(component.get())) {
			return ptr;
		}
	}
	return nullptr;
}

template <typename COMPONENT_TYPE>
bool GameObjectBase::RemoveComponent() {
	static_assert(std::is_base_of<IGameObjectComponent, COMPONENT_TYPE>::value,
		"COMPONENT_TYPE must be derived from IGameObjectComponent");

	for (auto it = mComponents.begin(); it != mComponents.end(); ++it) {
		if (auto ptr = dynamic_cast<COMPONENT_TYPE*>(it->get())) {
			mComponents.erase(it);
			return true;
		}
	}
	return false;
}

}