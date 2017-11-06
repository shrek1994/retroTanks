#include <SDL2/SDL.h>
#include <memory>

#include "debug.hpp"
#include "Constants.hpp"
#include "Bullet.hpp"
#include "Player.hpp"
#include "Game.hpp"
#include "Input.hpp"

namespace Game {

Game::Game() {
    SDL_Init(SDL_INIT_EVERYTHING);
}

void Game::init() {
    _graphics = std::make_unique<Graphics>();
    _input = std::make_unique<Input>();
    _map = std::make_unique<Map>("level 1", SDL_Point{42, 42}, *_graphics);
    _objects.push_back(std::make_unique<Sandbag>(*_graphics, 200, 200));
}


void Game::gameLoop() {
    init();
    AI::Player player(*_input);
    _player = std::make_unique<Tank>(player, *this, *_graphics, 100, 100);

    auto lastUpdateTime = SDL_GetTicks();

    do {
        _input->beginNewFrame();

        auto currentTimeMs = SDL_GetTicks();
        auto elapsedTimeMs = currentTimeMs - lastUpdateTime;

        //TODO czy powinien byc sleep ?
        auto sleepMs = MAX_FRAME_TIME - elapsedTimeMs > MAX_FRAME_TIME ? 0 : MAX_FRAME_TIME - elapsedTimeMs;
        SDL_Delay(sleepMs);

        update(std::min(elapsedTimeMs, MAX_FRAME_TIME));
        draw(*_graphics);

        lastUpdateTime = currentTimeMs;
    } while (_input->isGameTerminated());

    DEBUG << "Ending game - correctly\n";
}


void Game::draw(Graphics& graphics) {
    graphics.clear();

    _map->draw(graphics);
    _player->draw(graphics);

    for (auto& obj : _objects) {
        obj->draw(graphics);
    }

    graphics.flip();
}

void Game::update(int elapsedTime) {
    _player->update(elapsedTime, _objects);

    for (auto& obj : _objects) {
        obj->update(elapsedTime);
    }
    _objects.remove_if([](auto& obj) { return obj->shouldBeRemove(); });

}

int Game::start() {
    gameLoop();
    return 0;
}

void Game::addObject(std::unique_ptr<Object> object) {
    _objects.push_back(std::move(object));
}

}
