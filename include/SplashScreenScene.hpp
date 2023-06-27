#pragma once

#include <SFML/Graphics.hpp>
#include "SceneManager.hpp"
#include "AssetManager.hpp"

class SplashScreenScene : public Scene
{
private:
    float elapsedTime = 0.f;
    float opacity = 0.f;
    sf::Text text;

public:
    SplashScreenScene(sf::RenderWindow *window, AssetManager *am) : Scene(window, am) {}
    ~SplashScreenScene();
    void initialize() override;
    void update(float deltaTime) override;
    void draw() override;
};