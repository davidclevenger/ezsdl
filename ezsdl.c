#include <stdlib.h>
#include <SDL2/SDL.h>
#include "ezsdl.h"

static void process_x(int*);
static void process_y(int*);

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

	if( SDL_Init(SDL_INIT_EVERYTHING) != 0 )
	{
		return 1;
	}

    if( SDL_CreateWindowAndRenderer(width, height, SDL_WINDOW_RESIZABLE , &Context.window, &Context.renderer) != 0 )
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

	SDL_Quit();
}

void
color(int r, int g, int b, int a)
{
    SDL_SetRenderDrawColor(Context.renderer, r, g, b, a);
}

void
line(int x1, int y1, int x2, int y2)
{
	process_x(&x1);
	process_x(&x2);
	process_y(&y1);
	process_y(&y2);

    SDL_RenderDrawLine(Context.renderer, x1, y1, x2, y2);
}

void
delay(int ms)
{
    SDL_Delay(ms);
}

void
draw()
{
    SDL_RenderPresent(Context.renderer);
}

void
clear()
{
    SDL_RenderClear(Context.renderer);
}

Event
event()
{
    SDL_Event e;
    SDL_PollEvent(&e);
        
    if( e.type == SDL_QUIT )
    {
        return QUIT;
    }

    return EVENT_NONE;
}

Key
key()
{
    SDL_Event e;
    SDL_PollEvent(&e);
        
    if( e.type == SDL_KEYDOWN )
    {
        switch( e.key.keysym.sym )
        {
            case SDLK_LEFT:
                return LEFT;
            case SDLK_RIGHT:
                return RIGHT;
            case SDLK_UP:
                return UP;
            case SDLK_DOWN:
                return DOWN;
        }
    }

    return KEY_NONE;
}

void
process_x(int* x)
{
	*x = *x + (Context.width / 2);

	if( *x < 0 )
	{
		*x = 0;
	}
	else if( *x > Context.width )
	{
		*x = Context.width;
	}
}

void
process_y(int* y)
{
	*y = (Context.height / 2) - (*y); 

	if( *y < 0 )
	{
		*y = 0;
	}
	else if( *y > Context.height )
	{
		*y = Context.height;
	}
}

