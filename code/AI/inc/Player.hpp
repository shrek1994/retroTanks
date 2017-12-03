#pragma once

#include "ITankController.hpp"

class Input;
namespace Game {
class Game;
class Tank;
}

namespace AI {


class Player : public ITankController{
public:
    Player(Input& input, Game::Game& game);

    void conditionallyMove(Game::Tank& tank) override;
    void conditionallyShoot(Game::Tank& tank, Graphics& graphics) override;

    ~Player() override;
private:
    Input& input;
    Game::Game& game;
};

}