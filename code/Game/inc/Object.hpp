#pragma once

#include <string>
#include "Graphics.hpp"

namespace Game {

class Object {
public:
    Object(Graphics& graphics,
           const std::string& filePath,
           int sourceX,
           int sourceY,
           int width,
           int height,
           int posX,
           int posY);

    virtual void draw(Graphics &graphics, int x, int y);
    virtual void update();
    virtual ~Object() = default;
protected:
    SDL_Rect _sourceRect;
    SDL_Texture* _objectSheet;

    int _x, _y;
};


}