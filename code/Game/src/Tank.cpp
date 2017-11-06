#include "debug.hpp"
#include "Constants.hpp"
#include "Tank.hpp"
#include "ITankController.hpp"
#include "Graphics.hpp"
#include "Bullet.hpp"
#include "ObjectNotifier.hpp"
#include "Smoke.hpp"

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

Tank::Tank(AI::ITankController& tankController,
           ObjectNotifier& newObjectNotifier,
           Graphics& graphics,
           int posX, int posY) :
        AnimatedObject(graphics,
                       "res/playerTank.png",
                       0,
                       0,
                       TANK_HEIGHT,
                       TANK_WIGHT,
                       125),
        _centerX(posX), _centerY(posY),
        _direction(Animation::IdleUp),
        _tankController(tankController),
        _newObjectNotifier(newObjectNotifier)
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
}

void Tank::update(int elapsedTime) {
    _tankController.conditionallyMove(*this);

    _centerX += _dx * elapsedTime;
    _centerY += _dy * elapsedTime;

    _centerX < getWight() / 2 ? _centerX = getWight() / 2 : 0;
    _centerX  > WINDOW_WIGHT - getWight() / 2 ? _centerX = WINDOW_WIGHT - getWight() / 2 : 0;
    _centerY < getHeight() / 2 ? _centerY = getHeight() / 2 : 0;
    _centerY > WINDOW_HEIGHT - getHeight() / 2 ? _centerY = WINDOW_HEIGHT - getHeight() / 2 : 0;

    AnimatedObject::update(elapsedTime);
}

void Tank::draw(Graphics& graphics) {
    AnimatedObject::draw(graphics, _centerX, _centerY);
    _tankController.conditionallyShoot(*this, graphics);
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
    return _direction;
}

std::unique_ptr<Bullet> Tank::createBullet(Graphics& graphics) {
    auto direction = getDirection();
    auto posX = _centerX;
    auto posY = _centerY;

    if (direction == Animation::Left) {
        posX -= TANK_WIGHT / 2 * SCALE_HEIGHT;
    } else if (direction == Animation::Right) {
        posX += TANK_WIGHT / 2 * SCALE_HEIGHT;
    } else if (direction == Animation::Up) {
        posY -= TANK_HEIGHT / 2 * SCALE_HEIGHT;
    } else if (direction == Animation::Down) {
        posY += TANK_HEIGHT / 2 * SCALE_HEIGHT;
    }



    return std::make_unique<Bullet>(graphics, _newObjectNotifier, posX, posY, direction);
}

void Tank::shoot(Graphics& graphics) {
    auto bullet = createBullet(graphics);
    _newObjectNotifier.addObject(std::move(bullet));
}

bool Tank::shouldBeRemove() {
    return false;
}

void Tank::update(int elapsedTime, std::list<std::unique_ptr<Object>>& objects) {
    _tankController.conditionallyMove(*this);

    auto dx = _dx * elapsedTime;
    auto dy = _dy * elapsedTime;

    _centerX += dx;
    _centerY += dy;

    for (auto& obj : objects) {
        SDL_Rect objRect = obj->getRectangle();
        SDL_Rect tankRect = getRectangle();
        if (SDL_HasIntersection(&objRect, &tankRect)) {
            _centerX -= dx;
            _centerY -= dy;
            AnimatedObject::update(elapsedTime);
            return;
        }
    }

    _centerX < getWight() / 2 ? _centerX = getWight() / 2 : 0;
    _centerX > WINDOW_WIGHT - getWight() / 2 ? _centerX = WINDOW_WIGHT - getWight() / 2 : 0;
    _centerY < getHeight() / 2 ? _centerY = getHeight() / 2 : 0;
    _centerY > WINDOW_HEIGHT - getHeight() / 2 ? _centerY = WINDOW_HEIGHT - getHeight() / 2 : 0;


    AnimatedObject::update(elapsedTime);

}

SDL_Rect Tank::getRectangle() {
    return SDL_Rect{static_cast<int>(_centerX - getWight() / 2),
                    static_cast<int>(_centerY - getHeight() / 2),
                    static_cast<int>(getWight()),
                    static_cast<int>(getHeight())};
}


}