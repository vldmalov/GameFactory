#pragma once

#include <SFML/Window/Window.hpp>

namespace GameFactory {

struct Mouse {
	Mouse(sf::RenderWindow& window)
		: mRenderWindow(window) {
	}

	bool IsButtonDown(sf::Mouse::Button button = sf::Mouse::Button::Left) const {
		return sf::Mouse::isButtonPressed(static_cast<sf::Mouse::Button>(button));
	}

	sf::Vector2f GetPosition() const {
		sf::Vector2i mousePosition = sf::Mouse::getPosition(mRenderWindow);
		return mRenderWindow.mapPixelToCoords(mousePosition);
	}

private:
	const sf::RenderWindow& mRenderWindow;
};
}