#include <SDL2/SDL.h>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

const int VELOCITY = 1;
std::vector<int> fpsCounts;

int main(int argc, char *argv[])
{
    // Initialize SDL
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Create a window and a renderer
    int windowWidth = 640;
    int windowHeight = 480;
    SDL_Window *window = SDL_CreateWindow("SDL Input", SDL_WINDOWPOS_CENTERED,
                                          SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    // Define the size and position of the square
    int squareSize = 50;
    int squareX = (windowWidth - squareSize) / 2;
    int squareY = (windowHeight - squareSize) / 2;

    // Define the initial color of the square
    SDL_Color squareColor = {255, 255, 255, 255};
    SDL_Color previousSquareColor = squareColor;
    SDL_Color backgroundColor = {0, 0, 0, 255};

    // Seed the random number generator
    std::srand(std::time(nullptr));

    // Set the renderer draw color
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_SetRenderDrawColor(renderer, squareColor.r, squareColor.g, squareColor.b, squareColor.a);

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

    while (!quit)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
            case SDL_QUIT:
                quit = true;
                break;
            case SDL_KEYDOWN:
                switch (event.key.keysym.sym)
                {
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
                    squareColor.r = std::rand() % 256;
                    squareColor.g = std::rand() % 256;
                    squareColor.b = std::rand() % 256;
                    previousSquareColor = squareColor;
                    break;
                }
                break;
            case SDL_KEYUP:
                switch (event.key.keysym.sym)
                {
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
                squareX = event.button.x - squareSize / 2;
                squareY = event.button.y - squareSize / 2;
                break;
            case SDL_MOUSEMOTION:
                isHovering = (event.motion.x >= squareX && event.motion.x <= squareX + squareSize &&
                              event.motion.y >= squareY && event.motion.y <= squareY + squareSize);
                break;
            }
        }

        // Change the background color every 0.1 seconds if the mouse is hovering
        // over the square
        Uint32 currentTime = SDL_GetTicks();
        if (isHovering && currentTime - lastBackgroundColorChangeTime >= 100)
        {
            backgroundColor.r = std::rand() % 256;
            backgroundColor.g = std::rand() % 256;
            backgroundColor.b = std::rand() % 256;
            squareColor = {0, 0, 0, 255};
            lastBackgroundColorChangeTime = currentTime;
        }
        else if (!isHovering)
        {
            squareColor = previousSquareColor;
            backgroundColor = {0, 0, 0, 255};
        }
        SDL_SetRenderDrawColor(renderer, backgroundColor.r, backgroundColor.g, backgroundColor.b,
                               backgroundColor.a);
        SDL_RenderClear(renderer);

        // Update the position of the square based on the arrow key state
        if (arrowKeys[0])
        {
            squareY -= VELOCITY;
        }
        if (arrowKeys[1])
        {
            squareY += VELOCITY;
        }
        if (arrowKeys[2])
        {
            squareX -= VELOCITY;
        }
        if (arrowKeys[3])
        {
            squareX += VELOCITY;
        }

        // Draw the square with the current color
        SDL_SetRenderDrawColor(renderer, squareColor.r, squareColor.g, squareColor.b,
                               squareColor.a);
        SDL_Rect squareRect = {squareX, squareY, squareSize, squareSize};
        SDL_RenderFillRect(renderer, &squareRect);

        // Update the fps counter
        frameCount++;
        Uint32 currentFrameTime = SDL_GetTicks();
        if (currentFrameTime - lastFrameTime >= 1000)
        {
            fps = frameCount;
            frameCount = 0;
            lastFrameTime = currentFrameTime;
        }

        // Log the FPS every 5 seconds
        static Uint32 lastFpsLogTime = SDL_GetTicks();
        static Uint32 lastFpsStoreTime = SDL_GetTicks();

        if (currentFrameTime - lastFpsStoreTime >= 1000)
        {
            if (currentFrameTime - lastFpsLogTime >= 5000)
            {
                std::cout << "FPS: " << fps << std::endl;
                lastFpsLogTime = currentFrameTime;
            }

            fpsCounts.push_back(fps);
            lastFpsStoreTime = currentFrameTime;
        }

        SDL_RenderPresent(renderer);
        SDL_Delay(1);
    }

    // Log the average FPS, add up all the FPS counts and divide by the number of
    // counts
    int fpsTotal = 0;
    for (int fpsCount : fpsCounts)
    {
        fpsTotal += fpsCount;
    }
    std::cout << "Average FPS: " << fpsTotal / fpsCounts.size() << std::endl;

    // Clean up and exit
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}