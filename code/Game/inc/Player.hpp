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

    Bullet createBullet(Graphics& graphics) {
        auto direction = getDirection();
        auto posX = _x;
        auto posY = _y;

        if (direction == Animation::Left) {
            posY += TANK_HEIGHT / 2 * SCALE_HEIGHT;
        } else if (direction == Animation::Right) {
            posX += TANK_WIGHT * SCALE_WIGHT;
            posY += TANK_HEIGHT / 2 * SCALE_HEIGHT;
        } else if (direction == Animation::Up) {
            posX += TANK_WIGHT / 2 * SCALE_WIGHT;
        } else if (direction == Animation::Down) {
            posX += TANK_WIGHT / 2 * SCALE_WIGHT;
            posY += TANK_HEIGHT * SCALE_HEIGHT;
        }



        return Bullet(graphics, posX, posY, direction);
    }

private:
    Animation _direction;
    double _dx = 0, _dy = 0;
    double _x, _y;
};


}