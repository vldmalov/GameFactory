#pragma once

#include <GameScene/GameObjects/GameObjectComponents/GameObjectComponent.h>
#include <SFML/System/Vector2.hpp>

namespace GameFactory {
class KinematicsComponent final : public GameObjectComponent {
public:
	KinematicsComponent(GameObjectBase* owner, ComponentUpdateOrder updateOrder);
	~KinematicsComponent() override = default;

	void Update(float deltaTime) override;

	void SetVelocity(const sf::Vector2f&);
	void SetAcceleration(const sf::Vector2f&);

	sf::Vector2f GetVelocity() const;
	sf::Vector2f GetAcceleration() const;

private:
	sf::Vector2f mVelocity{0.f, 0.f};
	sf::Vector2f mAcceleration{0.f, 0.f};
};
}