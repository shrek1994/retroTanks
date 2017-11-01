#include "AnimatedObject.hpp"

namespace GameView {

AnimatedObject::AnimatedObject(Graphics& graphics,
                               const std::string& filePath,
                               int sourceX,
                               int sourceY,
                               int width,
                               int height,
                               int posX,
                               int posY,
                               double timeToUpdate) :
        Object(graphics,
               filePath,
               sourceX,
               sourceY,
               width,
               height,
               posX,
               posY),
        _timeToUpdate(timeToUpdate),
        _visible(true)
{}


void AnimatedObject::addAnimation(int frames,
                                  int x,
                                  int y,
                                  Animation animation,
                                  int width,
                                  int height,
                                  Offset offset) {
    std::vector<SDL_Rect> rectangles;
    for (int i = 0; i < frames; i++) {
        SDL_Rect newRect = { (i + x) * width, y, width, height };
        rectangles.push_back(newRect);
    }
    _animations.insert({animation, rectangles});
    _offsets.insert({animation, offset});
}

void AnimatedObject::resetAnimations() {
    _animations.clear();
    _offsets.clear();
}

void AnimatedObject::playAnimation(Animation animation, bool once) {
    _currentAnimationOnce = once;
    if (_currentAnimation != animation) {
        _currentAnimation = animation;
        _frameIndex = 0;
    }
}

void AnimatedObject::setVisible(bool visible) {
    _visible = visible;
}

void AnimatedObject::stopAnimation() {
    _frameIndex = 0;
    animationDone(_currentAnimation);
}

void AnimatedObject::update(int elapsedTime) {
    Object::update();

    _timeElapsed += elapsedTime;
    if (_timeElapsed > _timeToUpdate) {
        _timeElapsed -= _timeToUpdate;
        if (_frameIndex < _animations[_currentAnimation].size() - 1) {
            _frameIndex++;
        }
        else {
            if (_currentAnimationOnce) {
                setVisible(false);
            }
            stopAnimation();
        }
    }
}

void AnimatedObject::draw(Graphics &graphics, int x, int y) {
    if (_visible) {
        SDL_Rect destinationRectangle;
        destinationRectangle.x = x + _offsets[_currentAnimation].x;
        destinationRectangle.y = y + _offsets[_currentAnimation].y;
        destinationRectangle.w = _sourceRect.w;
        destinationRectangle.h = _sourceRect.h;

        SDL_Rect sourceRect = _animations[_currentAnimation][_frameIndex];
        graphics.render(_objectSheet, &sourceRect, &destinationRectangle);
    }
}

}