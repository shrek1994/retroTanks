#pragma once

#include "ITankController.hpp"

class Input;
namespace Game {
class Tank;
}

namespace AI {


class Player : public ITankController{
public:
    Player(Input& input);

    void conditionallyMove(Game::Tank& tank) override;
    void conditionallyShoot(Game::Tank& tank, Graphics& graphics) override;
private:
    Input& input;
};

}