#include "Resources/ResourceManager.h"

#include <iostream>
#include <filesystem>

namespace GameFactory {

// TODO: List of supported extensions
ResourceManager::ResourceManager(const std::string& texturesDir)
	: mTexturesDir(texturesDir) {
}

bool ResourceManager::Init() {
	if (!std::filesystem::is_directory(mTexturesDir)) {
		std::cerr << "ResourceManager::Load. Directory " << mTexturesDir << "does not exist!" << std::endl;
		return false;
	}

	int numberOfPngFiles{ 0 };
	int numberOfLoadedPngFiles{ 0 };

	for (const auto & entry : std::filesystem::directory_iterator(mTexturesDir)) {
		const auto& path = entry.path();
		if (entry.is_regular_file() && (path.extension() == ".png" || path.extension() == ".jpg")) {
			++numberOfPngFiles;
			if (LoadTexture(path)) {
				++numberOfLoadedPngFiles;
			}
		}
	}

	if (numberOfPngFiles == 0) {
		std::cerr << "ResourceManager::Load. No PNG files found!" << std::endl;
		return false;
	}

	return numberOfPngFiles == numberOfLoadedPngFiles;
}

void ResourceManager::Deinit() {
	mLoadedTextures.clear();
}

bool ResourceManager::LoadTexture(const std::filesystem::path& path) {
	if (mLoadedTextures.find(path.filename()) != mLoadedTextures.end() ) {
		std::cerr << "ResourceManager::LoadTexture. Texture name " << path.filename() << " already loaded!" << std::endl;
		return false;
	}

	if (!mLoadedTextures[path.filename()].loadFromFile(path.string())) {
		std::cerr << "ResourceManager::LoadTexture. Error loading texture: " << path.filename() << std::endl;
		return false;
	}

	std::cout << "ResourceManager::LoadTexture. Texture " << path.filename() << " was successfully loaded" << std::endl;
	return true;
}

bool ResourceManager::HasTexture(const std::string& textureName) const {
	return mLoadedTextures.find(textureName) != mLoadedTextures.end();
}

const sf::Texture& ResourceManager::GetTexture(const std::string& textureName) const {
	return mLoadedTextures.at(textureName);
}

}