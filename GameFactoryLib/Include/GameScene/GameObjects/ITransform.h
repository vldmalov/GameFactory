#pragma once

#include <SFML/System/Vector2.hpp>

namespace GameFactory {

// TODO: SFML should have the same
class ITransform {
public:
	virtual ~ITransform() = default;

	virtual void SetPosition(const sf::Vector2f&) = 0;
	virtual void SetRotation(float) = 0;
	virtual void SetScale(float) = 0;

	virtual sf::Vector2f GetPosition() const = 0;
	virtual float GetRotation() const = 0;
	virtual float GetScale() const = 0;
};
}