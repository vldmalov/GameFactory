#pragma once

namespace GameFactory {

class SpriteComponent;

class IRenderManager {
public:
	virtual ~IRenderManager() = default;

	virtual void Init() = 0;
	virtual void Deinit() = 0;

	virtual void Render() = 0;

	virtual void AddSprite(SpriteComponent* sprite) = 0;
	virtual void RemoveSprite(SpriteComponent* sprite) = 0;
};

}