#include <SDL2/SDL.h>
#include <cstdlib>
#include <ctime>
#include <iostream>

const int VELOCITY = 10;

int main(int argc, char *argv[]) {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
    return 1;
  }

  // Create a window and a renderer
  int windowWidth = 640;
  int windowHeight = 480;
  SDL_Window *window =
      SDL_CreateWindow("SDL Input", SDL_WINDOWPOS_CENTERED,
                       SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, 0);
  SDL_Renderer *renderer =
      SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

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
  SDL_SetRenderDrawColor(renderer, squareColor.r, squareColor.g, squareColor.b,
                         squareColor.a);

  // Create a loop that listens for events
  bool quit = false;
  bool isHovering = false;
  Uint32 lastBackgroundColorChangeTime = SDL_GetTicks();

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
          squareY -= VELOCITY;
          break;
        case SDLK_DOWN:
          squareY += VELOCITY;
          break;
        case SDLK_LEFT:
          squareX -= VELOCITY;
          break;
        case SDLK_RIGHT:
          squareX += VELOCITY;
          break;
        case SDLK_SPACE:
          squareColor.r = std::rand() % 256;
          squareColor.g = std::rand() % 256;
          squareColor.b = std::rand() % 256;
          previousSquareColor = squareColor;
          break;
        }
        break;
      case SDL_MOUSEBUTTONDOWN:
        squareX = event.button.x - squareSize / 2;
        squareY = event.button.y - squareSize / 2;
        break;
      case SDL_MOUSEMOTION:
        isHovering = (event.motion.x >= squareX &&
                      event.motion.x <= squareX + squareSize &&
                      event.motion.y >= squareY &&
                      event.motion.y <= squareY + squareSize);
        break;
      }
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
    SDL_Rect squareRect = {squareX, squareY, squareSize, squareSize};
    SDL_RenderFillRect(renderer, &squareRect);

    SDL_RenderPresent(renderer);
    SDL_Delay(1);
  }

  // Clean up and exit
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}