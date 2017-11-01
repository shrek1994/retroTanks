#pragma once

#include <vector>
#include "Object.hpp"
#include "Animation.hpp"

namespace GameView {

class AnimatedObject : public Object {
public:
    AnimatedObject(Graphics& graphics, const std::string& filePath, int sourceX, int sourceY, int width, int height,
                   int posX, int posY, double timeToUpdate);

    void playAnimation(Animation animation, bool once = false);

    virtual void update(int elapsedTime);

    void draw(Graphics &graphics, int x, int y);

    virtual void setupAnimations() = 0;
protected:
    double _timeToUpdate;
    bool _currentAnimationOnce;
    Animation _currentAnimation;

    void addAnimation(int frames,
                      int x, int y,
                      Animation animation,
                      int width, int height,
                      Offset offset = Offset{0,0});
    void resetAnimations();
    void stopAnimation();
    void setVisible(bool visible);
    virtual void animationDone(Animation currentAnimation) {};

private:
    std::map<Animation, std::vector<SDL_Rect> > _animations;
    std::map<Animation, Offset> _offsets;

    int _frameIndex;
    double _timeElapsed;
    bool _visible;
};

}