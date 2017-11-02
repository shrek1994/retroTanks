#include <SDL2/SDL.h>
#include <memory>

#include "Game.hpp"
#include "Input.hpp"

namespace {
    constexpr unsigned FPS = 50;
    constexpr unsigned MAX_FRAME_TIME = 1000 / FPS;
}

namespace GameView {

Game::Game() {
    SDL_Init(SDL_INIT_EVERYTHING);
}


void Game::gameLoop() {
    Graphics graphics;
    Input input;
    SDL_Event event;
    _map = std::make_unique<Map>("level 1", Offset{42, 42}, graphics);
    _player = std::make_unique<Player>(graphics, 100, 100);
    _player->playAnimation(Animation::Right);

    int LAST_UPDATE_TIME = SDL_GetTicks();

    do {
        input.beginNewFrame();

        if (SDL_PollEvent(&event)) {
            if (event.type == SDL_KEYDOWN && event.key.repeat == 0) {
                input.keyDownEvent(event);
            } else if (event.type == SDL_KEYUP) {
                input.keyUpEvent(event);
            }
        }

        if (input.isKeyHeld(SDL_SCANCODE_LEFT)) {
            _player->moveLeft();
        } else if (input.isKeyHeld(SDL_SCANCODE_RIGHT)) {
            _player->moveRight();
        } else if (input.isKeyHeld(SDL_SCANCODE_UP)) {
            _player->moveUp();
        } else if (input.isKeyHeld(SDL_SCANCODE_DOWN)) {
            _player->moveDown();
        } else if (!input.isKeyHeld(SDL_SCANCODE_LEFT) && !input.isKeyHeld(SDL_SCANCODE_RIGHT)
            && !input.isKeyHeld(SDL_SCANCODE_UP) && !input.isKeyHeld(SDL_SCANCODE_DOWN)) {
            _player->stopMoving();
        }

        unsigned CURRENT_TIME_MS = SDL_GetTicks();
        unsigned ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;

        update(std::min(ELAPSED_TIME_MS, MAX_FRAME_TIME));
        LAST_UPDATE_TIME = CURRENT_TIME_MS;

        draw(graphics);
    } while (event.type != SDL_QUIT);
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
