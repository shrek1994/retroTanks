#pragma once

#include "Graphics.hpp"
#include "Tank.hpp"
#include "Map.hpp"
#include "Bullet.hpp"
#include <memory>
#include <list>

namespace Game {

class Game {
public:
    Game();
    int start();
private:
    void gameLoop();
    void draw(Graphics &graphics);
    void update(int elapsedTime);

    std::unique_ptr<Graphics> _graphics;
    std::unique_ptr<Tank> _player ;
    std::unique_ptr<Map> _map;
    std::list<Bullet> _bullets;
    std::list<Smoke> _smokes;
};

}