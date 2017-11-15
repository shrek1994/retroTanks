#include "debug.hpp"
#include "Bullet.hpp"
#include "Constants.hpp"
#include "Graphics.hpp"
#include "Smoke.hpp"
#include "ObjectOwner.hpp"

namespace Game {


Bullet::Bullet(Graphics& graphics,
               ObjectOwner& objectOwner,
               int centerPosX, int centerPosY,
               Animation direction)
        : Object(graphics,
                 "res/bulletGreen.png",
                 0, 0,
                 BULLET_WIGHT_WHEN_IS_UP, BULLET_HEIGHT_WHEN_IS_UP),
          direction(direction),
          centerX(centerPosX), centerY(centerPosY),
          graphics(graphics),
          objectOwner(objectOwner)
{
    switch (direction)
    {
        case Animation::Up:
            _dy = - 2 * SPEED;
            sourceRect.x = 0;
            sourceRect.y = 0;
            sourceRect.w = BULLET_WIGHT_WHEN_IS_UP;
            sourceRect.h = BULLET_HEIGHT_WHEN_IS_UP;
            break;
        case Animation::Right:
            _dx = 2 * SPEED;
            sourceRect.x = 0;
            sourceRect.y = BULLET_HEIGHT_WHEN_IS_UP;
            sourceRect.w = BULLET_WIGHT_WHEN_IS_LEFT;
            sourceRect.h = BULLET_HEIGHT_WHEN_IS_LEFT;
            break;
        case Animation::Down:
            _dy = 2 * SPEED;
            sourceRect.x = 0;
            sourceRect.y = BULLET_HEIGHT_WHEN_IS_UP + BULLET_HEIGHT_WHEN_IS_LEFT;
            sourceRect.w = BULLET_WIGHT_WHEN_IS_UP;
            sourceRect.h = BULLET_HEIGHT_WHEN_IS_UP;
            break;
        case Animation::Left:
            _dx = - 2 * SPEED;
            sourceRect.x = 0;
            sourceRect.y = 2 * BULLET_HEIGHT_WHEN_IS_UP + BULLET_HEIGHT_WHEN_IS_LEFT;
            sourceRect.w = BULLET_WIGHT_WHEN_IS_LEFT;
            sourceRect.h = BULLET_HEIGHT_WHEN_IS_LEFT;
            break;
        default:
            ERROR << "Wrong direction: " << direction << "\n";
    }
    objectOwner.addObject(std::move(createSmoke(graphics)));
}

void Bullet::draw(Graphics& graphics) {
    Object::draw(graphics, centerX, centerY);
}

void Bullet::update(int elapsedTime) {
    centerX += _dx * elapsedTime;
    centerY += _dy * elapsedTime;

    centerX < 0 ? centerX = 0 : 0;
    centerX > WINDOW_WIGHT ? centerX = WINDOW_WIGHT : 0;
    centerY < 0 ? centerY = 0 : 0;
    centerY > WINDOW_HEIGHT ? centerY = WINDOW_HEIGHT : 0;
}

std::unique_ptr<Smoke> Bullet::createSmoke(Graphics& graphics) {
    return std::make_unique<Smoke>(graphics, centerX, centerY);
}


Bullet::~Bullet() {
    objectOwner.addObject(std::move(createSmoke(graphics)));
}

SDL_Rect Bullet::getRectangle() const {
    return SDL_Rect{static_cast<int>(centerX - getWight() / 2),
                    static_cast<int>(centerY - getHeight() / 2),
                    static_cast<int>(getWight()),
                    static_cast<int>(getHeight())};
}

bool Bullet::shouldBeRemove() const {
    return isCollisionWithWall() || checkCollisionWithTanks();
}

bool Bullet::isCollisionWithWall() const {
    return centerX == 0 || centerX == WINDOW_WIGHT || centerY == 0 || centerY == WINDOW_HEIGHT;
}

bool Bullet::checkCollisionWithTanks() const {
    auto bulletRect = getRectangle();
    for (const auto& tank : objectOwner.getTanks()) {
        auto tankRect = tank->getRectangle();
        if (SDL_HasIntersection(&bulletRect, &tankRect)) {
            tank->setKilled();
            return true;
        }
    }

    return false;
}

}
