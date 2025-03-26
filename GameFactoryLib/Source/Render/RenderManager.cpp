#include "Render/RenderManager.h"

namespace GameFactory {
RenderManager::RenderManager(sf::RenderTarget& renderTarget)
	: mRenderTarget(renderTarget) {
}

void RenderManager::Init() {
}

void RenderManager::Deinit() {
	mDrawables.clear();
}

void RenderManager::Render() {
	for (auto* drawable : mDrawables) {
		drawable->Render(mRenderTarget);
	}
}

void RenderManager::AddDrawable(IDrawable* drawable) {
	mDrawables.emplace_back(drawable);
}

void RenderManager::RemoveDrawable(IDrawable* drawable) {
	const auto& drawableIt = std::find(mDrawables.begin(), mDrawables.end(), drawable);
	if (drawableIt != mDrawables.end()) {
		mDrawables.erase(drawableIt);
	}
}

}