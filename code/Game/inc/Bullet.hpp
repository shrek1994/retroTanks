#pragma once

#include <Constants.hpp>
#include <debug.hpp>
#include "Object.hpp"
#include "Animation.hpp"

namespace Game {


class Bullet : public Object {
public:
    Bullet(Graphics& graphics,
           int centerPosX, int centerPosY,
           Animation direction);

    void draw(Graphics& graphics) override;
    void update(int elapsedTime) override {
        _x += _dx * elapsedTime;
        _y += _dy * elapsedTime;

        _x < 0 ? _x = 0 : 0;
        _x > WINDOW_WIGHT ? _x = WINDOW_WIGHT : 0;
        _y < 0 ? _y = 0 : 0;
        _y > WINDOW_HEIGHT ? _y = WINDOW_HEIGHT : 0;
    }

private:
    Animation _direction;
    double _x, _y;
    double _dx = 0, _dy = 0;
};

}
