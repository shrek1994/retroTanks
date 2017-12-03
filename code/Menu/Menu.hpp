#pragma once

#include <memory>

class Graphics;
class Input;
namespace Menu {

enum class MenuChoice {
    StartGame,
    Options,
    Stats,
    Quit
};

class Menu {
public:
    Menu(std::shared_ptr<Graphics> graphics,
         std::shared_ptr<Input> input);

    MenuChoice start();
    void init();
private:

    void draw(Graphics& graphics);


    std::shared_ptr<Graphics> graphics;
    std::shared_ptr<Input> input;
};

}
