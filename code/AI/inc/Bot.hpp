#pragma once

#include "ITankController.hpp"

namespace Game {

class Tank;
class Graphics;

}


namespace AI {

class Bot : public ITankController
{
public:
    Bot(const Game::Tank& player);
    ~Bot() = default;
    void conditionallyMove(Game::Tank& tank) override;
    void conditionallyShoot(Game::Tank& tank, Game::Graphics& graphics) override;
private:
    bool inline shouldShoot(double botPosition, double playerPosition) const noexcept;

    const Game::Tank& player;
};

}
