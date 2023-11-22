/**
 * @file sdl_timer.hpp
 * @author Robin Pijnappels (rm.pijnappels@student.avans.nl)
 * @brief This file contains the Timer class definition.
 * @version 0.1
 * @date 2023-11-08
 *
 * The Timer class is used to create timing events within the game engine, such as
 * counting down to a game event, tracking how long an operation takes, or
 * managing in-game timers. It utilizes SDL's timing functions to provide accurate
 * timing functionality.
 *
 * This class is typically used to control game flow, animations, or time-dependent events.
 * It can measure elapsed time or count down from a set interval.
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DEFUNBOBENGINE_TIMER_HPP
#define DEFUNBOBENGINE_TIMER_HPP

#include <SDL.h>

/**
 * @class Timer
 * @brief Class for managing time-related events in the game engine.
 *
 * Timer offers start, stop, pause, and resume functionalities to manage time intervals.
 * It can be used to track elapsed time since a particular event or to create a countdown timer.
 */
class Timer
{
  private:
    Uint32 startTicks;  ///< The ticks at the moment the timer was started.
    Uint32 pausedTicks; ///< The ticks counted at the moment the timer was paused.
    bool paused;        ///< Timer pause state.
    bool started;       ///< Timer start state.

  public:
    /**
     * @brief Construct a new Timer object.
     *
     * Initializes the timer, setting all ticks counts to zero and the timer to not started or
     * paused.
     */
    Timer();

    /**
     * @brief Starts or restarts the timer.
     *
     * Records the current tick count and changes the timer's state to started.
     */
    void Start();

    /**
     * @brief Stops the timer.
     *
     * Clears the tick counts and changes the timer's state to not started.
     */
    void Stop();

    /**
     * @brief Pauses the timer if it is running.
     *
     * Records the current tick count for paused time and changes the timer's state to paused.
     */
    void Pause();

    /**
     * @brief Resumes the timer if it was paused.
     *
     * Adjusts the start ticks to account for the paused duration, effectively unpausing the timer.
     */
    void Unpause();

    /**
     * @brief Gets the timer's elapsed time in ticks.
     * @return Uint32 The number of ticks since the timer was started minus any paused duration.
     */
    Uint32 GetTicks() const;
};

#endif // DEFUNBOBENGINE_TIMER_HPP
