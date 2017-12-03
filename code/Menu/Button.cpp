#include "Button.hpp"

namespace Menu {
Button::Button(std::unique_ptr<Object>&& inactiveBackground,
                std::unique_ptr<Object>&& activeBackground,
                std::unique_ptr<Object>&& text,
                int centerX, int centerY)
                : inactiveBackground(std::move(inactiveBackground)),
                activeBackground(std::move(activeBackground)),
                text(std::move(text)),
                centerX(centerX),
                centerY(centerY)
                {}

void Button::draw(Graphics& graphics) {
    if (state == State::Active) {
        activeBackground->draw(graphics, centerX, centerY);
    } else {
        inactiveBackground->draw(graphics, centerX, centerY);
    }
    text->draw(graphics, centerX, centerY);
}

void Button::setState(State state) {
    this->state = state;
}

}