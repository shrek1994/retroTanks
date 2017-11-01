#include <debug.hpp>
#include "Player.hpp"

namespace GameView {


Player::Player(Graphics& graphics, int posX, int posY) :
        AnimatedObject(graphics,
                       "res/playerTank.png",
                       0,
                       0,
                       85,
                       85,
                       posX,
                       posY,
                       125),
        _x(posX), _y(posY)
{
    setupAnimations();
}

void Player::setupAnimations() {
    addAnimation(2, 0, 0, Direction::Down, 85, 85, Offset{0, 85});
    addAnimation(2, 0, 85, Direction::Left, 85, 85, Offset{0, 85});
    addAnimation(2, 0, 170, Direction::Up, 85, 85, Offset{0, 85});
    addAnimation(2, 0, 255, Direction::Right, 85, 85, Offset{0, 85});

    LOG << "loading player animation - DONE!\n";
}

void Player::draw(Graphics& graphics) {
    AnimatedObject::draw(graphics, _x, _y);
}

}