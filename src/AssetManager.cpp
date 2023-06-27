#include <SFML/Graphics.hpp>
#include <map>
#include <iostream>

#include "../include/AssetManager.hpp"
#include "../include/CardList.hpp"

void AssetManager::loadTextures()
{
    // Load card textures!
    addTexture(CARD_ONE, "assets/card.png");

    // Load fonts
    addFont(0, "assets/IGOTMARKERS.ttf");
}

bool AssetManager::addTexture(int id, std::string pathToFile)
{
    sf::Texture texture;
    if (!texture.loadFromFile(pathToFile))
    {
        std::cerr << "Error! Cannot load " << pathToFile << ".\n";
        return false;
    }
    texture.setSmooth(true);
    textures.insert(std::make_pair(id, texture));
}

bool AssetManager::addFont(int id, std::string pathToFile)
{
    sf::Font font;
    if (!font.loadFromFile(pathToFile))
    {
        std::cerr << "Error! Cannot load " << pathToFile << ".\n";
        return false;
    }
    fonts.insert(std::make_pair(id, font));
}

sf::Texture *AssetManager::getPointerToTexture(int id)
{
    return &textures.at(id);
}

sf::Font *AssetManager::getPointerToFont(int id)
{
    return &fonts.at(id);
}