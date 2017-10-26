#include <SDL2/SDL.h>

#include "Game.hpp"
#include "Input.hpp"

namespace {
    constexpr int FPS = 50;
    constexpr int MAX_FRAME_TIME = 1000 / FPS;
}

namespace GameView {

Game::Game() {
    SDL_Init(SDL_INIT_EVERYTHING);
    this->gameLoop();
}


void Game::gameLoop() {
    Graphics graphics;
    Input input;
    SDL_Event event;

    int LAST_UPDATE_TIME = SDL_GetTicks();

    do {
        input.beginNewFrame();

        if (SDL_PollEvent(&event)) {
            if (event.type == SDL_KEYDOWN) {
                if (event.key.repeat == 0) {
                    input.keyDownEvent(event);
                }
            } else if (event.type == SDL_KEYUP) {
                input.keyUpEvent(event);
            }
        }

        const int CURRENT_TIME_MS = SDL_GetTicks();
        int ELAPSED_TIME_MS = CURRENT_TIME_MS - LAST_UPDATE_TIME;

        this->update(std::min(ELAPSED_TIME_MS, MAX_FRAME_TIME));
        LAST_UPDATE_TIME = CURRENT_TIME_MS;

        this->draw(graphics);
    } while (event.type != SDL_QUIT);
}

void Game::draw(Graphics& graphics) {
    graphics.clear();

    graphics.flip();
}

void Game::update(int elapsedTime) {
}

}