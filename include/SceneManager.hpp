#pragma once

#include <SFML/Graphics.hpp>
#include "AssetManager.hpp"

enum Scenes
{
    SPLASHSCREEN,
    GAME_MENU,
    GAME_OPTIONS,
    GAME_GAME
};

class SceneManager;

class Scene
{
protected:
    sf::RenderWindow *window;
    AssetManager *am;
    SceneManager *sm;

public:
    Scene(sf::RenderWindow *window, AssetManager *am, SceneManager *sm)
    {
        this->window = window;
        this->am = am;
        this->sm = sm;
    }
    virtual void initialize() {}
    virtual void update(float deltaTime) {}
    virtual void draw() {}
    virtual ~Scene() {}
};

class SceneManager
{
private:
    Scene *currentScene = nullptr;

public:
    void changeScene(Scene *scene);
    void updateCurrentScene(float deltaTime);
    void drawCurrentScene();
};