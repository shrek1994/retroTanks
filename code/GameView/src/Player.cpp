#include "Player.hpp"

namespace GameView {


Player::Player(Graphics& graphics,
               const std::string& filePath,
               int sourceX,
               int sourceY,
               int width,
               int height,
               float posX,
               float posY,
               double timeToUpdate) :
        AnimatedObject(graphics,
                       filePath,
                       sourceX,
                       sourceY,
                       width,
                       height,
                       posX,
                       posY,
                       timeToUpdate)
{}

}