#pragma once

#include <memory>
#include "Object.hpp"
#include "Animation.hpp"

namespace Game {
class Smoke;
class ObjectOwner;

class Bullet : public Object {
public:
    Bullet(Graphics& graphics,
           ObjectOwner& objectOwner,
           int centerPosX, int centerPosY,
           Animation direction);

    void draw(Graphics& graphics) override;
    void update(int elapsedTime) override;
    bool shouldBeRemove() const override;
    SDL_Rect getRectangle() const override;

    std::unique_ptr<Smoke> createSmoke(Graphics& graphics);
    ~Bullet() override;
private:
    bool isCollisionWithWall() const;
    bool checkCollisionWithTanks() const;
    bool checkCollisionWithObjects() const;

    Animation direction;
    double centerX, centerY;
    double _dx = 0, _dy = 0;

    Graphics& graphics;
    ObjectOwner& objectOwner;
};

}
