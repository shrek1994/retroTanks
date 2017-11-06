#pragma once

#include <memory>
#include "Object.hpp"
#include "Animation.hpp"

namespace Game {
class Smoke;
class ObjectNotifier;

class Bullet : public Object {
public:
    Bullet(Graphics& graphics,
           ObjectNotifier& newObjectNotifier,
           int centerPosX, int centerPosY,
           Animation direction);

    void draw(Graphics& graphics) override;
    void update(int elapsedTime) override;
    bool shouldBeRemove() override;

    bool isCollision();
    std::unique_ptr<Smoke> createSmoke(Graphics& graphics);
    ~Bullet() override;
private:
    Animation _direction;
    double _x, _y;
    double _dx = 0, _dy = 0;

    Graphics& _graphics;
    ObjectNotifier& _newObjectNotifier;
};

}
