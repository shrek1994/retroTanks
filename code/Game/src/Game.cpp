#include <SDL2/SDL.h>
#include <memory>
#include <debug.hpp>
#include <Game/inc/Bullet.hpp>

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
    _map = std::make_unique<Map>("level 1", Offset{42, 42}, *graphics);
    _player = std::make_unique<Player>(*graphics, 0, 0);
    bullets = std::vector<Bullet>{
            Bullet{*graphics, 20,20, Animation::Up},
            Bullet{*graphics, 40,40, Animation::Down},
            Bullet{*graphics, 60,60, Animation::Left},
            Bullet{*graphics, 80,80, Animation::Right},
    };

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
        } else if (!input->isKeyHeld(SDL_SCANCODE_LEFT) && !input->isKeyHeld(SDL_SCANCODE_RIGHT)
            && !input->isKeyHeld(SDL_SCANCODE_UP) && !input->isKeyHeld(SDL_SCANCODE_DOWN)) {
            _player->stopMoving();
        }



        auto currentTimeMs = SDL_GetTicks();
        auto elapsedTimeMs = currentTimeMs - lastUpdateTime;

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

    for(auto bullet : bullets)
    {
        bullet.draw(graphics);
    }

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
