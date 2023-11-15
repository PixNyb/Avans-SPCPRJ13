/// @file

#ifndef DEFUNBOBENGINE_TIME_HPP
#define DEFUNBOBENGINE_TIME_HPP

#include <SDL_timer.h>

class Time {
  private:
    static uint64_t startTime; /// The time when the class started
    static uint64_t prevTime; /// The time of the previous frame
    static uint64_t currentTime; /// The time of the current frame
    static double deltaTime; /// The time between the previous frame and the current frame
    static double timeScale; /// The time scale of the game

  public:
    static void StartFrame();

    /**
     * @brief Gets the current elapsed time since the start of the frame
     * @details This means the time from when this function was called, not the time from the start of the frame
     * @return float The elapsed time in milliseconds
     */
    [[nodiscard]] static double GetElapsedTimeSinceFrameStart();

    /**
     * @brief Gets the total time since the start of the timer
     * @return float The total time in seconds
     */
    [[nodiscard]] static double GetTotalTime();

    /**
     * @brief Gets the time between the previous frame and the current frame
     * @return float The delta time in seconds
     */
    [[nodiscard]] static double GetDeltaTime();

    /**
     * @brief The scale at which time passes.
     * @return time scale value
     */
    static double TimeScale();

    /**
     * @brief The scale at which time passes.
     * @param newTimeScale The new value for the time scale.
     */
    static void TimeScale(double newTimeScale);
};

#endif //DEFUNBOBENGINE_TIME_HPP
