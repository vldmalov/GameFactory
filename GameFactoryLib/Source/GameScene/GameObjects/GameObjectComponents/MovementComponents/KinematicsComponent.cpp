#include "../../../../../Include/GameScene/GameObjects/GameObjectComponents/MovementComponents/KinematicsComponent.h"
#include "GameScene/GameObjects/GameObjectBase.h"

namespace GameFactory {
KinematicsComponent::KinematicsComponent(GameObjectBase* owner, ComponentUpdateOrder updateOrder)
	: GameObjectComponent(owner, updateOrder) {
}

void KinematicsComponent::Update(float deltaTime) {
	sf::Vector2f objPos = mOwner->GetPosition();
	objPos += mVelocity * deltaTime;
	mVelocity += mAcceleration * deltaTime;

	mOwner->SetPosition(objPos);
}

void KinematicsComponent::SetVelocity(const sf::Vector2f& velocity) {
	mVelocity = velocity;
}

void KinematicsComponent::SetAcceleration(const sf::Vector2f& acceleration) {
	mAcceleration = acceleration;
}

sf::Vector2f KinematicsComponent::GetVelocity() const {
	return mVelocity;
}

sf::Vector2f KinematicsComponent::GetAcceleration() const {
	return mAcceleration;
}


}