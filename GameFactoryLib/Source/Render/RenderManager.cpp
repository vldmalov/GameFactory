#include "Render/RenderManager.h"

namespace GameFactory {
RenderManager::RenderManager(sf::RenderTarget& renderTarget)
	: mRenderTarget(renderTarget) {
}

void RenderManager::Init() {
}

void RenderManager::Deinit() {
	mSpriteComponents.clear();
}

void RenderManager::Render() {
	for (auto* sprite : mSpriteComponents) {
		sprite->Render(mRenderTarget);
	}
}

void RenderManager::AddSprite(SpriteComponent* sprite) {
	mSpriteComponents.emplace_back(sprite);
}

void RenderManager::RemoveSprite(SpriteComponent* sprite) {
	const auto& spriteIt = std::find(mSpriteComponents.begin(), mSpriteComponents.end(), sprite);
	if (spriteIt != mSpriteComponents.end()) {
		mSpriteComponents.erase(spriteIt);
	}
}


}