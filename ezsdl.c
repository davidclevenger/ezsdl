#include <stdlib.h>
#include <SDL2/SDL.h>
#include "ezsdl.h"

struct context
{
    int init;
    int width;
    int height;
    SDL_Window* window;
    SDL_Renderer* renderer;
};

static struct context Context;

int
create(int width, int height)
{
    Context.init = 0;
    Context.width = width;
    Context.height = height;
    Context.window = NULL;
    Context.renderer = NULL;

    if( SDL_CreateWindowAndRenderer(width, height, 0, &Context.window, &Context.renderer) != 0 )
        return 1;

    Context.init = 1;
    return 0;
}

void 
destroy()
{
    if( Context.init == 1)
    {
        SDL_DestroyRenderer(Context.renderer);
        SDL_DestroyWindow(Context.window);
    }
}

void color(int r, int g, int b, int a)
{
    SDL_SetRenderDrawColor(Context.renderer, r, g, b, a);
}

void line(int x1, int x2, int y1, int y2)
{
    SDL_RenderDrawLine(Context.renderer, x1, x2, y1, y2);
}

void delay(int ms)
{
    SDL_Delay(ms);
}

void draw()
{
    SDL_RenderPresent(Context.renderer);
}

void clear()
{
    SDL_RenderClear(Context.renderer);
}
