#pragma once

#include "Graphics.hpp"

namespace GameView {

class Game {
public:
    Game();

private:
    void gameLoop();
    void draw(Graphics &graphics);
    void update(int elapsedTime);
};

}