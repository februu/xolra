#include <SFML/Graphics.hpp>

#include "../include/Card.hpp"
#include "../include/AssetManager.hpp"
#include "../include/GameScene.hpp"
#include "../include/CardList.hpp"

void GameScene::initialize()
{
    // add cards to hand
    for (int i = 0; i < 4; i++)
    {
        Card card(am->getPointerToTexture(CARD_ONE), {300.f + i * 300.f, 900.f});
        hand.push_back({i, card});
    }
}

void GameScene::update(float deltaTime)
{
    // update cards
    for (auto &card : hand)
        if (card.card.update(deltaTime, window))
        {
            for (auto &card2 : hand)
                if (card2.zIndex > card.zIndex)
                    card2.zIndex -= 1;
            card.zIndex = hand.size() - 1;
        }
}

void GameScene::draw()
{
    window->clear(sf::Color(75, 75, 75));
    for (int i = 0; i < hand.size(); i++)
        for (auto &card : hand)
            if (card.zIndex == i)
                window->draw(card.card.sprite);

    window->display();
}

GameScene::~GameScene()
{
    // delete animations to prevent memory leaks
    for (auto &card : hand)
        card.card.deleteAnimations();
}