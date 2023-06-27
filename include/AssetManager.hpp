#pragma once
#include <SFML/Graphics.hpp>
#include <map>

class AssetManager
{
private:
    std::map<int, sf::Texture> textures;
    std::map<int, sf::Font> fonts;

public:
    // Public maps

    // Loads all the textures
    void loadTextures();

    // Adds assets to maps
    bool addTexture(int id, std::string pathToFile);
    bool addFont(int id, std::string pathToFile);

    // Get assets from maps
    sf::Texture *getPointerToTexture(int id);
    sf::Font *getPointerToFont(int id);
};
