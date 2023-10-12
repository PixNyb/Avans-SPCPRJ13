#pragma once

#include <algorithm>
#include "SDL_scancode.h"

namespace InputManager {
    // Function declarations
    void poll();
    bool wasKeyPressed(SDL_Scancode key);
    bool wasKeyReleased(SDL_Scancode key);
    bool wasMouseButtonPressed(Uint8 button);
    bool wasMouseButtonReleased(Uint8 button);
    bool hasQuit();
}