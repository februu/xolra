#include <SFML/Graphics.hpp>

#include "../include/SceneManager.hpp"

void SceneManager::changeScene(int id)
{

    currentScene.deactivate();
    // TODO: Set new current scene.

    currentScene.initialize();
}

void SceneManager::updateCurrentScene(float deltaTime)
{
    currentScene.update(deltaTime);
}

void SceneManager::drawCurrentScene(sf::RenderWindow *window)
{
    currentScene.draw(window);
}