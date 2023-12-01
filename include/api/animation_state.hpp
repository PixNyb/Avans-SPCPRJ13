/**
 * @file animation_state.hpp
 * @author Roël Couwenberg (contact@roelc.me)
 * @brief This file contains the AnimationState class definition.
 * @version 0.1
 * @date 2023-11-16
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef AVANS_SPCPRJ13_ANIMATIONSTATE_H
#define AVANS_SPCPRJ13_ANIMATIONSTATE_H

#include <map>
#include <string>

/**
 * @class AnimationState
 * @brief Manages the states of an animation.
 *
 * This class is responsible for handling different states of an animation.
 * It maintains a map of states and provides functionalities to update
 * the animation based on the current state.
 */
class AnimationState
{
  private:
    std::map<std::string, AnimationState> states; ///< Map of animation states.

    int startFrameIndex;   ///< The index of the first frame of the animation.
    int endFrameIndex;     ///< The index of the last frame of the animation.
    float frameDuration;   ///< The duration of a single frame of the animation.
    int currentFrameIndex; ///< The index of the current frame of the animation.
    float elapsedTime;     ///< The time elapsed since the start of the animation.

  public:
    /**
     * @brief Constructs a new AnimationState object.
     *
     * Initializes a new instance of the AnimationState class.
     */
    AnimationState();

    /**
     * @brief Constructs a new AnimationState object.
     *
     * Initializes a new instance of the AnimationState class with the specified
     * parameters.
     *
     * @param startFrameIndex The index of the first frame of the animation.
     * @param endFrameIndex The index of the last frame of the animation.
     * @param frameDuration The duration of a single frame of the animation.
     */
    AnimationState(int startFrameIndex, int endFrameIndex, float frameDuration)
        : startFrameIndex(startFrameIndex), endFrameIndex(endFrameIndex),
          frameDuration(frameDuration), currentFrameIndex(startFrameIndex), elapsedTime(0)
    {
    }

    /**
     * @brief Updates the animation state.
     *
     * This function updates the state of an animation based on the current state
     * and the elapsed time.
     *
     * @param deltaTime The time elapsed since the last frame.
     */
    void Update(float deltaTime);

    /**
     * @brief Gets the current frame index.
     *
     * This function returns the current frame index of the animation.
     *
     * @return int The current frame index.
     */
    [[nodiscard]] int GetCurrentFrameIndex() const;

    /**
     * @brief Gets the total duration of the animation.
     *
     * This function returns the total duration of the animation.
     *
     * @return float The total duration of the animation.
     */
    [[nodiscard]] float GetTotalDuration() const;
};

#endif // AVANS_SPCPRJ13_ANIMATIONSTATE_H
