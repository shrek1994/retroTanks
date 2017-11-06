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

    void conditionallyMove(Game::Tank& tank) override;
    void conditionallyShoot(Game::Tank& tank, Game::Graphics& graphics) override;
private:
    Game::Input& input;
};

}