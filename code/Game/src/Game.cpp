#include <SDL2/SDL.h>
#include <memory>
#include <debug.hpp>

#include "Game.hpp"
#include "Input.hpp"

namespace {
    constexpr unsigned FPS = 50;
    constexpr unsigned MAX_FRAME_TIME = 1000 / FPS;
}

namespace Game {

Game::Game() {
    SDL_Init(SDL_INIT_EVERYTHING);
}


void Game::gameLoop() {
    auto graphics = std::make_unique<Graphics>();
    auto input = std::make_unique<Input>();
    _map = std::make_unique<Map>("level 1", Offset{42, 42}, graphics);
    _player = std::make_unique<Player>(graphics, 0, 0);

    int LAST_UPDATE_TIME = SDL_GetTicks();

    do {
        input->beginNewFrame();

        if (input->isKeyHeld(SDL_SCANCODE_LEFT)) {
            _player->moveLeft();
        } else if (input->isKeyHeld(SDL_SCANCODE_RIGHT)) {
            _player->moveRight();
        } else if (input->isKeyHeld(SDL_SCANCODE_UP)) {
            _player->moveUp();
        } else if (input->isKeyHeld(SDL_SCANCODE_DOWN)) {
            _player->moveDown();
        } else if (!input->isKeyHeld(SDL_SCANCODE_LEFT) && !input->isKeyHeld(SDL_SCANCODE_RIGHT)
            && !input->isKeyHeld(SDL_SCANCODE_UP) && !input->isKeyHeld(SDL_SCANCODE_DOWN)) {
            _player->stopMoving();
        }

        unsigned CURRENT_TIME_MS = SDL_GetTicks();
        unsigned ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;

        update(std::min(ELAPSED_TIME_MS, MAX_FRAME_TIME));
        LAST_UPDATE_TIME = CURRENT_TIME_MS;

        draw(*graphics);
    } while (input->isGameTerminated());

    DEBUG << "Ending game - correctly\n";
}

void Game::draw(Graphics& graphics) {
    graphics.clear();

    _map->draw(graphics);
    _player->draw(graphics);

    graphics.flip();
}

void Game::update(int elapsedTime) {
    _player->update(elapsedTime);
}

int Game::start() {
    gameLoop();
    return 0;
}

}
