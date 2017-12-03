#pragma once

#include <memory>
#include "Object.hpp"

class Graphics;

namespace Menu {

enum class State {
    Active,
    Inactive
};


class Button {
public:
    Button(std::unique_ptr<Object>&& inactiveBackground,
           std::unique_ptr<Object>&& activeBackground,
           std::unique_ptr<Object>&& text,
           int centerX, int centerY)
            : inactiveBackground(std::move(inactiveBackground)),
              activeBackground(std::move(activeBackground)),
              text(std::move(text)),
              centerX(centerX),
              centerY(centerY)
    {}

    void draw(Graphics& graphics) {
        if (state == State::Active) {
            activeBackground->draw(graphics, centerX, centerY);
        } else {
            inactiveBackground->draw(graphics, centerX, centerY);
        }
        text->draw(graphics, centerX, centerY);
    }
private:
    std::unique_ptr<Object> inactiveBackground;
    std::unique_ptr<Object> activeBackground;
    std::unique_ptr<Object> text;
    State state = State::Inactive;
    int centerX;
    int centerY;
};

}
