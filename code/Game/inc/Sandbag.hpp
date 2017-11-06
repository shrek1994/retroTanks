#pragma once

#include "Object.hpp"

namespace Game {

class Sandbag : public Object {
public:
    Sandbag(Game::Graphics& graphics, int centerX, int centerY);

    void draw(Graphics& graphics) override;
    void update(int elapsedTime) override;
    bool shouldBeRemove() override;
    SDL_Rect getRectangle() override;

private:
    double _centerX, _centerY;
};


}
