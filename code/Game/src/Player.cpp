#include <debug.hpp>
#include <Constants.hpp>
#include "Player.hpp"

namespace Game {

namespace {

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
                       TANK_HEIGHT,
                       TANK_WIGHT,
                       125),
        _x(posX), _y(posY), _direction(Animation::IdleUp)
{
    setupAnimations();
}

void Player::setupAnimations() {
    addAnimation(1, 0, 0, Animation::IdleDown, TANK_WIGHT, TANK_HEIGHT, SDL_Point{0, TANK_HEIGHT});
    addAnimation(1, 0, TANK_HEIGHT, Animation::IdleLeft, TANK_WIGHT, TANK_HEIGHT, SDL_Point{0, TANK_HEIGHT});
    addAnimation(1, 0, 2*TANK_HEIGHT, Animation::IdleUp, TANK_WIGHT, TANK_HEIGHT, SDL_Point{0, TANK_HEIGHT});
    addAnimation(1, 0, 3*TANK_HEIGHT, Animation::IdleRight, TANK_WIGHT, TANK_HEIGHT, SDL_Point{0, TANK_HEIGHT});

    addAnimation(2, 0, 0, Animation::Down, TANK_WIGHT, TANK_HEIGHT, SDL_Point{0, TANK_HEIGHT});
    addAnimation(2, 0, TANK_HEIGHT, Animation::Left, TANK_WIGHT, TANK_HEIGHT, SDL_Point{0, TANK_HEIGHT});
    addAnimation(2, 0, 2*TANK_HEIGHT, Animation::Up, TANK_WIGHT, TANK_HEIGHT, SDL_Point{0, TANK_HEIGHT});
    addAnimation(2, 0, 3*TANK_HEIGHT, Animation::Right, TANK_WIGHT, TANK_HEIGHT, SDL_Point{0, TANK_HEIGHT});

    DEBUG << "Loading player animation - DONE!\n";
}

void Player::update(int elapsedTime) {
    _x += _dx * elapsedTime;
    _y += _dy * elapsedTime;

    _x < 0 ? _x = 0 : 0;
    _y < 0 ? _y = 0 : 0;

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