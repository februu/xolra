#include <SFML/Graphics.hpp>
#include <map>
#include <iostream>

#include "../include/AssetManager.hpp"

bool AssetManager::addTexture(int id, std::string pathToFile)
{
    sf::Texture texture;
    if (!texture.loadFromFile(pathToFile))
    {
        std::cerr << "Error! Cannot load " << pathToFile << ".\n";
        return false;
    }
    textures.insert(std::make_pair(id, texture));
}
sf::Texture *AssetManager::getPointerToTexture(int id)
{
    return &textures.at(id);
}