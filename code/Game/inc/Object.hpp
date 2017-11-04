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
           int height);

    virtual void draw(Graphics& graphics) = 0;
    virtual void update(int elapsedTime) = 0;
    virtual ~Object() = default;

protected:
    virtual void draw(Graphics& graphics, int x, int y);

    SDL_Rect _sourceRect;
    SDL_Texture* _objectSheet;
};


}