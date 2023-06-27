#include <SFML/Graphics.hpp>
#include <iostream>

#include "../include/SplashScreenScene.hpp"
#include "../include/AssetManager.hpp"

void SplashScreenScene::initialize()
{
    text = sf::Text("febru presents", *am->getPointerToFont(0), 30);
    sf::FloatRect textRect = text.getLocalBounds();
    text.setOrigin(textRect.left + textRect.width / 2.0f,
                   textRect.top + textRect.height / 2.0f);
    text.setFillColor(sf::Color(255, 255, 255, 0));
    text.setPosition(sf::Vector2f(window->getSize().x / 2.0f, window->getSize().y / 2.0f));
}

void SplashScreenScene::update(float deltaTime)
{
    elapsedTime += deltaTime;

    if (elapsedTime > 7.f && elapsedTime < 8.f)
        text.setFillColor(sf::Color(255, 255, 255, 255 - int(255 * (elapsedTime - 7.f))));

    else if (elapsedTime > 5.f && elapsedTime < 6.f)
        text.setFillColor(sf::Color(255, 255, 255, int(255 * (elapsedTime - 5.f))));
    else if (elapsedTime > 4.f && text.getCharacterSize() != 60)
    {
        text.setString("// Xolra: The Mountain of Secrets \\\\");
        text.setCharacterSize(60);
        sf::FloatRect textRect = text.getLocalBounds();
        text.setOrigin(textRect.left + textRect.width / 2.0f,
                       textRect.top + textRect.height / 2.0f);
    }

    else if (elapsedTime > 3.f && elapsedTime < 4.f)
        text.setFillColor(sf::Color(255, 255, 255, 255 - int(255 * (elapsedTime - 3.f))));

    else if (elapsedTime > 1.f && elapsedTime < 2.f)
        text.setFillColor(sf::Color(255, 255, 255, int(255 * (elapsedTime - 1.f))));
}

void SplashScreenScene::draw()
{
    window->clear(sf::Color(15, 15, 15));
    window->draw(text);
    window->display();
}

SplashScreenScene::~SplashScreenScene()
{
}