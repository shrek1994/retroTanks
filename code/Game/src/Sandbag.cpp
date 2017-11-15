#include "Sandbag.hpp"

namespace Game {

Sandbag::Sandbag(Graphics& graphics, int centerX, int centerY)
        : Object(graphics, "res/sandbag.png", 0, 0, 66, 33),
          _centerX(centerX), _centerY(centerY)
{}

void Sandbag::draw(Graphics& graphics) {
    Object::draw(graphics, _centerX, _centerY);
}

void Sandbag::update(int ) {

}

bool Sandbag::shouldBeRemove() const {
    return false;
}

SDL_Rect Sandbag::getRectangle() const {
    return SDL_Rect{static_cast<int>(_centerX - getWight() / 2),
                    static_cast<int>(_centerY - getHeight() / 2),
                    static_cast<int>(getWight()),
                    static_cast<int>(getHeight())};
}


}