/// @file

#ifndef DEFUNBOBENGINE_TIME_HPP
#define DEFUNBOBENGINE_TIME_HPP

/**
 * @brief Class representing game time.
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
