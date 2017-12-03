#include <debug.hpp>
#include "Game.hpp"
#include "Config.hpp"
#include "Menu.hpp"

int main() {
    using Menu::MenuChoice;
    using Menu::Menu;
    using Game::Game;

    auto graphics = std::make_shared<Graphics>();
    auto input = std::make_shared<Input>();

    MenuChoice choice;
    do
    {
        choice = Menu(graphics, input).start();
        switch (choice) {
            case MenuChoice::StartGame:
                Game(graphics, input).start();
                break;
            case MenuChoice::Options:
                ERROR << "Not implemented yet !\n";
                break;
            case MenuChoice::Stats:
                ERROR << "Not implemented yet !\n";
                break;
            default:
                break;
        }
    } while (choice != MenuChoice::Quit);
    return EXIT_SUCCESS;
}
