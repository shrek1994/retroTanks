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
            _bullet.x = 0;
            _bullet.y = 0;
            _bullet.w = 20;
            _bullet.h = 34;
            break;
        case Animation::Right:
            _bullet.x = 0;
            _bullet.y = 34;
            _bullet.w = 34;
            _bullet.h = 20;
            break;
        case Animation::Down:
            _bullet.x = 0;
            _bullet.y = 54;
            _bullet.w = 20;
            _bullet.h = 34;
            break;
        case Animation::Left:
            _bullet.x = 0;
            _bullet.y = 88;
            _bullet.w = 34;
            _bullet.h = 20;
            break;
        default:
            ERROR << "Wrong direction: " << _direction << "\n";
    }
}

}
