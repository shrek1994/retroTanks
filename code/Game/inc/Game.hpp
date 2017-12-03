#pragma once

#include <memory>
#include <list>

#include "Graphics.hpp"
#include "Tank.hpp"
#include "Map.hpp"
#include "Bullet.hpp"
#include "Smoke.hpp"
#include "ObjectOwner.hpp"
#include "Sandbag.hpp"
#include "Input.hpp"

namespace Game {

class Game : public ObjectOwner {
public:
    Game(std::shared_ptr<Graphics> graphics, std::shared_ptr<Input> input);
    int start();

    void addObject(std::unique_ptr<Object>&& object) override;
    const std::list<std::unique_ptr<Tank>>& getTanks() override;
    const std::list<std::unique_ptr<Object>>& getObjects() override;
private:
    void init();
    void gameLoop();
    void draw(Graphics &graphics);
    void update(int elapsedTime);

    void createTanks();
    void addTank(std::unique_ptr<Tank>&& tank);

    std::shared_ptr<Graphics> graphics;
    std::shared_ptr<Input> input;
    std::unique_ptr<Map> map;

    std::list<std::unique_ptr<Object>> objects;
    std::list<std::unique_ptr<Tank>> tanks;
};

}
