#include "debug.hpp"
#include "Bullet.hpp"
#include "Constants.hpp"
#include "Graphics.hpp"
#include "Smoke.hpp"
#include "ObjectNotifier.hpp"

namespace Game {
namespace {
constexpr int BULLET_WIGHT_WHEN_IS_UP = 20;
constexpr int BULLET_HEIGHT_WHEN_IS_UP = 34;
}


Bullet::Bullet(Graphics& graphics,
               ObjectNotifier& newObjectNotifier,
               int centerPosX, int centerPosY,
               Animation direction)
        : Object(graphics,
                 "res/bulletGreen.png",
                 0, 0,
                 BULLET_WIGHT_WHEN_IS_UP, BULLET_HEIGHT_WHEN_IS_UP),
          _direction(direction),
          _centerX(centerPosX), _centerY(centerPosY),
          _graphics(graphics),
          _newObjectNotifier(newObjectNotifier)
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
    _newObjectNotifier.addObject(std::move(createSmoke(graphics)));
}

void Bullet::draw(Graphics& graphics) {
    Object::draw(graphics, _centerX, _centerY);
}

void Bullet::update(int elapsedTime) {
    _centerX += _dx * elapsedTime;
    _centerY += _dy * elapsedTime;

    _centerX < 0 ? _centerX = 0 : 0;
    _centerX > WINDOW_WIGHT ? _centerX = WINDOW_WIGHT : 0;
    _centerY < 0 ? _centerY = 0 : 0;
    _centerY > WINDOW_HEIGHT ? _centerY = WINDOW_HEIGHT : 0;
}

std::unique_ptr<Smoke> Bullet::createSmoke(Graphics& graphics) {
    return std::make_unique<Smoke>(graphics, _centerX, _centerY);
}

bool Bullet::isCollision() const {
    return _centerX == 0 || _centerX == WINDOW_WIGHT || _centerY == 0 || _centerY == WINDOW_HEIGHT;
}

bool Bullet::shouldBeRemove() const {
    return isCollision();
}

Bullet::~Bullet() {
    _newObjectNotifier.addObject(std::move(createSmoke(_graphics)));
}

SDL_Rect Bullet::getRectangle() const {
    return SDL_Rect{static_cast<int>(_centerX - getWight() / 2),
                    static_cast<int>(_centerY - getHeight() / 2),
                    static_cast<int>(getWight()),
                    static_cast<int>(getHeight())};
}

}
