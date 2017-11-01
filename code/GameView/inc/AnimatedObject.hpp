#pragma once

#include <vector>
#include "Object.hpp"
#include "Direction.hpp"

namespace GameView {

class AnimatedObject : public Object {
public:
    AnimatedObject(Graphics& graphics, const std::string& filePath, int sourceX, int sourceY, int width, int height,
                   int posX, int posY, double timeToUpdate);

    void playAnimation(std::string animation, bool once = false);

    void update(int elapsedTime);

    void draw(Graphics &graphics, int x, int y);

    virtual void setupAnimations() {
        addAnimation(2, 0, 0, "Up", 56, 56, Offset{0, 0});
    };
protected:
    double _timeToUpdate;
    bool _currentAnimationOnce;
    std::string _currentAnimation;

    void addAnimation(int frames, int x, int y, std::string name, int width, int height, Offset offset);
    void resetAnimations();
    void stopAnimation();
    void setVisible(bool visible);
    virtual void animationDone(std::string currentAnimation) {
    };

private:
    std::map<std::string, std::vector<SDL_Rect> > _animations;
    std::map<std::string, Offset> _offsets;

    int _frameIndex;
    double _timeElapsed;
    bool _visible;
};

}