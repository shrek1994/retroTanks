#pragma once

#include "AnimatedObject.hpp"
#include "ITankController.hpp"
#include <memory>
#include <list>


namespace Game {
class Bullet;
class ObjectOwner;

class Tank : public AnimatedObject {
public:
    Tank(std::unique_ptr<AI::ITankController>&& tankController,
         ObjectOwner& objectOwner,
         Graphics& graphics,
         int posX, int posY);

    void setupAnimations() override;
    void update(int elapsedTime) override;
    void draw(Graphics& graphics) override;
    bool shouldBeRemove() const override;
    SDL_Rect getRectangle() const override;

    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    void stopMoving();

    double getXPosition() const;
    double getYPosition() const;

    void shoot(Graphics& graphics);
    void setKilled();

    Animation getDirection();
    std::unique_ptr<Bullet> createBullet(Graphics& graphics);

    ~Tank() override;
private:
    bool isKilled = false;
    double _dx = 0, _dy = 0;
    double centerX, centerY;
    Animation direction;
    std::unique_ptr<AI::ITankController> tankController;
    ObjectOwner& objectOwner;
    Graphics& graphics;
};


}