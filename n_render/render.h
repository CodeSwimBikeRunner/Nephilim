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

/*
    * Initializes the renderer, set the height and width of the app here.
    */
RenderPtr render_init(const int height,const int width);
/*
    * This will handle the renderloop.
    ? Possible place for registering of all observables.
    ? just before this create all threads and observers, when there are no more observers exit?
    */
int render_loop(RenderPtr);

/*
    * This will handle shutting down SDL and closing the window.
    */
void render_quit(RenderPtr render);
