#include <debug.hpp>
#include <Constants.hpp>
#include "Tank.hpp"

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

Tank::Tank(AI::ITankController& tankController, Graphics& graphics, int posX, int posY) :
        AnimatedObject(graphics,
                       "res/playerTank.png",
                       0,
                       0,
                       TANK_HEIGHT,
                       TANK_WIGHT,
                       125),
        _x(posX), _y(posY), _direction(Animation::IdleUp), _tankController(tankController)
{
    setupAnimations();
}

void Tank::setupAnimations() {
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

void Tank::update(int elapsedTime) {
    _tankController.move(*this);
    
    _x += _dx * elapsedTime;
    _y += _dy * elapsedTime;

    _x < getWight() / 2 ? _x = getWight() / 2 : 0;
    _x  > WINDOW_WIGHT - getWight() / 2 ? _x = WINDOW_WIGHT - getWight() / 2 : 0;
    _y < getHeight() / 2 ? _y = getHeight() / 2 : 0;
    _y > WINDOW_HEIGHT - getHeight() / 2 ? _y = WINDOW_HEIGHT - getHeight() / 2 : 0;

    AnimatedObject::update(elapsedTime);
}

void Tank::draw(Graphics& graphics) {
    AnimatedObject::draw(graphics, _x, _y);
}

void Tank::moveLeft() {
    _dx = - SPEED;
    _dy = 0;
    _direction = Animation::Left;
    playAnimation(_direction);
}

void Tank::moveRight() {
    _dx = SPEED;
    _dy = 0;
    _direction = Animation::Right;
    playAnimation(_direction);
}

void Tank::moveUp() {
    _dx = 0;
    _dy = - SPEED;
    _direction = Animation::Up;
    playAnimation(_direction);
}

void Tank::moveDown() {
    _dx = 0;
    _dy = SPEED;
    _direction = Animation::Down;
    playAnimation(_direction);
}

void Tank::stopMoving() {
    _dx = 0;
    _dy = 0;
    _direction = getIdle(_direction);
    playAnimation(_direction);
}

Animation Tank::getDirection() {
    switch (_direction)
    {
        case Animation::Left:
        case Animation::IdleLeft:
            return Animation::Left;
        case Animation::Right:
        case Animation::IdleRight:
            return Animation::Right;
        case Animation::Up:
        case Animation::IdleUp:
            return Animation::Up;
        case Animation::Down:
        case Animation::IdleDown:
            return Animation::Down;
    }
}

Bullet Tank::createBullet(Graphics& graphics) {
    auto direction = getDirection();
    auto posX = _x;
    auto posY = _y;

    if (direction == Animation::Left) {
        posX -= TANK_WIGHT / 2 * SCALE_HEIGHT;
    } else if (direction == Animation::Right) {
        posX += TANK_WIGHT / 2 * SCALE_HEIGHT;
    } else if (direction == Animation::Up) {
        posY -= TANK_HEIGHT / 2 * SCALE_HEIGHT;
    } else if (direction == Animation::Down) {
        posY += TANK_HEIGHT / 2 * SCALE_HEIGHT;
    }



    return Bullet(graphics, posX, posY, direction);
}


}