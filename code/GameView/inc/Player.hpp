#pragma once

#include <string>
#include "Graphics.hpp"

namespace GameView {

class Player {
public:
    Player(Graphics& graphics,
           const std::string& filePath,
           int sourceX,
           int sourceY,
           int width,
           int height,
           float posX,
           float posY);

    virtual void draw(Graphics &graphics, int x, int y);
    virtual void update();
    virtual ~Player() = default;
private:
    SDL_Rect _sourceRect;
    SDL_Texture* _playerSheet;

    float _x, _y;
};


}