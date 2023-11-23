/**
 * @file time.hpp
 * @author Robin Pijnappels
 * @version 0.1
 * @date 2023-11-12
 *
 * @brief Defines the Time class for managing game time in the DefunBobEngine.
 * The Time class provides static methods and properties to handle time-related functionalities,
 * such as tracking the delta time between frames and setting a global time scale.
 * This class is essential for managing animations, physics, and other time-dependent processes in
 * games.
 *
 * @copyright Copyright (c) 2023
 */

#ifndef DEFUNBOBENGINE_TIME_HPP
#define DEFUNBOBENGINE_TIME_HPP

#include <cstdint>

/**
 * @class Time
 * @brief Represents game time, providing static methods to access and manipulate it.
 *
 * The Time class offers functionalities related to game time, like getting the time elapsed
 * between frames (delta time) and controlling the rate at which time passes (time scale).
 */
class Time
{
  private:
    static uint64_t startTime;   ///< The time when the class started
    static uint64_t prevTime;    ///< The time of the previous frame
    static uint64_t currentTime; ///< The time of the current frame
    static double deltaTime;     ///< The time between the previous frame and the current frame
    static double timeScale;     ///< The time scale of the game

  public:
    static void StartFrame();

    /**
     * @brief Gets the current elapsed time since the start of the frame
     * @details This means the time from when this function was called, not the time from the start
     * of the frame
     * @return The elapsed time in milliseconds
     */
    [[nodiscard]] static double GetElapsedTimeSinceFrameStart();

    /**
     * @brief Gets the total time since the start of the timer
     * @return The total time in seconds
     */
    [[nodiscard]] static double GetTotalTime();

    /**
     * @brief Gets the time between the previous frame and the current frame
     * @return The delta time in seconds
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

#endif // DEFUNBOBENGINE_TIME_HPP
