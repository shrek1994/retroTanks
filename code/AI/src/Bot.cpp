#include "Tank.hpp"
#include "AI/inc/Bot.hpp"
#include <ctime>
#include <random>
#include <Constants.hpp>
#include <debug.hpp>

namespace {
constexpr unsigned MIN_MOVES_IN_ONE_DIRECTION = 15;
}

namespace AI {

    Bot::Bot(const Game::Tank &player) : player{player}
    {}

    void Bot::conditionallyMove(Game::Tank& tank)
    {
        if (movingNumber++ != MIN_MOVES_IN_ONE_DIRECTION) {
            return;
        }

        std::random_device rd;
        std::mt19937 mt(rd());
        std::uniform_int_distribution<> dist(1, 4);
        auto randVar = dist(mt);

        if (randVar == 0) {
            tank.stopMoving();
        } else if (randVar == 1) {
            tank.moveDown();
        } else if (randVar == 2) {
            tank.moveLeft();
        } else if (randVar == 3) {
            tank.moveUp();
        } else if (randVar == 4){
            tank.moveRight();
        } else {
            tank.stopMoving();
        }

        movingNumber = 0;
    }

    void Bot::conditionallyShoot(Game::Tank& tank, Game::Graphics& graphics)
    {
        if (shouldShoot(tank.getYPosition(), player.getYPosition()) && movingNumber == MIN_MOVES_IN_ONE_DIRECTION) {
            tank.shoot(graphics);
        }
    }

    bool Bot::shouldShoot(double botPosition, double playerPosition) const noexcept
    {
        return botPosition < playerPosition + TANK_HEIGHT * SCALE_HEIGHT
               && botPosition > playerPosition - TANK_HEIGHT * SCALE_HEIGHT;
    }
}