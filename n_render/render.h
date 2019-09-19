#pragma once

#include "../SDL2/include/SDL.h"
#include "../SDL2_image/include/SDL_image.h"
#include "stdio.h"

/*
    * A point in the drawing grid.
    * (0,0) is top left of window.
    */
typedef struct Point Point;
/*
    * this is the renderer.
    */
typedef struct Render * RenderPtr;
/*
    * Draws from the top left using the surface provided
    */
typedef void (*Draw)(Point, SDL_Surface);

RenderPtr render_init(const int height,const int width);
int render_loop(RenderPtr);
void render_quit(RenderPtr render);
