#pragma once

#include <common/Constants.hpp>
#include "Button.hpp"

namespace Menu {

class StartGameButton : public Button {
public:
    StartGameButton(Graphics& graphics, int centerX, int centerY);
};

}
