#pragma once

#include "IRenderManager.h"
#include "GameScene/GameObjects/GameObjectComponents/SpriteComponent.h"

#include <SFML/Graphics/RenderTarget.hpp>
#include <vector>

namespace GameFactory {
class RenderManager final : public IRenderManager {
public:
	explicit RenderManager(sf::RenderTarget& renderTarget);
	~RenderManager() = default;

	void Init() override;
	void Deinit() override;

	void Render() override;

	void AddSprite(SpriteComponent* sprite) override;
	void RemoveSprite(SpriteComponent* sprite) override;

private:
	sf::RenderTarget& mRenderTarget;
	std::vector<GameFactory::SpriteComponent*> mSpriteComponents;
};
}