#include "TextureManager.h"

std::shared_ptr<sf::Texture> TextureManager::acquire(const std::string& filename)
{
	const auto i = texturePtrs.find(filename);

	// If the texture already exists, return it.
	if (i != texturePtrs.end())
		return i->second;

	// Otherwise, load texture and add it to the map.
	auto pTex = std::make_shared<sf::Texture>();
	pTex->loadFromFile(filename);
	texturePtrs.insert({ filename, pTex });
	return pTex;
}

void TextureManager::clean()
{
	for (auto i = texturePtrs.begin(); i != texturePtrs.end();)
		if (i->second.unique())
			i = texturePtrs.erase(i);
		else
			i++;
}

std::unordered_map<std::string, std::shared_ptr<sf::Texture>> TextureManager::texturePtrs;