#include <SFML/Graphics.hpp>
#include <iostream>

using std::cout;

#include "../include/SceneManager.hpp"

void SceneManager::changeScene(Scene *scene)
{

    if (currentScene != nullptr)
        delete currentScene;

    currentScene = scene;

    if (scene == nullptr)
        return;

    currentScene->initialize();
}

void SceneManager::updateCurrentScene(float deltaTime)
{
    currentScene->update(deltaTime);
}

void SceneManager::drawCurrentScene()
{
    currentScene->draw();
}