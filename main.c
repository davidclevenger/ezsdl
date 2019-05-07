#include "ezsdl.h"
#include <SDL2/SDL.h>

int main(int argc, char* argv[])
{
    if( create(640, 480) != 0 )
    {
        return 1;
    }

	for(int i = 0; i < 100; i++)
	{
		color(0, 0, 0, 255);
		clear();

		color(255, 0, 0, 255);
		line(i, 0, i+30, 30);
		draw();
		delay(50);
	}
}

