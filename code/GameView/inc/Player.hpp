#pragma once

#include <AnimatedObject.hpp>

namespace GameView {

class Player : public AnimatedObject {
public:
    Player(Graphics& graphics, int posX, int posY);
};


}