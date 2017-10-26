#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Graphics.hpp"

namespace GameView {

Graphics::Graphics() {
    SDL_CreateWindowAndRenderer(800, 600, 0, &_window, &_renderer);
    SDL_SetWindowTitle(_window, "Test");
}

Graphics::~Graphics() {
    SDL_DestroyWindow(_window);
    SDL_DestroyRenderer(_renderer);
}

SDL_Surface* Graphics::loadImage(const std::string& filePath) {
    if (_spriteSheets.count(filePath) == 0) {
        _spriteSheets[filePath] = IMG_Load(filePath.c_str());
    }
    return _spriteSheets[filePath];
}

void Graphics::blitSurface(SDL_Texture* texture, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle) {
    SDL_RenderCopy(_renderer, texture, sourceRectangle, destinationRectangle);
}

void Graphics::flip() {
    SDL_RenderPresent(_renderer);
}

void Graphics::clear() {
    SDL_RenderClear(_renderer);
}

SDL_Renderer* Graphics::getRenderer() const {
    return _renderer;
}

}
