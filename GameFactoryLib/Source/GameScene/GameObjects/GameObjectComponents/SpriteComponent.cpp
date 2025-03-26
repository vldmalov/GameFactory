#include "GameScene/GameObjects/GameObjectComponents/SpriteComponent.h"
#include "GameScene/GameObjects/GameObjectBase.h"

#include "Render/IRenderManager.h"

namespace GameFactory {
SpriteComponent::SpriteComponent(GameObjectBase* owner, IRenderManager& renderManager, const sf::Texture& texture, ComponentUpdateOrder updateOrder)
	: GameObjectComponent(owner, updateOrder)
	, mRenderManager(renderManager)
	, mSprite(texture) {
	mRenderManager.AddDrawable(this);
}

SpriteComponent::~SpriteComponent() {
	mRenderManager.RemoveDrawable(this);
}

void SpriteComponent::Update(float deltaTime) {
	const float scale = mOwner->GetScale();
	const sf::Vector2f spriteCenter{ mSprite.getLocalBounds().getCenter() };
	mSprite.setOrigin(spriteCenter);
	mSprite.setPosition(mOwner->GetPosition());
	mSprite.setRotation(sf::radians(mOwner->GetRotation()));
	mSprite.setScale({scale, scale});
}

void SpriteComponent::Render(sf::RenderTarget& renderTarget) {
	renderTarget.draw(mSprite);
};
}