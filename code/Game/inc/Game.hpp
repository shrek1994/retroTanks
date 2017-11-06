#pragma once

#include <memory>
#include <list>

#include "Graphics.hpp"
#include "Tank.hpp"
#include "Map.hpp"
#include "Bullet.hpp"
#include "Smoke.hpp"
#include "ObjectNotifier.hpp"

namespace Game {

class Game : public ObjectNotifier {
public:
    Game();
    int start();
private:
    void gameLoop();
    void draw(Graphics &graphics);
    void update(int elapsedTime);

    void addObject(std::unique_ptr<Object> object) override;

    std::unique_ptr<Graphics> _graphics;
    std::unique_ptr<Tank> _player ;
    std::unique_ptr<Map> _map;
    std::list<std::unique_ptr<Object>> _objects;
};

}