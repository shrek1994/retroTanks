#pragma once

namespace Game {
class Tank;
}

namespace AI {

class ITankController {
public:
    virtual void move(Game::Tank& tank) = 0;
    virtual ~ITankController() = default;
};

}