#include <SDL2/SDL.h>
#include <memory>
#include <debug.hpp>
#include <Game/inc/Bullet.hpp>

#include "Game.hpp"
#include "Input.hpp"

namespace Game {

Game::Game() {
    SDL_Init(SDL_INIT_EVERYTHING);
}


void Game::gameLoop() {
    auto graphics = std::make_unique<Graphics>();
    auto input = std::make_unique<Input>();
    _map = std::make_unique<Map>("level 1", SDL_Point{42, 42}, *graphics);
    _player = std::make_unique<Player>(*graphics, 100, 100);

    auto lastUpdateTime = SDL_GetTicks();

    do {
        input->beginNewFrame();

        if (input->isKeyHeld(SDL_SCANCODE_LEFT) || input->isKeyHeld(SDL_SCANCODE_A)) {
            _player->moveLeft();
        } else if (input->isKeyHeld(SDL_SCANCODE_RIGHT) || input->isKeyHeld(SDL_SCANCODE_D)) {
            _player->moveRight();
        } else if (input->isKeyHeld(SDL_SCANCODE_UP) || input->isKeyHeld(SDL_SCANCODE_W)) {
            _player->moveUp();
        } else if (input->isKeyHeld(SDL_SCANCODE_DOWN) || input->isKeyHeld(SDL_SCANCODE_S)) {
            _player->moveDown();
        } else {
            _player->stopMoving();
        }

        if (input->wasKeyPressed(SDL_SCANCODE_LCTRL)) {
            _bullets.push_back(_player->createBullet(*graphics));
        }



        auto currentTimeMs = SDL_GetTicks();
        auto elapsedTimeMs = currentTimeMs - lastUpdateTime;

        //TODO czy powinien byc sleep ?
        auto sleepMs = MAX_FRAME_TIME - elapsedTimeMs > MAX_FRAME_TIME ? 0 : MAX_FRAME_TIME - elapsedTimeMs;
        SDL_Delay(sleepMs);

        update(std::min(elapsedTimeMs, MAX_FRAME_TIME));
        lastUpdateTime = currentTimeMs;

        draw(*graphics);
    } while (input->isGameTerminated());

    DEBUG << "Ending game - correctly\n";
}

void Game::draw(Graphics& graphics) {
    graphics.clear();

    _map->draw(graphics);
    _player->draw(graphics);
    for(auto& bullet : _bullets) {
        bullet.draw(graphics);
    }

    graphics.flip();
}

void Game::update(int elapsedTime) {
    _player->update(elapsedTime);
    for(auto& bullet : _bullets) {
        bullet.update(elapsedTime);
    }
}

int Game::start() {
    gameLoop();
    return 0;
}

}
