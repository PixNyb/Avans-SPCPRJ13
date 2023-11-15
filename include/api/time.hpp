/**
 * @file time.hpp
 * @author Robin Pijnappels
 * @version 0.1
 * @date 2023-11-12
 *
 * @brief Defines the Time class for managing game time in the DefunBobEngine.
 * The Time class provides static methods and properties to handle time-related functionalities,
 * such as tracking the delta time between frames and setting a global time scale.
 * This class is essential for managing animations, physics, and other time-dependent processes in games.
 *
 * @copyright Copyright (c) 2023
 */

#ifndef DEFUNBOBENGINE_TIME_HPP
#define DEFUNBOBENGINE_TIME_HPP

/**
 * @class Time
 * @brief Represents game time, providing static methods to access and manipulate it.
 *
 * The Time class offers functionalities related to game time, like getting the time elapsed
 * between frames (delta time) and controlling the rate at which time passes (time scale).
 */
class Time {
public:
    /**
     * @brief The interval in seconds from the last frame to the current one (Read Only)
     */
    static double DeltaTime();

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

private:
    static double deltaTime;
    static double timeScale;
};

#endif //DEFUNBOBENGINE_TIME_HPP
