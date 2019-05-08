#include "ezsdl.h"
#include <SDL2/SDL.h>

int main(int argc, char* argv[])
{
    if( create(640, 480) != 0 )
    {
        return 1;
    }
    
    int len = 30;
    int delta_x = 0;
    int delta_y = 0;
    int move = 5;

	for(;;)
	{
		color(0, 0, 0, 255);
		clear();


        color(255, 0, 0, 255);

		line(len + delta_x,
             len + delta_y,
             -len + delta_x,
             -len + delta_y);

		line(-len + delta_x,
        len + delta_y,
        len + delta_x,
        -len + delta_y);

	    draw();
		//delay(50);
        
        switch( key() )
        {
            case LEFT:
                delta_x -= move;
                break;

            case RIGHT:
                delta_x += move;
                break;

            case UP:
                delta_y += move;
                break;

            case DOWN:
                delta_y -= move;
                break;
                
        }

        if( event() == QUIT )
        {
            break;
        }
	}

    destroy();
}

