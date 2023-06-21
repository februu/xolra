#include <SFML/Graphics.hpp>
#include <iostream>

#include "../include/Animation.hpp"

bool ScaleAnimation::update(float deltaTime)
{
    elapsedTime += deltaTime;
    float component = elapsedTime / duration;

    sf::Vector2f scale = startScale;
    scale.x += (endScale.x - startScale.x) * component;
    scale.y += (endScale.y - startScale.y) * component;
    sprite->setScale(scale);

    return elapsedTime > duration;
}

bool PositionAnimation::update(float deltaTime)
{
    elapsedTime += deltaTime;
    float component = elapsedTime / duration;

    sf::Vector2f position = startPosition;
    position.x += (endPosition.x - startPosition.x) * component;
    position.y += (endPosition.y - startPosition.y) * component;
    sprite->setPosition(position);

    return elapsedTime > duration;
}

bool RotationAnimation::update(float deltaTime)
{
    elapsedTime += deltaTime;
    float component = elapsedTime / duration;

    float rotation = startAngle + ((endAngle - startAngle) * component);
    // std::cout << endAngle << " " << startAngle << " " << rotation << "\n";
    sprite->setRotation(rotation);

    return elapsedTime > duration;
}

bool FrameAnimation::update(float deltaTime)
{

    return elapsedTime > duration;
}