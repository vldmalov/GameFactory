#pragma once

#include "IResourceManager.h"

// TODO: Read resources list from config file

namespace GameFactory {
class ResourceManager final : public IResourceManager {
public:
	explicit ResourceManager(const std::string& texturesDir);
	~ResourceManager() = default;

	bool Init() override;
	void Deinit() override;

	bool HasTexture(const std::string& textureName) const override;
	const sf::Texture& GetTexture(const std::string& textureName) const override;

private:
	bool LoadTexture(const std::filesystem::path& path);

	std::string mTexturesDir;
	std::unordered_map<std::string, sf::Texture> mLoadedTextures;

};
}