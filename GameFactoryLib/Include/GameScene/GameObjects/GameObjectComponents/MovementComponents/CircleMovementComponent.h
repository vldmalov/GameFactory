#pragma once

#include <GameScene/GameObjects/GameObjectComponents/GameObjectComponent.h>
#include <SFML/System/Vector2.hpp>

namespace GameFactory {
class CircleMovementComponent final : public GameObjectComponent {
public:
	CircleMovementComponent(
		GameObjectBase* owner,
		ComponentUpdateOrder updateOrder,
		const sf::Vector2f& rotationPoint,
		float rotationRadius,
		float angularSpeed,
		float startAngle,
		bool movementDirection);
	~CircleMovementComponent() override = default;

	void Update(float deltaTime) override;

private:
	const sf::Vector2f mRotationPoint{};
	float mRotationRadius{ 0.f };
	float mAngularSpeed{ 0.f };
	float mCurrentAngle{ 0.f };
	bool mMovementDirection{ false };
};
}