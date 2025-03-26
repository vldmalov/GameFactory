#pragma once

namespace sf {
class RenderTarget;
}

namespace GameFactory {

class IDrawable {
public:
	virtual ~IDrawable() = default;

	virtual void Render(sf::RenderTarget& renderTarget) = 0;
};

}