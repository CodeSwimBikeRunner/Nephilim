#include "../render.h"

struct Render {
    SDL_Window *window;
} Render;

RenderPtr render_init(const int height,const int width)
{
  struct Render * my_render = malloc(sizeof(Render));
  SDL_Init(SDL_INIT_VIDEO);

  SDL_Window *window = SDL_CreateWindow(
    "Nephilim",
    SDL_WINDOWPOS_UNDEFINED,
    SDL_WINDOWPOS_UNDEFINED,
    height,
    width,
    0
  );

  SDL_Surface* surface = IMG_Load("design.png");
  if(!surface)
  {
    const char * error = IMG_GetError();
    printf("Image failed to load: %s\n", error);
  }
  SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_SOFTWARE);
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
  
  SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, surface);
  SDL_FreeSurface(surface);
  
  SDL_RenderClear(renderer);
  SDL_RenderCopy(renderer, texture, NULL, NULL);
  SDL_RenderPresent(renderer);

  my_render->window = window;
  return my_render;
}

int render_loop(RenderPtr render)
{
  SDL_Delay(5000);
}

void render_quit(RenderPtr render)
{
    SDL_DestroyWindow(render->window);
    SDL_Quit();
}