#pragma once

#include "Object.hpp"

namespace Game {

class IndestructibleObject : public Object {
public:
    IndestructibleObject(Graphics& graphics, const std::string& filePath, int sourceX, int sourceY, int width,
                       int height, int centerX, int centerY);

    void update(int elapsedTime) override;
    bool shouldBeRemove() const override;
    void draw(Graphics& graphics) override;
    SDL_Rect getRectangle() const override;
private:
    double _centerX, _centerY;
};

}
