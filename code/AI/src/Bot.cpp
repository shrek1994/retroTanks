#include "Tank.hpp"
#include "AI/inc/Bot.hpp"
#include <ctime>



namespace AI {

    Bot::Bot(const Game::Tank &player) : player{player}
    {}

    void Bot::conditionallyMove(Game::Tank& tank)
    {
        std::srand(std::time(0));
        int randVar = std::rand() % 6;

        for (int i = 0; i < 5; ++i) {
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
        }
    }

    void Bot::conditionallyShoot(Game::Tank& tank, Game::Graphics& graphics)
    {
        if (shouldShoot(tank.getYPosition(), player.getYPosition())) {
            tank.shoot(graphics);
        }
    }

    bool Bot::shouldShoot(double botPosition, double playerPosition) const noexcept
    {
        return botPosition < playerPosition + 5 && botPosition > playerPosition - 5;
    }
}