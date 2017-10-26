#pragma once

#include "Graphics.hpp"

class Game {
public:
    Game();
private:
    void gameLoop();
    void draw(Graphics &graphics);
    void update(int elapsedTime);
};
