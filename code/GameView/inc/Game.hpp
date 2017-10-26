#pragma once

#include "Graphics.hpp"
#include "Player.hpp"
#include <memory>

namespace GameView {

class Game {
public:
    Game();
    int start();
private:
    void gameLoop();
    void draw(Graphics &graphics);
    void update(int elapsedTime);

    std::unique_ptr<Player> _player ;
};

}