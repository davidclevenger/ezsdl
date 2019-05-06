#include "ezsdl.h"

int main(int argc, char* argv[])
{
    if( create(640, 480) != 0 )
    {
        return 1;
    }

    color(60, 0, 60, 255);
    line(5,25, 10,30);
    draw();

    delay(2000);
    destroy();
}

