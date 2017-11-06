#pragma once

#include "AnimatedObject.hpp"

namespace Game {

class Smoke : public AnimatedObject {
public:
    Smoke(Graphics& graphics, int centerPosX, int centerPosY);

    void setupAnimations() override;
    void draw(Graphics& graphics) override;
    bool shouldBeRemove() override;
    SDL_Rect getRectangle() override;

private:
    int _centerX, _centerY;
};

}