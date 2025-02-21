#pragma once

#include "GameScene/GameObjects/GameObjectComponents/InputComponent.h"
#include "IInputProcessor.h"

#include <vector>

namespace GameFactory {
class InputProcessor final : public IInputProcessor {
public:
	InputProcessor() = default;
	~InputProcessor() = default;

	void Init() override;
	void Deinit() override;

	bool OnKeyPressed(const sf::Event::KeyPressed* eventData) override;
	bool OnKeyReleased(const sf::Event::KeyReleased* eventData) override;
	void OnMouseMoved(const sf::Vector2i& from, const sf::Vector2i& to) override;
	void OnMouseButtonPressed(const sf::Vector2i& mousePos) override;
	void OnMouseButtonReleased(const sf::Vector2i& mousePos) override;

	void AddInputComponent(InputComponent* inputComponent) override;
	void RemoveInputComponent(InputComponent* inputComponent) override;

private:
	std::vector<InputComponent*> mInputComponents;
};
}