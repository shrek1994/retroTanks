#pragma once

#include "AnimatedObject.hpp"

namespace Game {

class Smoke : public AnimatedObject {
public:
    Smoke(Graphics& graphics, int centerPosX, int centerPosY);

    void setupAnimations() override;
    void draw(Graphics& graphics) override;


    bool operator==(const Smoke& smoke) {
        return this == &smoke;
    }
private:
    int _x, _y;
};

}