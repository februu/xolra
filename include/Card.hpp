#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

#include "Animation.hpp"

class Card
{
private:
    // Drag Logic
    const float hoverOffset = 200.f;
    bool isHovered = false;
    bool isDragged = false;
    bool isButtonPressed = false;
    sf::Vector2f dragOffset;
    sf::Vector2f initialPosition;
    bool hasBeenPlayed = false;

    // Animations
    // bool isDuringAnimation[4]; // [scale, position, rotation, frames]
    std::vector<Animation *> activeAnimations;
    bool duringPropertyAnimation();
    void updateAnimations(float deltaTime);

public:
    static Card *draggedCard;
    Card(sf::Texture *texture, sf::Vector2f initialPosition)
    {

        sprite.setTexture(*texture);
        sprite.setPosition(initialPosition);
        sprite.setOrigin({sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2});
        sprite.setScale({0.5f, 0.5f}); // FIXME
        this->initialPosition = initialPosition;
    }

    sf::Sprite sprite;
    std::vector<Animation *> getAnimations() { return activeAnimations; }

    void update(float deltaTime, sf::RenderWindow *window);
};