#pragma once
#include <vector>

#include <SFML/Graphics.hpp>
#include "SceneManager.hpp"
#include "AssetManager.hpp"
#include "Card.hpp"

struct cardPair
{
    int zIndex;
    Card card;
};

class GameScene : public Scene
{
private:
    std::vector<cardPair> hand; // goofy ass vector of pairs {Card card, int z-index}.

public:
    GameScene(sf::RenderWindow *window, AssetManager *am, SceneManager *sm) : Scene(window, am, sm) {}
    ~GameScene();
    void initialize() override;
    void update(float deltaTime) override;
    void draw() override;
};