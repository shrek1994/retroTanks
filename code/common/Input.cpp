#include "Input.hpp"

void Input::beginNewFrame() {
    _pressedKeys.clear();
    _releasedKeys.clear();

    if (SDL_PollEvent(&_event)) {
        if (_event.type == SDL_KEYDOWN && _event.key.repeat == 0) {
            keyDownEvent(_event);
        } else if (_event.type == SDL_KEYUP) {
            keyUpEvent(_event);
        }
    }
}

void Input::keyDownEvent(const SDL_Event& event) {
    _pressedKeys[event.key.keysym.scancode] = true;
    _heldKeys[event.key.keysym.scancode] = true;
}

void Input::keyUpEvent(const SDL_Event& event) {
    _releasedKeys[event.key.keysym.scancode] = true;
    _heldKeys[event.key.keysym.scancode] = false;
}

bool Input::wasKeyPressed(SDL_Scancode key) {
    return _pressedKeys[key];
}

bool Input::wasKeyReleased(SDL_Scancode key) {
    return _releasedKeys[key];
}

bool Input::isKeyHeld(SDL_Scancode key) {
    return _heldKeys[key];
}

bool Input::isGameTerminated() {
    return _event.type != SDL_QUIT;
}
