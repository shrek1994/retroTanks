#pragma once

#include <SDL2/SDL.h>
#include <map>

class Input {
public:
    void beginNewFrame();

    bool wasKeyPressed(SDL_Scancode key);
    bool wasKeyReleased(SDL_Scancode key);
    bool isKeyHeld(SDL_Scancode key);

    bool isGameTerminated();
private:
    void keyUpEvent(const SDL_Event& event);
    void keyDownEvent(const SDL_Event& event);

    std::map<SDL_Scancode, bool> _heldKeys;
    std::map<SDL_Scancode, bool> _pressedKeys;
    std::map<SDL_Scancode, bool> _releasedKeys;

    SDL_Event _event;
};
