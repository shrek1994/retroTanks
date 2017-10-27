#pragma once

#include <vector>
#include "Object.hpp"
#include "Direction.hpp"

namespace GameView {

class AnimatedObject : public Object {
public:
    AnimatedObject(Graphics& graphics, const std::string& filePath, int sourceX, int sourceY, int width, int height,
                   int posX, int posY, double timeToUpdate);

    /* void playAnimation
     * Plays the animation provided if it's not already playing
     */
    void playAnimation(std::string animation, bool once = false);

    /* void update
     * Updates the animated sprite (timer)
     */
    void update(int elapsedTime);

    /* void draw
     * Draws the sprite to the screen
     */
    void draw(Graphics &graphics, int x, int y);

    /* void setupAnimations
     * A required function that sets up all animations for a sprite
     */
    virtual void setupAnimations() {
        addAnimation(2, 0, 0, "Up", 56, 56, Offset{0, 0});
    };
protected:
    double _timeToUpdate;
    bool _currentAnimationOnce;
    std::string _currentAnimation;

    /* void addAnimation
     * Adds an animation to the map of animations for the sprite
     */
    void addAnimation(int frames, int x, int y, std::string name, int width, int height, Offset offset);

    /* void resetAnimations
     * Resets all animations associated with this sprite
     */
    void resetAnimations();

    /* void stopAnimation
     * Stops the current animation
     */
    void stopAnimation();

    /* void setVisible
     * Changes the visibility of the animated sprite
     */
    void setVisible(bool visible);

    /* void animationDone
     * Logic that happens when an animation ends
     */
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