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
           int centerX, int centerY);

    void draw(Graphics& graphics);
    void setState(State state);

    void setWight(int wight) {
        inactiveBackground->setWight(wight);
        activeBackground->setWight(wight);
        text->setWight(wight);
    };

    void setHeight(int height) {
        inactiveBackground->setHeight(height);
        activeBackground->setHeight(height);
        text->setHeight(height);
    };

    virtual ~Button() = default;
private:
    std::unique_ptr<Object> inactiveBackground;
    std::unique_ptr<Object> activeBackground;
    std::unique_ptr<Object> text;
    State state = State::Inactive;
    int centerX;
    int centerY;
};

}
