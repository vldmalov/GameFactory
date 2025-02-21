#include "GameScene/GameObjects/GameObjectComponents/InputComponent.h"

#include "Input/IInputProcessor.h"

namespace GameFactory {
InputComponent::InputComponent(GameObjectBase* owner, IInputProcessor& inputProcessor)
	: GameObjectComponent(owner)
	, mInputProcessor(inputProcessor) {
	mInputProcessor.AddInputComponent(this);
}

InputComponent::~InputComponent() {
	mInputProcessor.RemoveInputComponent(this);
}

}
