#include "GameScene/GameObjects/GameObjectComponents/MovementComponents/CircleMovementComponent.h"
#include "GameScene/GameObjects/GameObjectBase.h"

namespace GameFactory {
CircleMovementComponent::CircleMovementComponent(
	GameObjectBase* owner,
	ComponentUpdateOrder updateOrder,
	const sf::Vector2f& rotationPoint,
	float rotationRadius,
	float angularSpeed,
	float startAngle,
	bool movementDirection)
	: GameObjectComponent(owner, updateOrder)
	, mCurrentAngle{ startAngle }
	, mRotationPoint{ rotationPoint }
	, mRotationRadius{ rotationRadius }
	, mAngularSpeed{ angularSpeed }
	, mMovementDirection{ movementDirection }
{
}

void CircleMovementComponent::Update(float deltaTime) {
	mCurrentAngle += mAngularSpeed * deltaTime;
	sf::Vector2f currentPosition = mRotationPoint;
	currentPosition.x += mRotationRadius * cos(mCurrentAngle);
	currentPosition.y += mRotationRadius * sin(mCurrentAngle);

	mOwner->SetPosition(currentPosition);

	if (mMovementDirection) {
		mOwner->SetRotation(mCurrentAngle - M_PI_2); // TODO: Why -M_PI_2?
	}
}

}