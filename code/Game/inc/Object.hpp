#pragma once

#include <SDL2/SDL.h>
#include <string>

namespace Game {
class Graphics;

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

    double getWight();
    double getHeight();

protected:
    virtual void draw(Graphics& graphics, int centerX, int centerY);

    SDL_Rect _sourceRect;
    SDL_Texture* _objectTexture;
};


}