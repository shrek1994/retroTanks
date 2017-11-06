#pragma once

#include "AnimatedObject.hpp"
#include <memory>

namespace AI {
class ITankController;
}

namespace Game {
class Bullet;
class ObjectNotifier;

class Tank : public AnimatedObject {
public:
    Tank(AI::ITankController& tankController, ObjectNotifier& newObjectNotifier, Graphics& graphics, int posX, int posY);

    void setupAnimations() override;
    void update(int elapsedTime) override;
    void draw(Graphics& graphics) override;
    bool shouldBeRemove() override;

    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    void stopMoving();

    void shoot(Graphics& graphics);

    Animation getDirection();
    std::unique_ptr<Bullet> createBullet(Graphics& graphics);

private:
    double _dx = 0, _dy = 0;
    double _x, _y;
    Animation _direction;
    AI::ITankController& _tankController;
    ObjectNotifier& _newObjectNotifier;
};


}