#include "../SDL2/include/SDL.h"
#include "../SDL2_image/include/SDL_image.h"
#include "stdio.h"
#include "stdlib.h"

int main(int argc, const char *argv[])
{
  SDL_Init(SDL_INIT_VIDEO);

  SDL_Window *window = SDL_CreateWindow(
    "Nephilim",
    SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED,
    640,
    640,
    0
  );

  SDL_Surface* surface = IMG_Load("design.png");
  if(!surface)
  {
    const char * error = IMG_GetError();
    printf("IMG_Load(): %s\n", error);
  }
  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
  
  SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
  SDL_FreeSurface(surface);
  
  SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer, texture, NULL, NULL);
  SDL_RenderPresent(renderer);

  SDL_Delay(3000);

  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}