#pragma once

#include "Object.hpp"
#include "Animation.hpp"

namespace Game {


class Bullet : public Object {
public:
    Bullet(Graphics& graphics,
           int posX, int posY,
           Animation direction);

    void draw(Graphics& graphics) override {
        SDL_Rect destinationRectangle = { x,
                                          y,
                                          _bullet.w,
                                          _bullet.h };
        graphics.render(_objectSheet, &_bullet, &destinationRectangle);
    }

    void update(int elapsedTime) override {

    }
private:
    Animation _direction;
    SDL_Rect _bullet;
    int x, y;
};

}
