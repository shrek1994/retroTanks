#include <SDL2/SDL.h>

#include "debug.hpp"
#include "Constants.hpp"
#include "Player.hpp"
#include "Game.hpp"
#include "Bot.hpp"
#include "Barrel.hpp"

namespace Game {

Game::Game() {
    SDL_Init(SDL_INIT_EVERYTHING);
}

void Game::init() {
    graphics = std::make_unique<Graphics>();
    input = std::make_unique<Input>();
    map = std::make_unique<Map>("level 1", SDL_Point{42, 42}, *graphics);
    objects.push_back(std::make_unique<Sandbag>(*graphics, 100, 400));
    objects.push_back(std::make_unique<Barrel>(*graphics, *this, 200, 400));

    createTanks();
}


void Game::gameLoop() {
    init();

    auto lastUpdateTime = SDL_GetTicks();

    do {
        input->beginNewFrame();

        auto currentTimeMs = SDL_GetTicks();
        auto elapsedTimeMs = currentTimeMs - lastUpdateTime;

        //TODO czy powinien byc sleep ?
        auto sleepMs = MAX_FRAME_TIME - elapsedTimeMs > MAX_FRAME_TIME ? 0 : MAX_FRAME_TIME - elapsedTimeMs;
        SDL_Delay(sleepMs);

        update(std::min(elapsedTimeMs, MAX_FRAME_TIME));
        draw(*graphics);

        lastUpdateTime = currentTimeMs;
    } while (input->isGameTerminated());

    DEBUG << "Ending game - correctly\n";
}

void Game::createTanks() {
    auto player = std::make_unique<AI::Player>(*input);
    auto playerTank = std::make_unique<Tank>(std::move(player), *this, *graphics, 100, 100);
    auto botTank1 = std::make_unique<AI::Bot>(*playerTank);
    auto botTank2 = std::make_unique<AI::Bot>(*playerTank);
    auto botTank3 = std::make_unique<AI::Bot>(*playerTank);
    auto botTank4 = std::make_unique<AI::Bot>(*playerTank);
    addTank(std::move(playerTank));
    addTank(std::make_unique<Tank>(std::move(botTank1), *this, *graphics, 200, 200));
    addTank(std::make_unique<Tank>(std::move(botTank2), *this, *graphics, 300, 300));
    addTank(std::make_unique<Tank>(std::move(botTank3), *this, *graphics, 400, 400));
    addTank(std::make_unique<Tank>(std::move(botTank4), *this, *graphics, 500, 500));
}


void Game::draw(Graphics& graphics) {
    graphics.clear();

    map->draw(graphics);

    for (const auto& tank : tanks) {
        tank->draw(graphics);
    }

    for (auto& obj : objects) {
        obj->draw(graphics);
    }

    map->drawTree(graphics);

    graphics.flip();
}

void Game::update(int elapsedTime) {
    for (const auto& tank : tanks) {
        tank->update(elapsedTime);
    }
    tanks.remove_if([](const auto& tank) { return tank->shouldBeRemove(); });

    for (const auto& obj : objects) {
        obj->update(elapsedTime);
    }
    objects.remove_if([](const auto& obj) { return obj->shouldBeRemove(); });

}

int Game::start() {
    gameLoop();
    return 0;
}

void Game::addObject(std::unique_ptr<Object>&& object) {
    objects.push_back(std::move(object));
}

void Game::addTank(std::unique_ptr<Tank>&& tank) {
    tanks.push_back(std::move(tank));
}

const std::list<std::unique_ptr<Tank>>& Game::getTanks() {
    return tanks;
}

const std::list<std::unique_ptr<Object>>& Game::getObjects() {
    return objects;
}

}
