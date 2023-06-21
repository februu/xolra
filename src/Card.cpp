#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <time.h>

#include "../include/Card.hpp"
#include "../include/Animation.hpp"

Card *Card::draggedCard = nullptr;

bool Card::duringPropertyAnimation()
{
    return activeAnimations.size() == 0;
}

void Card::updateAnimations(float deltaTime)
{
    // update isDruingAnimation
    std::vector<Animation *>::iterator it = activeAnimations.begin();
    while (it != activeAnimations.end())
    {
        if ((*it)->update(deltaTime))
        {
            delete (*it);
            it = activeAnimations.erase(it);
        }
        else
            ++it;
    }
}

void Card::update(float deltaTime, sf::RenderWindow *window)
{
    // Updates animations
    updateAnimations(deltaTime);

    if (hasBeenPlayed)
        return;

    bool oldIsHovered = isHovered;
    bool oldIsButtonPressed = isButtonPressed;

    isButtonPressed = sf::Mouse::isButtonPressed(sf::Mouse::Left);

    // Check if is being hovered over
    isHovered = sprite.getGlobalBounds().contains(sf::Mouse::getPosition(*window).x, sf::Mouse::getPosition(*window).y);

    // Check if it started to be hovered?
    bool startedToBeHovered = !oldIsHovered && isHovered && draggedCard == nullptr;

    // Check if it ended to be hovered
    bool endedToBeHovered = oldIsHovered && !isHovered && draggedCard == nullptr;

    // Check if it started to be dragged?
    bool startedToBeDragged = !isDragged && isButtonPressed && !oldIsButtonPressed && isHovered && draggedCard == nullptr;

    // Check if it ended to be dragged
    bool endedToBeDragged = isDragged && (!isButtonPressed || !isHovered);

    // Check if is being dragged
    isDragged = isHovered && isButtonPressed && draggedCard == this;

    // if (isHovered)
    //     std::cout << isHovered << " " << isDragged << " " << startedToBeDragged << " " << endedToBeDragged << "\n";

    //  Drag card over

    if (!duringPropertyAnimation())
        return;

    if (startedToBeDragged)
    {
        dragOffset.x = sf::Mouse::getPosition(*window).x - sprite.getPosition().x;
        dragOffset.y = sf::Mouse::getPosition(*window).y - sprite.getPosition().y;
        draggedCard = this;
    }
    else if (isDragged)
    {
        sf::Vector2f newPosition = sf::Vector2f(sf::Mouse::getPosition(*window));
        newPosition.x -= dragOffset.x;
        newPosition.y -= dragOffset.y;
        sprite.setPosition(newPosition);
    }
    else if (endedToBeDragged)
    {
        draggedCard = nullptr;
        if (sf::Mouse::getPosition(*window).y < window->getSize().y / 2)
        {
            hasBeenPlayed = true;
            float random = (rand() % 21) - 10;
            std::cout << random << "\n";
            RotationAnimation *rotAnimation = new RotationAnimation(0.2f, &sprite, random);
            activeAnimations.push_back(rotAnimation);
            PositionAnimation *posAnimation = new PositionAnimation(0.2f, &sprite, sf::Vector2f(window->getSize().x / 2, window->getSize().y / 3));
            activeAnimations.push_back(posAnimation);
            ScaleAnimation *scaleAnimation = new ScaleAnimation(0.2f, &sprite, {0.6f, 0.6f});
            activeAnimations.push_back(scaleAnimation);
        }
        else if (sprite.getPosition() != initialPosition && sprite.getPosition() != sf::Vector2f(initialPosition.x, initialPosition.y - hoverOffset))
        {
            PositionAnimation *animation = new PositionAnimation(0.1f, &sprite, initialPosition);
            activeAnimations.push_back(animation);
        }
    }
    else if (startedToBeHovered)
    {
        sprite.setPosition({initialPosition.x, initialPosition.y - hoverOffset});
    }
    else if (endedToBeHovered)
    {
        sprite.setPosition(initialPosition);
    }
}
