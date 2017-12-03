#include <SDL_timer.h>
#include <Constants.hpp>
#include "Menu.hpp"
#include "Input.hpp"
#include "Graphics.hpp"

namespace Menu {

Menu::Menu(std::shared_ptr<Graphics> graphics,
            std::shared_ptr<Input> input)
            : graphics(std::move(graphics)),
            input(std::move(input)) {}

void Menu::init() {

}

MenuChoice Menu::start() {
    init();
    auto lastUpdateTime = SDL_GetTicks();
    do {
        input->beginNewFrame();
        if (!input->isGameTerminated()) return MenuChoice::Quit;

        auto currentTimeMs = SDL_GetTicks();
        auto elapsedTimeMs = currentTimeMs - lastUpdateTime;
        auto sleepMs = MAX_FRAME_TIME - elapsedTimeMs > MAX_FRAME_TIME ? 0 : MAX_FRAME_TIME - elapsedTimeMs;
        SDL_Delay(sleepMs);

        draw(*graphics);

        lastUpdateTime = currentTimeMs;

    } while (!input->wasKeyPressed(SDL_SCANCODE_RETURN));

    return MenuChoice::StartGame;
}

void Menu::draw(Graphics& graphics) {
    graphics.clear();

    graphics.flip();
}



}