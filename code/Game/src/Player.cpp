#include <debug.hpp>
#include "Player.hpp"

namespace Game {

namespace {
constexpr double SPEED = 0.3;

Animation getIdle(Animation animation) {
    switch (animation) {
        case Animation::Left:
            return Animation::IdleLeft;
        case Animation::Right:
            return Animation::IdleRight;
        case Animation::Up:
            return Animation::IdleUp;
        case Animation::Down:
            return Animation::IdleDown;
        default:
            return animation;
    }
}

}

Player::Player(Graphics& graphics, int posX, int posY) :
        AnimatedObject(graphics,
                       "res/playerTank.png",
                       0,
                       0,
                       85,
                       85,
                       posX,
                       posY,
                       125),
        _x(posX), _y(posY)
{
    setupAnimations();
}

void Player::setupAnimations() {
    addAnimation(1, 0, 0, Animation::IdleDown, 85, 85, Offset{0, 85});
    addAnimation(1, 0, 85, Animation::IdleLeft, 85, 85, Offset{0, 85});
    addAnimation(1, 0, 170, Animation::IdleUp, 85, 85, Offset{0, 85});
    addAnimation(1, 0, 255, Animation::IdleRight, 85, 85, Offset{0, 85});

    addAnimation(2, 0, 0, Animation::Down, 85, 85, Offset{0, 85});
    addAnimation(2, 0, 85, Animation::Left, 85, 85, Offset{0, 85});
    addAnimation(2, 0, 170, Animation::Up, 85, 85, Offset{0, 85});
    addAnimation(2, 0, 255, Animation::Right, 85, 85, Offset{0, 85});

    DEBUG << "loading player animation - DONE!\n";
}

void Player::update(int elapsedTime) {
    _x += _dx * elapsedTime;
    _y += _dy * elapsedTime;

    AnimatedObject::update(elapsedTime);
}

void Player::draw(Graphics& graphics) {
    AnimatedObject::draw(graphics, _x, _y);
}

void Player::moveLeft() {
    _dx = - SPEED;
    _dy = 0;
    _direction = Animation::Left;
    playAnimation(_direction);
}

void Player::moveRight() {
    _dx = SPEED;
    _dy = 0;
    _direction = Animation::Right;
    playAnimation(_direction);
}

void Player::moveUp() {
    _dx = 0;
    _dy = - SPEED;
    _direction = Animation::Up;
    playAnimation(_direction);
}

void Player::moveDown() {
    _dx = 0;
    _dy = SPEED;
    _direction = Animation::Down;
    playAnimation(_direction);
}

void Player::stopMoving() {
    _dx = 0;
    _dy = 0;
    _direction = getIdle(_direction);
    playAnimation(_direction);
}



}