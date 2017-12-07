#include <SDL2/SDL.h>

#include <utility>

#include "debug.hpp"
#include "Constants.hpp"
#include "Player.hpp"
#include "Game.hpp"
#include "Bot.hpp"
#include "Barrel.hpp"

namespace Game {

Game::Game(std::shared_ptr<Graphics> graphics, std::shared_ptr<Input> input) :
    graphics(std::move(graphics)),
    input(std::move(input)),
    config(Config::getConfig()),
    enemyInOneRound(config.enemyInOneRound)
{}

void Game::init() {
    map = std::make_unique<Map>("level 1", *graphics, *this);

    createPlayer();
    createTanks();
}


void Game::gameLoop() {
    init();

    auto lastUpdateTime = SDL_GetTicks();

    do {
        input->beginNewFrame();

        auto currentTimeMs = SDL_GetTicks();
        auto elapsedTimeMs = currentTimeMs - lastUpdateTime;

        auto sleepMs = MAX_FRAME_TIME - elapsedTimeMs > MAX_FRAME_TIME ? 0 : MAX_FRAME_TIME - elapsedTimeMs;
        SDL_Delay(sleepMs);

        update(std::min(elapsedTimeMs, MAX_FRAME_TIME));
        draw(*graphics);

        lastUpdateTime = currentTimeMs;
    } while (input->isGameTerminated() && ! (isEnd));

    DEBUG << "Ending game - correctly\n";

    if (isEnd) {
        SDL_Delay(1000);
    }
}

void Game::createPlayer() {
    auto player = std::make_unique<AI::Player>(*input, *this);
    auto playerTank = std::make_unique<Tank>(
            std::move(player), *this, *graphics, 0, 0, GREEN_TANK);
    this->playerTank = playerTank.get();
    tanks.push_back(std::move(playerTank));
}

void Game::createTanks() {
    static int positionX = 0;
    while (tanks.size() < config.maxEnemyAtTheSameTime && enemyInOneRound > 0) {
        enemyInOneRound--;
        addTank(positionX, WINDOW_HEIGHT);
        positionX += WINDOW_WIGHT / config.maxEnemyAtTheSameTime;
        if (positionX > WINDOW_WIGHT)
            positionX = TANK_WIGHT + 1;
    }
}


void Game::draw(Graphics& graphics) {
    graphics.clear();

    map->drawBackground(graphics);

    for (const auto& tank : tanks) {
        tank->draw(graphics);
    }

    for (auto& obj : objects) {
        obj->draw(graphics);
    }

    map->drawTrees(graphics);

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

    createTanks();
    if (tanks.size() == 1)
        isEnd = true;
}

int Game::start() {
    gameLoop();
    return 0;
}

void Game::addObject(std::unique_ptr<Object>&& object) {
    objects.push_back(std::move(object));
}

void Game::addTank(int centerX, int centerY) {
    auto botTank = std::make_unique<AI::Bot>(*playerTank);
    auto tank = std::make_unique<Tank>(std::move(botTank), *this, *graphics, centerX, centerY);
    tanks.push_back(std::move(tank));
}

const std::list<std::unique_ptr<Tank>>& Game::getTanks() {
    return tanks;
}

const std::list<std::unique_ptr<Object>>& Game::getObjects() {
    return objects;
}

}
