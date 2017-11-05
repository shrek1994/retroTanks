#pragma once

#include <vector>
#include "Object.hpp"
#include "Animation.hpp"

namespace Game {

class AnimatedObject : public Object {
public:
    AnimatedObject(Graphics& graphics,
                   const std::string& filePath,
                   int sourceX, int sourceY,
                   int width, int height,
                   double timeToUpdate);

    virtual void setupAnimations() = 0;

    void playAnimation(Animation animation, bool once = false);
    virtual void update(int elapsedTime);
    void draw(Graphics &graphics, int x, int y);

protected:
    double _timeToUpdate;
    bool _currentAnimationOnce;
    Animation _currentAnimation;

    void addAnimation(int frames,
                      int x, int y,
                      Animation animation,
                      int width, int height,
                      SDL_Point offset = SDL_Point{0,0});

    void resetAnimations();
    void stopAnimation();
    void setVisible(bool visible);
    virtual void animationDone(Animation currentAnimation) {};

private:
    std::map<Animation, std::vector<SDL_Rect> > _animations;
    std::map<Animation, SDL_Point> _offsets;

    int _frameIndex;
    double _timeElapsed = 0;
    bool _visible;
};

}