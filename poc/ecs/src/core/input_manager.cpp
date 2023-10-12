#include <vector>
#include <algorithm>
#include "SDL_scancode.h"
#include "SDL_events.h"
#include "input_manager.h"

namespace InputManager {
    // Member variables
    static bool quit = false;
    static std::vector<Uint8> mouseButtonsDown;
    static std::vector<Uint8> mouseButtonsUp;
    static std::vector<SDL_Scancode> keysDown;
    static std::vector<SDL_Scancode> keysUp;
    static std::pair<int, int> mousePos = {0, 0};
    static std::pair<int, int> mouseDeltaPos = {0, 0};

    void poll() {
        mouseButtonsDown.clear();
        mouseButtonsUp.clear();
        keysDown.clear();
        keysUp.clear();
        mouseDeltaPos.first = 0;
        mouseDeltaPos.second = 0;

        SDL_Event event;

        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    quit = true;
                    break;
                case SDL_MOUSEMOTION:
                {
                    std::pair<int, int> mousePrevPos = mousePos;
                    mousePos.first = event.motion.x;
                    mousePos.second = event.motion.y;
                    mouseDeltaPos.first = mousePos.first - mousePrevPos.first;
                    mouseDeltaPos.second = mousePos.second - mousePrevPos.second;
                }
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    mouseButtonsDown.push_back(event.button.button);
                    break;
                case SDL_MOUSEBUTTONUP:
                    mouseButtonsUp.push_back(event.button.button);
                    break;
                case SDL_KEYDOWN:
                    keysDown.push_back(event.key.keysym.scancode);
                    break;
                case SDL_KEYUP:
                    keysUp.push_back(event.key.keysym.scancode);
                    break;
            }
        }
    }

    bool wasKeyPressed(SDL_Scancode key) {
        return std::find(keysDown.begin(), keysDown.end(), key) != keysDown.end();
    }

    bool wasKeyReleased(SDL_Scancode key) {
        return std::find(keysUp.begin(), keysUp.end(), key) != keysUp.end();
    }

    bool wasMouseButtonPressed(Uint8 button) {
        return std::find(mouseButtonsDown.begin(), mouseButtonsDown.end(), button) != mouseButtonsDown.end();
    }

    bool wasMouseButtonReleased(Uint8 button) {
        return std::find(mouseButtonsUp.begin(), mouseButtonsUp.end(), button) != mouseButtonsUp.end();
    }

    bool hasQuit(){
        return quit;
    }
}