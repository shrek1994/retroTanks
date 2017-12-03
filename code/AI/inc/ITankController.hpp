#pragma once

class Graphics;

namespace Game {
class Tank;
}

namespace AI {

class ITankController {
public:
    virtual void conditionallyMove(Game::Tank& tank) = 0;
    virtual void conditionallyShoot(Game::Tank& tank, Graphics& graphics) = 0;
    virtual ~ITankController() = default;
};

}