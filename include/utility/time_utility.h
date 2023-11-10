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

class TimeUtility {
  private:
    uint64_t startTime;
    uint64_t prevTime;
    uint64_t currentTime;
    float deltaTime;

  public:
    TimeUtility() : startTime(0), prevTime(0), currentTime(0), deltaTime(0.0f) {}

    void StartFrame() {
        prevTime = currentTime;
        currentTime = SDL_GetPerformanceCounter();
        deltaTime = static_cast<float>(currentTime - prevTime) / SDL_GetPerformanceFrequency();
    }

    [[nodiscard]] float GetElapsedTimeSinceFrameStart() const {
        return (SDL_GetPerformanceCounter() - currentTime) / static_cast<float>(SDL_GetPerformanceFrequency()) * 1000.0f;
    }

    [[nodiscard]] float GetTotalTime() const {
        return static_cast<float>(currentTime - startTime) / SDL_GetPerformanceFrequency();
    }

    [[nodiscard]] float GetDeltaTime() const {
        return deltaTime;
    }
};

#endif // DEFUNBOBENGINE_TIMEUTILITY_H
