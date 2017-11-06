#include "debug.hpp"
#include "AnimatedObject.hpp"
#include "Graphics.hpp"

namespace Game {

AnimatedObject::AnimatedObject(Graphics& graphics,
                               const std::string& filePath,
                               int sourceX,
                               int sourceY,
                               int width,
                               int height,
                               double timeToUpdate) :
        Object(graphics,
               filePath,
               sourceX,
               sourceY,
               width,
               height),
        _timeToUpdate(timeToUpdate),
        _currentAnimationOnce(false),
        _currentAnimation(Animation::IdleUp),
        _frameIndex(0),
        _visible(true)

{}


void AnimatedObject::addAnimation(int frames,
                                  int x,
                                  int y,
                                  Animation animation,
                                  int width,
                                  int height,
                                  SDL_Point offset) {
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

void AnimatedObject::draw(Graphics &graphics, int centerX, int centerY) {
    if (_visible) {
        SDL_Rect destinationRectangle = {static_cast<int>(centerX - getWight() / 2),
                                         static_cast<int>(centerY - getHeight() / 2),
                                         static_cast<int>(getWight()),
                                         static_cast<int>(getHeight())};

        if (static_cast<int>(_currentAnimation) > 8 || _frameIndex < 0)
        {
            //TODO repair it !
            ERROR << "SEGMENTATION FAULT REASON: _currentAnimation has invalid value: " << _currentAnimation << ", "
                  << "or_frameIndex has invalid value: " << _frameIndex << "\n";
        }

        SDL_Rect sourceRect = _animations[_currentAnimation][_frameIndex];
        graphics.render(_objectTexture, &sourceRect, &destinationRectangle);
    }
}

bool AnimatedObject::isVisible() {
    return _visible;
}

}