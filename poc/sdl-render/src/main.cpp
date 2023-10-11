#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Renderer.hpp"
#include "Spritesheet.hpp"

int main(int argc, char *args[]) {
  int windowWidth = 800;
  int windowHeight = 600;

  // Initialiseer SDL
  if (SDL_Init(SDL_INIT_VIDEO) < 0) {
    return 1;
  }

  // Initialiseer SDL_image
  if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG)) {
    return 1;
  }

  Renderer renderer(800, 600);

  SDL_Surface *bgSurface = IMG_Load("../assets/indianaBob.png");
  if (bgSurface == nullptr) {
    SDL_Log("Unable to load image: %s", IMG_GetError());
    return 1;
  }

  SDL_Texture *bgTexture =
      SDL_CreateTextureFromSurface(renderer.getSDLRenderer(), bgSurface);
  SDL_FreeSurface(bgSurface);

  if (bgTexture == nullptr) {
    SDL_Log("Unable to create texture: %s", SDL_GetError());
    return 1;
  }

  // Game loop
  bool quit = false;
  SDL_Event e;
  while (!quit) {
    while (SDL_PollEvent(&e) != 0) {
      if (e.type == SDL_QUIT) {
        quit = true;
      }
    }

    renderer.clear();

    renderer.drawImage(bgTexture, 0, 0, windowWidth, windowHeight);
    renderer.drawRectangle(50, 50, 100, 100);
    renderer.drawCircle(400, 300, 50);

    renderer.present();
    SDL_Delay(500); // Vertraging toegevoegd om de animatie te kunnen zien
  }

  SDL_DestroyTexture(bgTexture);

  IMG_Quit();
  SDL_Quit();

  return 0;
}