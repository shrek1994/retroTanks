#include "StartGameButton.hpp"
#include "InactiveBackground.hpp"
#include "ActiveBackground.hpp"

namespace Menu {

StartGameButton::StartGameButton(Graphics& graphics, int centerX, int centerY) :
        Button(std::make_unique<InactiveBackground>(graphics),
               std::make_unique<ActiveBackground>(graphics),
               std::make_unique<Object>(graphics, "res/menu/startGame.png", 0, 0, 389, 78),
               centerX, centerY)
    {
        setHeight(BUTTON_HEIGHT);
        setWight(BUTTON_WEIGHT);
    }

}