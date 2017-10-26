#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "Graphics.hpp"

namespace GameView {

Graphics::Graphics() {
    SDL_CreateWindowAndRenderer(800, 600, 0, &this->_window, &this->_renderer);
    SDL_SetWindowTitle(this->_window, "Test");
}

Graphics::~Graphics() {
    SDL_DestroyWindow(this->_window);
    SDL_DestroyRenderer(this->_renderer);
}

SDL_Surface* Graphics::loadImage(const std::string& filePath) {
    if (this->_spriteSheets.count(filePath) == 0) {
        this->_spriteSheets[filePath] = IMG_Load(filePath.c_str());
    }
    return this->_spriteSheets[filePath];
}

void Graphics::blitSurface(SDL_Texture* texture, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle) {
    SDL_RenderCopy(this->_renderer, texture, sourceRectangle, destinationRectangle);
}

void Graphics::flip() {
    SDL_RenderPresent(this->_renderer);
}

void Graphics::clear() {
    SDL_RenderClear(this->_renderer);
}

SDL_Renderer* Graphics::getRenderer() const {
    return this->_renderer;
}

}