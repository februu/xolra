#pragma once

#include <SFML/Graphics.hpp>

class Scene
{
public:
    void initialize() {}
    void update(float deltaTime) {}
    void draw(sf::RenderWindow *window) {}
    void deactivate() {}
};

class SceneManager
{
private:
    Scene currentScene;

public:
    void changeScene(int id);
    void updateCurrentScene(float deltaTime);
    void drawCurrentScene(sf::RenderWindow *window);
};