#pragma once

#include <SDL2/SDL.h>
#include <string>

class Graphics;
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
    virtual bool shouldBeRemove() const = 0;
    virtual SDL_Rect getRectangle() const = 0;
    virtual void setDestroyed() {}
    virtual ~Object() = default;

    double getWight() const;
    double getHeight() const;
protected:
    virtual void draw(Graphics& graphics, double centerX, double centerY);

    SDL_Rect sourceRect;
    SDL_Texture* objectTexture;
};

}

bool operator==(const Game::Object& lhs, const Game::Object& rhs);
bool operator!=(const Game::Object& lhs, const Game::Object& rhs);
