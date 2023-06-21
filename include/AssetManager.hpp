#pragma once
#include <SFML/Graphics.hpp>
#include <map>

class AssetManager
{
public:
    std::map<int, sf::Texture> textures;
    bool addTexture(int id, std::string pathToFile);
    sf::Texture *getPointerToTexture(int id);
};
