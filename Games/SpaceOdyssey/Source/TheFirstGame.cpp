#include "TheFirstGame.h"
#include "DebugTools/BenchmarkTimer.h"
#include "GameScene/GameObjects/GameObjectComponents/InputComponent.h"
#include "Input/InputProcessor.h"
#include "Resources/ResourceManager.h"

TheFirstGame::TheFirstGame(const std::string& texturesDir)
	: mResourceManager(nullptr)
	, mRenderManager(nullptr)
	, mInputProcessor(nullptr)
	, mGameMainScene(nullptr)
	, mTexturesDir(texturesDir) {
}

void TheFirstGame::Init(sf::RenderTarget& renderTarget) {
	GameFactory::BenchmarkTimer timer("Application::Init");

	mResourceManager = std::make_unique<GameFactory::ResourceManager>(mTexturesDir);
	mResourceManager->Init();

	mRenderManager = std::make_unique<GameFactory::RenderManager>(renderTarget);
	mRenderManager->Init();

	mInputProcessor = std::make_unique<GameFactory::InputProcessor>();
	mInputProcessor->Init();

	auto renderTargetSize = renderTarget.getSize();
	mGameMainScene = std::make_unique<GameMainScene>(
		*mRenderManager.get(),
		*mInputProcessor.get(),
		*mResourceManager.get());
	mGameMainScene->Init(renderTargetSize);
}

void TheFirstGame::Deinit() {
	mGameMainScene->Deinit();
	mInputProcessor->Deinit();
	mRenderManager->Deinit();
	mResourceManager->Deinit();
}

void TheFirstGame::Update(float deltaTime) {
	if (mPause) {
		return; // TODO: Should scene objects be updated anyway?
	}
	GameFactory::BenchmarkTimer timer("Application::Update");
	const float gameDeltaTime = deltaTime * mGameSpeed;
	mGameMainScene->Update(gameDeltaTime);
}

void TheFirstGame::Render(sf::RenderTarget& renderTarget) {
	mRenderManager->Render();
}

bool TheFirstGame::IsFinished() const {
	return false;
}

bool TheFirstGame::OnKeyPressed(const sf::Event::KeyPressed* eventData) {
	// TODO: Move to Input Processor?
	if (eventData->scancode == sf::Keyboard::Scancode::P ||
		eventData->scancode == sf::Keyboard::Scancode::Pause ||
		eventData->scancode == sf::Keyboard::Scancode::MediaPlayPause ) {
		mPause = !mPause;
		return true;
	}
	if (eventData->scancode == sf::Keyboard::Scancode::NumpadEqual) {
		mGameSpeed = 1.f;
		return true;
	}
	if (eventData->scancode == sf::Keyboard::Scancode::NumpadPlus) {
		mGameSpeed *= 1.1f;
		return true;
	}
	if (eventData->scancode == sf::Keyboard::Scancode::NumpadMinus) {
		mGameSpeed /= 1.1f;
		return true;
	}

	return mInputProcessor->OnKeyPressed(eventData);
}

bool TheFirstGame::OnKeyReleased(const sf::Event::KeyReleased* eventData) {
	return mInputProcessor->OnKeyReleased(eventData);
};


void TheFirstGame::OnMouseMoved(const sf::Vector2i& from, const sf::Vector2i& to) {
	mInputProcessor->OnMouseMoved(from, to);
}

void TheFirstGame::OnMouseButtonPressed(const sf::Vector2i& mousePos) {
	mInputProcessor->OnMouseButtonPressed(mousePos);
}

void TheFirstGame::OnMouseButtonReleased(const sf::Vector2i& mousePos) {
	mInputProcessor->OnMouseButtonReleased(mousePos);
}

