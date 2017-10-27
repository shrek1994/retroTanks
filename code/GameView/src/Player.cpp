#include "Player.hpp"

namespace GameView {


Player::Player(Graphics& graphics, int posX, int posY) :
        AnimatedObject(graphics,
                       "../res/tank_user_1.png",
                       0,
                       0,
                       56,
                       56,
                       posX,
                       posY,
                       125)
{}

}