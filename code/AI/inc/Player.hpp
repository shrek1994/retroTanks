#pragma once

#include "ITankController.hpp"

namespace Game {
class Input;
class Tank;
}

namespace AI {


class Player : public ITankController{
public:
    Player(Game::Input& input);

    void move(Game::Tank& tank) override;
private:
    Game::Input& input;
};

}