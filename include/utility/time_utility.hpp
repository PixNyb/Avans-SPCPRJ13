/**
 * @file TimeUtility.h
 * @author "Melvin van Bree"
 * @brief TODO
 * @version 0.1
 * @date 10/11/2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DEFUNBOBENGINE_TIMEUTILITY_H
#define DEFUNBOBENGINE_TIMEUTILITY_H

#include <SDL_timer.h>

class TimeUtility
{
  private:
    uint64_t startTime;   /// The time when the class started
    uint64_t prevTime;    /// The time of the previous frame
    uint64_t currentTime; /// The time of the current frame
    float deltaTime;      /// The time between the previous frame and the current frame

  public:
    TimeUtility() : startTime(0), prevTime(0), currentTime(0), deltaTime(0.0f) {}

    void StartFrame();

    /**
     * @brief Gets the current elapsed time since the start of the frame
     * @details This means the time from when this function was called, not the time from the start
     * of the frame
     * @return float The elapsed time in milliseconds
     */
    [[nodiscard]] float GetElapsedTimeSinceFrameStart() const;

    /**
     * @brief Gets the total time since the start of the timer
     * @return float The total time in seconds
     */
    [[nodiscard]] float GetTotalTime() const;

    /**
     * @brief Gets the time between the previous frame and the current frame
     * @return float The delta time in seconds
     */
    [[nodiscard]] float GetDeltaTime() const;
};

#endif // DEFUNBOBENGINE_TIMEUTILITY_H
