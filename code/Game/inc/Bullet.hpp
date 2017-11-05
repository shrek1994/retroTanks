#pragma once

#include <Constants.hpp>
#include <debug.hpp>
#include "Object.hpp"
#include "Animation.hpp"
#include "Smoke.hpp"

namespace Game {


class Bullet : public Object {
public:
    Bullet(Graphics& graphics,
           int centerPosX, int centerPosY,
           Animation direction);

    void draw(Graphics& graphics) override;
    void update(int elapsedTime) override;

    bool isCollision();
    Smoke createSmoke(Graphics& graphics);

    bool operator==(const Bullet& bullet) {
        return this == &bullet;
    }
private:
    Animation _direction;
    double _x, _y;
    double _dx = 0, _dy = 0;
};

}
