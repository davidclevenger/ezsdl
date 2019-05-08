#ifndef __EZSDL_H
#define __EZSDL_H

typedef enum
{
    EVENT_NONE = 0,
    QUIT = 1
} Event;

typedef enum
{
    KEY_NONE = 0,
    LEFT = 1,
    RIGHT = 2,
    UP = 3,
    DOWN = 4
} Key;

/* window */
int create(int, int);
void destroy();

/* rendering */
void color(int, int, int, int);
void line(int, int, int, int);
void draw();
void clear();

/* user input */
Event event();
Key key();

/* misc */
void delay(int);

#endif

