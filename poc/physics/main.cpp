#include <SDL.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

float verticalVelocity = 0.0f;
const float GRAVITY = 0.05f;
const float JUMP_STRENGTH = -4.0f;
const float BOUNCE_STRENGTH = -5.0f;
const float VELOCITY = 1.0f;
const float DAMPING_FACTOR = 0.9f;

std::vector<int> fpsCounts;
int windowWidth = 640;
int windowHeight = 480;

float squareSize = 50;
SDL_FRect squareRect = {static_cast<float>((windowWidth - squareSize) / 2),
                        static_cast<float>((windowHeight - squareSize) / 2),
                        static_cast<float>(squareSize),
                        static_cast<float>(squareSize)};

SDL_FRect floorRect = {0.0f,
                       static_cast<float>(windowHeight - 10),
                       static_cast<float>(windowWidth),
                       10.0f};

void bounceRect() {
    verticalVelocity = -verticalVelocity * DAMPING_FACTOR;
}

void jumpRect() {
    verticalVelocity = JUMP_STRENGTH;
}

bool checkCol(SDL_FRect rect1, SDL_FRect rect2) {
    return rect1.x < rect2.x + rect2.w &&
           rect1.x + rect1.w > rect2.x &&
           rect1.y < rect2.y + rect2.h &&
           rect1.y + rect1.h > rect2.y;
}

int main(int argc, char *argv[]) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Create a window and a renderer

    SDL_Window *window =
            SDL_CreateWindow("SDL Input", SDL_WINDOWPOS_CENTERED,
                             SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, 0);
    SDL_Renderer *renderer =
            SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Define the initial color of the square
    SDL_Color squareColor = {255, 255, 255, 255};
    SDL_Color previousSquareColor = squareColor;
    SDL_Color backgroundColor = {0, 0, 0, 255};

    // Seed the random number generator
    std::srand(std::time(nullptr));

    // Set the renderer draw color
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_SetRenderDrawColor(renderer, squareColor.r, squareColor.g, squareColor.b,
                           squareColor.a);

    // Create a loop that listens for events
    bool quit = false;
    bool isHovering = false;
    Uint32 lastBackgroundColorChangeTime = SDL_GetTicks();

    // Initialize the arrow key state array
    bool arrowKeys[4] = {false, false, false, false};

    // Initialize the fps counter variables
    Uint32 lastFrameTime = SDL_GetTicks();
    int frameCount = 0;
    int fps = 0;

    while (!quit) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    quit = true;
                    break;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym) {
                        case SDLK_ESCAPE:
                            quit = true;
                            break;
                        case SDLK_UP:
                            arrowKeys[0] = true;
                            break;
                        case SDLK_DOWN:
                            arrowKeys[1] = true;
                            break;
                        case SDLK_LEFT:
                            arrowKeys[2] = true;
                            break;
                        case SDLK_RIGHT:
                            arrowKeys[3] = true;
                            break;
                        case SDLK_SPACE:
                            if (event.key.keysym.mod & KMOD_SHIFT) {
                                jumpRect();
                            } else {
                                squareColor.r = std::rand() % 256;
                                squareColor.g = std::rand() % 256;
                                squareColor.b = std::rand() % 256;
                                previousSquareColor = squareColor;
                            }
                            break;
                    }
                    break;
                case SDL_KEYUP:
                    switch (event.key.keysym.sym) {
                        case SDLK_UP:
                            arrowKeys[0] = false;
                            break;
                        case SDLK_DOWN:
                            arrowKeys[1] = false;
                            break;
                        case SDLK_LEFT:
                            arrowKeys[2] = false;
                            break;
                        case SDLK_RIGHT:
                            arrowKeys[3] = false;
                            break;
                    }
                    break;
                case SDL_MOUSEBUTTONDOWN:
                    squareRect.x = event.button.x - squareSize / 2;
                    squareRect.y = event.button.y - squareSize / 2;
                    break;
                case SDL_MOUSEMOTION:
                    isHovering = (event.motion.x >= squareRect.x &&
                                  event.motion.x <= squareRect.x + squareSize &&
                                  event.motion.y >= squareRect.y &&
                                  event.motion.y <= squareRect.y + squareSize);
                    break;
            }
        }

        // Apply gravity
        verticalVelocity += GRAVITY;

        // Update the square's vertical position
        squareRect.y += verticalVelocity;

        // Check for collision with the floor
        if (checkCol(squareRect, floorRect)) {
            squareRect.y = floorRect.y - squareRect.h; // Reset the y position to the top of the floor
            bounceRect();                              // Make it bounce
        }

        // Change the background color every 0.1 seconds if the mouse is hovering
        // over the square
        Uint32 currentTime = SDL_GetTicks();
        if (isHovering && currentTime - lastBackgroundColorChangeTime >= 100) {
            backgroundColor.r = std::rand() % 256;
            backgroundColor.g = std::rand() % 256;
            backgroundColor.b = std::rand() % 256;
            squareColor = {0, 0, 0, 255};
            lastBackgroundColorChangeTime = currentTime;
        } else if (!isHovering) {
            squareColor = previousSquareColor;
            backgroundColor = {0, 0, 0, 255};
        }
        SDL_SetRenderDrawColor(renderer, backgroundColor.r, backgroundColor.g,
                               backgroundColor.b, backgroundColor.a);
        SDL_RenderClear(renderer);

        // Draw the square with the current color
        SDL_SetRenderDrawColor(renderer, squareColor.r, squareColor.g,
                               squareColor.b, squareColor.a);

        SDL_RenderFillRectF(renderer, &squareRect);
        SDL_RenderFillRectF(renderer, &floorRect);

        // Update the position of the square based on the arrow key state
        if (arrowKeys[0]) {
            jumpRect();
        }
        if (arrowKeys[1]) {
            if (!checkCol(squareRect, floorRect)) {
                squareRect.y += VELOCITY;
            }
        }
        if (arrowKeys[2]) {
            squareRect.x -= VELOCITY;
        }
        if (arrowKeys[3]) {
            squareRect.x += VELOCITY;
        }

        if (!checkCol(squareRect, floorRect)) {
            squareRect.y += VELOCITY;
        }

        // Update the fps counter
        frameCount++;
        Uint32 currentFrameTime = SDL_GetTicks();
        if (currentFrameTime - lastFrameTime >= 1000) {
            fps = frameCount;
            frameCount = 0;
            lastFrameTime = currentFrameTime;
        }

        // Log the FPS every 5 seconds
        static Uint32 lastFpsLogTime = SDL_GetTicks();
        static Uint32 lastFpsStoreTime = SDL_GetTicks();

        if (currentFrameTime - lastFpsStoreTime >= 1000) {
            if (currentFrameTime - lastFpsLogTime >= 5000) {
                std::cout << "FPS: " << fps << std::endl;
                lastFpsLogTime = currentFrameTime;
            }

            fpsCounts.push_back(fps);
            lastFpsStoreTime = currentFrameTime;
        }

        SDL_RenderPresent(renderer);
        SDL_Delay(2);
    }

    // Log the average FPS, add up all the FPS counts and divide by the number of
    // counts
    int fpsTotal = 0;
    for (int fpsCount: fpsCounts) {
        fpsTotal += fpsCount;
    }
    std::cout << "Average FPS: " << fpsTotal / fpsCounts.size() << std::endl;

    // Clean up and exit
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}