#include "AI/inc/Player.hpp"
#include "common/Input.hpp"
#include "Tank.hpp"

namespace AI {

Player::Player(Input& input) : input(input) {}

void Player::conditionallyMove(Game::Tank& tank) {
    if (input.isKeyHeld(SDL_SCANCODE_LEFT) || input.isKeyHeld(SDL_SCANCODE_A)) {
        tank.moveLeft();
    } else if (input.isKeyHeld(SDL_SCANCODE_RIGHT) || input.isKeyHeld(SDL_SCANCODE_D)) {
        tank.moveRight();
    } else if (input.isKeyHeld(SDL_SCANCODE_UP) || input.isKeyHeld(SDL_SCANCODE_W)) {
        tank.moveUp();
    } else if (input.isKeyHeld(SDL_SCANCODE_DOWN) || input.isKeyHeld(SDL_SCANCODE_S)) {
        tank.moveDown();
    } else {
        tank.stopMoving();
    }
}

void Player::conditionallyShoot(Game::Tank& tank, Graphics& graphics) {
    if (input.wasKeyPressed(SDL_SCANCODE_LCTRL)
        || input.wasKeyPressed(SDL_SCANCODE_RCTRL)) {
        tank.shoot(graphics);
    }
}

}
