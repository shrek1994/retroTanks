#include <SDL_timer.h>
#include <Constants.hpp>
#include "Menu.hpp"
#include "Input.hpp"
#include "Graphics.hpp"
#include "StartGameButton.hpp"
#include "OptionsButton.hpp"

namespace Menu {

Menu::Menu(std::shared_ptr<Graphics> graphics,
            std::shared_ptr<Input> input)
            : graphics(std::move(graphics)),
            input(std::move(input)) {}

void Menu::init() {
    buttons.push_back(std::make_unique<StartGameButton>(*graphics, WINDOW_WIGHT / 2, 1.5 * BUTTON_HEIGHT));
    buttons.push_back(std::make_unique<OptionsButton>(*graphics, WINDOW_WIGHT / 2, 3.5 * BUTTON_HEIGHT));
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

    for (auto& button : buttons) {
        button->draw(graphics);
    }

    graphics.flip();
}



}