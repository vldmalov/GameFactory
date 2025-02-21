#pragma once

#include <SFML/Graphics/Texture.hpp>
#include <string>

namespace GameFactory {

class IResourceManager {
public:
	virtual ~IResourceManager() = default;

	virtual bool Init() = 0;
	virtual void Deinit() = 0;

	virtual bool HasTexture(const std::string& textureName) const = 0;
	virtual const sf::Texture& GetTexture(const std::string& textureName) const = 0;
};

}