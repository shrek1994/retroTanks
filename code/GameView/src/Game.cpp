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
    _player = std::make_unique<Player>(graphics, 100, 100);
    _player->playAnimation(Direction::Right);

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

        unsigned CURRENT_TIME_MS = SDL_GetTicks();
        unsigned ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;

        update(std::min(ELAPSED_TIME_MS, MAX_FRAME_TIME));
        LAST_UPDATE_TIME = CURRENT_TIME_MS;

        draw(graphics);
    } while (event.type != SDL_QUIT);
}

void Game::draw(Graphics& graphics) {
    graphics.clear();

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
