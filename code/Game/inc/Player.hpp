#pragma once

#include <AnimatedObject.hpp>
#include <memory>
#include "Bullet.hpp"

namespace Game {

class Player : public AnimatedObject {
public:
    Player(Graphics& graphics, int posX, int posY);

    void setupAnimations() override;
    void update(int elapsedTime) override;
    void draw(Graphics& graphics) override;

    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    void stopMoving();

    Animation getDirection();
    Bullet createBullet(Graphics& graphics);

private:
    Animation _direction;
    double _dx = 0, _dy = 0;
    double _x, _y;
};


}