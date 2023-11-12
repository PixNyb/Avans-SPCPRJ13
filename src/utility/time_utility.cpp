/**
 * @file time_utility.cpp
 * @author "Melvin van Bree"
 * @brief Time utility is used to get time related information in the game loop
 * @version 0.1
 * @date 10/11/2023
 *
 * @copyright Copyright (c) 2023
 *
 */

#include "time_utility.hpp"
#include "performance_utility.hpp"

float TimeUtility::GetTotalTime() const
{
    return static_cast<float>(currentTime - startTime) /
           static_cast<float>(PerformanceUtility::GetPerformanceFrequency());
}

float TimeUtility::GetElapsedTimeSinceFrameStart() const
{
    return static_cast<float>(PerformanceUtility::GetPerformanceCounter() - currentTime) /
           static_cast<float>(PerformanceUtility::GetPerformanceFrequency()) * 1000.0f;
}

float TimeUtility::GetDeltaTime() const { return deltaTime; }

void TimeUtility::StartFrame()
{
    prevTime = currentTime;
    currentTime = PerformanceUtility::GetPerformanceCounter();
    deltaTime = static_cast<float>(currentTime - prevTime) /
                static_cast<float>(PerformanceUtility::GetPerformanceFrequency());
}
