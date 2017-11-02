#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <Animation.hpp>

#include "Graphics.hpp"
#include "debug.hpp"

namespace GameView {

Graphics::Graphics() {
    auto result = SDL_CreateWindowAndRenderer(WINDOW_WIGTH, WINDOW_HEIGTH, 0, &_window, &_renderer);
    if (result){
        ERROR << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        std::exit(EXIT_FAILURE);
    }

    SDL_SetWindowTitle(_window, "Test");
}

Graphics::~Graphics() {
    SDL_DestroyWindow(_window);
    SDL_DestroyRenderer(_renderer);
}

SDL_Surface* Graphics::loadImage(const std::string& filePath) {
    if (_imageSheets.count(filePath) == 0) {
        _imageSheets[filePath] = IMG_Load(filePath.c_str());
    }
    return _imageSheets[filePath];
}

void Graphics::render(SDL_Texture* texture, SDL_Rect* sourceRectangle, SDL_Rect* destinationRectangle) {
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
