#pragma once

namespace Game {
class Tank;
class Graphics;
}

namespace AI {

class ITankController {
public:
    virtual void conditionallyMove(Game::Tank& tank) = 0;
    virtual void conditionallyShoot(Game::Tank& tank, Game::Graphics& graphics) = 0;
    virtual ~ITankController() = default;
};

}