#pragma once

#include "ITankController.hpp"

class Graphics;

namespace Game {

class Tank;

}


namespace AI {

class Bot : public ITankController
{
public:
    Bot(const Game::Tank& player);
    ~Bot() = default;
    void conditionallyMove(Game::Tank& tank) override;
    void conditionallyShoot(Game::Tank& tank, Graphics& graphics) override;
private:
    bool inline shouldShoot(double botPosition, double playerPosition) const noexcept;

    const Game::Tank& player;
    unsigned movingNumber = 0;
};

}
