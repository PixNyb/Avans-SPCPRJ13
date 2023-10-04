#include <SDL2/SDL.h>
#include <cstdlib>
#include <ctime>
#include <iostream>

int main(int argc, char *argv[]) {
  // Initialize SDL
  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
    return 1;
  }

  // Define the window size
  int windowWidth = 640;
  int windowHeight = 480;

  // Create a window and a renderer
  SDL_Window *window =
      SDL_CreateWindow("SDL Input", SDL_WINDOWPOS_CENTERED,
                       SDL_WINDOWPOS_CENTERED, windowWidth, windowHeight, 0);
  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

  // Define the size and position of the square
  int squareSize = 50;
  int squareX = (windowWidth - squareSize) / 2;
  int squareY = (windowHeight - squareSize) / 2;

  // Define the initial color of the square
  SDL_Color squareColor = {255, 255, 255, 255};

  // Seed the random number generator
  std::srand(std::time(nullptr));

  // Create a loop that listens for events
  bool quit = false;
  while (!quit) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
      switch (event.type) {
      case SDL_QUIT:
        quit = true;
        break;
      case SDL_KEYDOWN:
        switch (event.key.keysym.sym) {
        case SDLK_UP:
          squareY -= 10;
          break;
        case SDLK_DOWN:
          squareY += 10;
          break;
        case SDLK_LEFT:
          squareX -= 10;
          break;
        case SDLK_RIGHT:
          squareX += 10;
          break;
        case SDLK_SPACE:
          squareColor.r = std::rand() % 256;
          squareColor.g = std::rand() % 256;
          squareColor.b = std::rand() % 256;
          break;
        }
        break;
      }
    }

    // Clear the renderer and draw the square with the current color
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    SDL_SetRenderDrawColor(renderer, squareColor.r, squareColor.g,
                           squareColor.b, squareColor.a);
    SDL_Rect squareRect = {squareX, squareY, squareSize, squareSize};
    SDL_RenderFillRect(renderer, &squareRect);

    // Update the screen
    SDL_RenderPresent(renderer);
  }

  // Clean up and exit
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}