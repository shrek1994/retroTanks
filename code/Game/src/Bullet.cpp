#include <Animation.hpp>
#include <debug.hpp>
#include "Bullet.hpp"

namespace Game {


Bullet::Bullet(Graphics& graphics,
               int posX, int posY,
               Animation direction)
        : Object(graphics,
                 "res/bulletGreen.png",
                 0, 0,
                 20, 34),
          _direction(direction),
          x(posX), y(posY)
{
    switch (direction)
    {
        case Animation::Up:
            _sourceRect.x = 0;
            _sourceRect.y = 0;
            _sourceRect.w = 20;
            _sourceRect.h = 34;
            break;
        case Animation::Right:
            _sourceRect.x = 0;
            _sourceRect.y = 34;
            _sourceRect.w = 34;
            _sourceRect.h = 20;
            break;
        case Animation::Down:
            _sourceRect.x = 0;
            _sourceRect.y = 54;
            _sourceRect.w = 20;
            _sourceRect.h = 34;
            break;
        case Animation::Left:
            _sourceRect.x = 0;
            _sourceRect.y = 88;
            _sourceRect.w = 34;
            _sourceRect.h = 20;
            break;
        default:
            ERROR << "Wrong direction: " << _direction << "\n";
    }
}

void Bullet::draw(Graphics& graphics) {
    Object::draw(graphics, x, y);
}

}
