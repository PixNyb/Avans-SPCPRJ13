/**
 * @file performance_utility.h
 * @author "Melvin van Bree"
 * @brief A utility class for performance related functions
 * @version 0.1
 * @date 11/11/2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef DEFUNBOBENGINE_PERFORMANCE_UTILITY_HPP
#define DEFUNBOBENGINE_PERFORMANCE_UTILITY_HPP

#include <SDL_timer.h>

/**
 * @brief Encapsulates SDL_GetPerformanceCounter and SDL_GetPerformanceFrequency
 */
class PerformanceUtility {
  public:
    /**
     * @brief Gets the current performance counter
     * @details This is used to get a more precise performance indicator. It is usually multiplied by the frequency to get the time in seconds.
     * @return uint64_t The current performance counter
     */
    static uint64_t GetPerformanceCounter() {
        return SDL_GetPerformanceCounter();
    }

    /**
     * @brief Gets the performance frequency. The amount of counter ticks per second.
     * @details This is used to get a more precise performance indicator. It is usually multiplied by the counter to get the time in seconds.
     * @return uint64_t The performance frequency
     */
    static uint64_t GetPerformanceFrequency() {
        return SDL_GetPerformanceFrequency();
    }
};

#endif // DEFUNBOBENGINE_PERFORMANCE_UTILITY_HPP
