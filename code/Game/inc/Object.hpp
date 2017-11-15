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
    virtual bool shouldBeRemove() const = 0;
    virtual SDL_Rect getRectangle() const = 0;
    virtual ~Object() = default;

    double getWight() const;
    double getHeight() const;
protected:
    virtual void draw(Graphics& graphics, double centerX, double centerY);

    SDL_Rect _sourceRect;
    SDL_Texture* _objectTexture;
};

bool operator==(const Object& lhs, const Object& rhs);
}