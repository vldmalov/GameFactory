#pragma once

#include "IDrawable.h"

namespace GameFactory {

class SpriteComponent;

class IRenderManager {
public:
	virtual ~IRenderManager() = default;

	virtual void Init() = 0;
	virtual void Deinit() = 0;

	virtual void Render() = 0;

	virtual void AddDrawable(IDrawable* sprite) = 0;
	virtual void RemoveDrawable(IDrawable* sprite) = 0;
};

}