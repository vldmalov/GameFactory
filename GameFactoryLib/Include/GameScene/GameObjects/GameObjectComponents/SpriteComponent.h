#pragma once

#include "GameScene/GameObjects/GameObjectComponents/GameObjectComponent.h"

#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Sprite.hpp>

namespace GameFactory {

class IRenderManager;

class SpriteComponent final : public GameObjectComponent {
public:
	SpriteComponent(GameObjectBase* owner, IRenderManager& renderManager, const sf::Texture& texture, ComponentUpdateOrder updateOrder);
	~SpriteComponent() override;

	void Update(float deltaTime) override;
	void Render(sf::RenderTarget& renderTarget);

private:
	IRenderManager& mRenderManager;
	sf::Sprite mSprite;
};
}