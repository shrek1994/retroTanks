#pragma once

#include <AnimatedObject.hpp>

namespace GameView {

class Player : public AnimatedObject {
public:
    Player(Graphics& graphics, const std::string& filePath, int sourceX, int sourceY, int width, int height, float posX,
           float posY, double timeToUpdate);
};


}