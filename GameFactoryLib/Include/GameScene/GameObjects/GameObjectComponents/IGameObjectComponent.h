#pragma once

namespace GameFactory {
class IGameObjectComponent {
public:
	virtual ~IGameObjectComponent() = default;

	virtual void Update(float deltaTime) = 0;
};
}