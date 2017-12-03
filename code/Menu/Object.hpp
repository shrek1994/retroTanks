#pragma once

#include <SDL2/SDL.h>
#include <string>

class Graphics;

namespace Menu {

class Object {
public:
    Object(Graphics& graphics,
           const std::string& filePath,
           int sourceX,
           int sourceY,
           int width,
           int height);

    void draw(Graphics& graphics, int centerX, int centerY);

    void setWight(int wight) {this->wight = wight;};
    void setHeight(int height) {this->height = height;};

    virtual ~Object() = default;
protected:
    SDL_Rect sourceRect;
    SDL_Texture* objectTexture;

    int wight;
    int height;
};

}