#pragma once

#include "Object.hpp"
#include "Animation.hpp"

namespace Game {


class Bullet : public Object {
public:
    Bullet(Graphics& graphics,
           int posX, int posY,
           Animation direction);

    void draw(Graphics& graphics) override;
    void update(int elapsedTime) override {}
private:
    Animation _direction;
    int x, y;
};

}
