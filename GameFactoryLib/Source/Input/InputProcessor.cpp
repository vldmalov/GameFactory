#include "Input/InputProcessor.h"

namespace GameFactory {

void InputProcessor::Init() {
}

void InputProcessor::Deinit() {
	mInputComponents.clear();
}

bool InputProcessor::OnKeyPressed(const sf::Event::KeyPressed* eventData) {
	for (auto& component : mInputComponents) {
		const bool wasProcessed = component->OnKeyPressed(eventData);
		if (wasProcessed) {
			return true;
		}
	}
	return false;
}

bool InputProcessor::OnKeyReleased(const sf::Event::KeyReleased* eventData) {
	for (auto& component : mInputComponents) {
		const bool wasProcessed = component->OnKeyReleased(eventData);
		if (wasProcessed) {
			return true;
		}
	}
	return false;
}

void InputProcessor::OnMouseMoved(const sf::Vector2i& from, const sf::Vector2i& to) {
	for (auto& component : mInputComponents) {
		component->OnMouseMoved(from, to);
	}
}

void InputProcessor::OnMouseButtonPressed(const sf::Vector2i& mousePos) {
	for (auto& component : mInputComponents) {
		component->OnMouseButtonPressed(mousePos);
	}
}

void InputProcessor::OnMouseButtonReleased(const sf::Vector2i& mousePos) {
	for (auto& component : mInputComponents) {
		component->OnMouseButtonReleased(mousePos);
	}
}

void InputProcessor::AddInputComponent(InputComponent* sprite) {
	mInputComponents.emplace_back(sprite);
}

void InputProcessor::RemoveInputComponent(InputComponent* sprite) {
	const auto& componentIt = std::find(mInputComponents.begin(), mInputComponents.end(), sprite);
	if (componentIt != mInputComponents.end()) {
		mInputComponents.erase(componentIt);
	}
}


}