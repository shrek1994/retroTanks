#pragma once

#include <vector>
#include "Object.hpp"
#include "Direction.hpp"

namespace GameView {

class AnimatedObject : public Object {
public:
    AnimatedObject(Graphics& graphics, const std::string& filePath, int sourceX, int sourceY, int width, int height,
                   int posX, int posY, double timeToUpdate);

    void playAnimation(Direction direction, bool once = false);

    void update(int elapsedTime);

    void draw(Graphics &graphics, int x, int y);

    virtual void setupAnimations() = 0;
protected:
    double _timeToUpdate;
    bool _currentAnimationOnce;
    Direction _currentAnimation;

    void addAnimation(int frames,
                      int x, int y,
                      Direction direction,
                      int width, int height,
                      Offset offset = Offset{0,0});
    void resetAnimations();
    void stopAnimation();
    void setVisible(bool visible);
    virtual void animationDone(Direction currentDirection) {};

private:
    std::map<Direction, std::vector<SDL_Rect> > _animations;
    std::map<Direction, Offset> _offsets;

    int _frameIndex;
    double _timeElapsed;
    bool _visible;
};

}