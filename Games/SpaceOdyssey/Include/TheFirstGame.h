#pragma once

#include "IAppDelegate.h"
#include "GameMainScene.h"
#include "Resources/IResourceManager.h"
#include "Render/RenderManager.h"
#include "Input/IInputProcessor.h"

// TODO: Create the base class of the Game and move there mResourceManager and mRenderManager
class TheFirstGame : public GameFactory::IAppDelegate {
public:
	explicit TheFirstGame(const std::string& texturesDir);

	void Init(sf::RenderTarget& renderTarget) override;
	void Deinit() override;

	void Update(float deltaTime) override;
	void Render(sf::RenderTarget& renderTarget) override;
	bool IsFinished() const override;
	void OnResize(const sf::Vector2u& windowSize) override {};
	bool OnKeyPressed(const sf::Event::KeyPressed* eventData) override;
	bool OnKeyReleased(const sf::Event::KeyReleased* eventData) override;
	void OnMouseMoved(const sf::Vector2i& from, const sf::Vector2i& to) override;
	void OnMouseButtonPressed(const sf::Vector2i& mousePos) override;
	void OnMouseButtonReleased(const sf::Vector2i& mousePos) override;

private:
	std::unique_ptr<GameFactory::IResourceManager> mResourceManager{};
	std::unique_ptr<GameFactory::RenderManager> mRenderManager{}; // TODO: Interface instead of concreet class type
	std::unique_ptr<GameFactory::IInputProcessor> mInputProcessor{};
	std::unique_ptr<GameMainScene> mGameMainScene{};
	const std::string mTexturesDir;
	float mGameSpeed{ 1.0f };
	bool mPause{ false };
};
