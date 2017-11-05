#include <Player.hpp>
#include "Smoke.hpp"

namespace Game {


Smoke::Smoke(Graphics& graphics, int centerPosX, int centerPosY)
        : AnimatedObject(graphics, "res/smokeWhite.png", 0, 0, 107, 107, 125),
          _x(centerPosX), _y(centerPosY)
{
    setupAnimations();
}

void Smoke::setupAnimations() {
    addAnimation(3, 0, 0, Animation::IdleDown, 107, 107, SDL_Point{0, 107});

    playAnimation(Animation::IdleDown, true);
}

void Smoke::draw(Graphics& graphics) {
    AnimatedObject::draw(graphics, _x, _y);
}


}