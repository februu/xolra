#pragma once
#include <SFML/Graphics.hpp>

// ********************************************** //

class Animation
{
protected:
    // duration in seconds
    float duration;

    // time elapsed from animation start
    float elapsedTime = 0.f;

    // object to animate
    sf::Sprite *sprite;
    Animation(const float duration, sf::Sprite *sprite) : duration(duration), sprite(sprite) {}

public:
    virtual bool update(float deltaTime) { return false; };
};

// ********************************************** //

class ScaleAnimation : public Animation
{
private:
    sf::Vector2f startScale;
    sf::Vector2f endScale;

public:
    ScaleAnimation(const float duration, sf::Sprite *sprite, const sf::Vector2f endScale) : Animation(duration, sprite), endScale(endScale), startScale(sprite->getScale()) {}
    bool update(float deltaTime) override;
};

// ********************************************** //

class PositionAnimation : public Animation
{
private:
    sf::Vector2f startPosition;
    sf::Vector2f endPosition;

public:
    PositionAnimation(const float duration, sf::Sprite *sprite, const sf::Vector2f endPosition) : Animation(duration, sprite), endPosition(endPosition), startPosition(sprite->getPosition()) {}
    bool update(float deltaTime) override;
};

// ********************************************** //

class RotationAnimation : public Animation
{
private:
    float startAngle, endAngle;

public:
    RotationAnimation(const float duration, sf::Sprite *sprite, const float endAngle) : Animation(duration, sprite), endAngle(endAngle), startAngle(sprite->getRotation()) {}
    bool update(float deltaTime) override;
};

// ********************************************** //

class FrameAnimation : public Animation
{
private:
    // index of first frame in animation, index of last frame in animation,
    int startFrame, lastFrame;
    int currentFrame = 0;

public:
    FrameAnimation(const float duration, sf::Sprite *sprite, const int startFrame, const int lastFrame) : Animation(duration, sprite), startFrame(startFrame), lastFrame(lastFrame) {}
    bool update(float deltaTime) override;
};