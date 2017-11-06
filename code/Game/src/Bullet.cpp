#include "debug.hpp"
#include "Bullet.hpp"
#include "Constants.hpp"
#include "Graphics.hpp"
#include "Smoke.hpp"

namespace Game {
namespace {
constexpr int BULLET_WIGHT_WHEN_IS_UP = 20;
constexpr int BULLET_HEIGHT_WHEN_IS_UP = 34;
}


Bullet::Bullet(Graphics& graphics,
               int centerPosX, int centerPosY,
               Animation direction)
        : Object(graphics,
                 "res/bulletGreen.png",
                 0, 0,
                 BULLET_WIGHT_WHEN_IS_UP, BULLET_HEIGHT_WHEN_IS_UP),
          _direction(direction),
          _x(centerPosX), _y(centerPosY)
{
    switch (direction)
    {
        case Animation::Up:
            _dy = - 2 * SPEED;
            _sourceRect.x = 0;
            _sourceRect.y = 0;
            _sourceRect.w = BULLET_WIGHT_WHEN_IS_UP;
            _sourceRect.h = BULLET_HEIGHT_WHEN_IS_UP;
            break;
        case Animation::Right:
            _dx = 2 * SPEED;
            _sourceRect.x = 0;
            _sourceRect.y = BULLET_HEIGHT_WHEN_IS_UP;
            _sourceRect.w = BULLET_HEIGHT_WHEN_IS_UP;
            _sourceRect.h = BULLET_WIGHT_WHEN_IS_UP;
            break;
        case Animation::Down:
            _dy = 2 * SPEED;
            _sourceRect.x = 0;
            _sourceRect.y = BULLET_HEIGHT_WHEN_IS_UP + BULLET_WIGHT_WHEN_IS_UP;
            _sourceRect.w = BULLET_WIGHT_WHEN_IS_UP;
            _sourceRect.h = BULLET_HEIGHT_WHEN_IS_UP;
            break;
        case Animation::Left:
            _dx = - 2 * SPEED;
            _sourceRect.x = 0;
            _sourceRect.y = 2 * BULLET_HEIGHT_WHEN_IS_UP + BULLET_WIGHT_WHEN_IS_UP;
            _sourceRect.w = BULLET_HEIGHT_WHEN_IS_UP;
            _sourceRect.h = BULLET_WIGHT_WHEN_IS_UP;
            break;
        default:
            ERROR << "Wrong direction: " << _direction << "\n";
    }
}

void Bullet::draw(Graphics& graphics) {
    Object::draw(graphics, _x, _y);
}

void Bullet::update(int elapsedTime) {
    _x += _dx * elapsedTime;
    _y += _dy * elapsedTime;

    _x < 0 ? _x = 0 : 0;
    _x > WINDOW_WIGHT ? _x = WINDOW_WIGHT : 0;
    _y < 0 ? _y = 0 : 0;
    _y > WINDOW_HEIGHT ? _y = WINDOW_HEIGHT : 0;
}

Smoke Bullet::createSmoke(Graphics& graphics) {
    return Smoke(graphics, _x, _y);
}

bool Bullet::isCollision() {
    return _x == 0 || _x == WINDOW_WIGHT || _y == 0 || _y == WINDOW_HEIGHT;
}

}
