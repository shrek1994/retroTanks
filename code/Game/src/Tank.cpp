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

Tank::Tank(std::unique_ptr<AI::ITankController>&& tankController,
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
        centerX(posX), centerY(posY),
        direction(Animation::IdleUp),
        tankController(std::move(tankController)),
        newObjectNotifier(newObjectNotifier)
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
    tankController->conditionallyMove(*this);

    centerX += _dx * elapsedTime;
    centerY += _dy * elapsedTime;

    centerX < getWight() / 2 ? centerX = getWight() / 2 : 0;
    centerX  > WINDOW_WIGHT - getWight() / 2 ? centerX = WINDOW_WIGHT - getWight() / 2 : 0;
    centerY < getHeight() / 2 ? centerY = getHeight() / 2 : 0;
    centerY > WINDOW_HEIGHT - getHeight() / 2 ? centerY = WINDOW_HEIGHT - getHeight() / 2 : 0;

    AnimatedObject::update(elapsedTime);
}

void Tank::draw(Graphics& graphics) {
    AnimatedObject::draw(graphics, centerX, centerY);
    tankController->conditionallyShoot(*this, graphics);
}

void Tank::moveLeft() {
    _dx = - SPEED;
    _dy = 0;
    direction = Animation::Left;
    playAnimation(direction);
}

void Tank::moveRight() {
    _dx = SPEED;
    _dy = 0;
    direction = Animation::Right;
    playAnimation(direction);
}

void Tank::moveUp() {
    _dx = 0;
    _dy = - SPEED;
    direction = Animation::Up;
    playAnimation(direction);
}

void Tank::moveDown() {
    _dx = 0;
    _dy = SPEED;
    direction = Animation::Down;
    playAnimation(direction);
}

void Tank::stopMoving() {
    _dx = 0;
    _dy = 0;
    direction = getIdle(direction);
    playAnimation(direction);
}

Animation Tank::getDirection() {
    switch (direction)
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
    return direction;
}

std::unique_ptr<Bullet> Tank::createBullet(Graphics& graphics) {
    auto direction = getDirection();
    auto posX = centerX;
    auto posY = centerY;

    if (direction == Animation::Left) {
        posX -= TANK_WIGHT / 2 * SCALE_HEIGHT;
    } else if (direction == Animation::Right) {
        posX += TANK_WIGHT / 2 * SCALE_HEIGHT;
    } else if (direction == Animation::Up) {
        posY -= TANK_HEIGHT / 2 * SCALE_HEIGHT;
    } else if (direction == Animation::Down) {
        posY += TANK_HEIGHT / 2 * SCALE_HEIGHT;
    }



    return std::make_unique<Bullet>(graphics, newObjectNotifier, posX, posY, direction);
}

void Tank::shoot(Graphics& graphics) {
    auto bullet = createBullet(graphics);
    newObjectNotifier.addObject(std::move(bullet));
}

bool Tank::shouldBeRemove() const {
    return false;
}

void Tank::update(int elapsedTime, std::list<std::unique_ptr<Object>>& objects) {
    tankController->conditionallyMove(*this);

    auto dx = _dx * elapsedTime;
    auto dy = _dy * elapsedTime;

    centerX += dx;
    centerY += dy;

    for (auto& obj : objects) {
        SDL_Rect objRect = obj->getRectangle();
        SDL_Rect tankRect = getRectangle();
        if (SDL_HasIntersection(&objRect, &tankRect)) {
            centerX -= dx;
            centerY -= dy;
            AnimatedObject::update(elapsedTime);
            return;
        }
    }

    centerX < getWight() / 2 ? centerX = getWight() / 2 : 0;
    centerX > WINDOW_WIGHT - getWight() / 2 ? centerX = WINDOW_WIGHT - getWight() / 2 : 0;
    centerY < getHeight() / 2 ? centerY = getHeight() / 2 : 0;
    centerY > WINDOW_HEIGHT - getHeight() / 2 ? centerY = WINDOW_HEIGHT - getHeight() / 2 : 0;


    AnimatedObject::update(elapsedTime);

}

SDL_Rect Tank::getRectangle() const {
    return SDL_Rect{static_cast<int>(centerX - getWight() / 2),
                    static_cast<int>(centerY - getHeight() / 2),
                    static_cast<int>(getWight()),
                    static_cast<int>(getHeight())};
}

double Tank::getXPosition() const { return centerX; }

double Tank::getYPosition() const { return centerY; }

}