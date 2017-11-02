#pragma once

#include <AnimatedObject.hpp>

namespace Game {

class Player : public AnimatedObject {
public:
    Player(Graphics& graphics, int posX, int posY);

    void setupAnimations() override;
    void update(int elapsedTime) override ;
    void draw(Graphics& graphics);

    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    void stopMoving();

private:
    Animation _direction;
    double _dx = 0, _dy = 0;
    double _x, _y;
};


}