# ezsdl
Lightweight wrapper around SDL2 with Cartesian coordinate system

### Functions

Create window and renderer
```C
int create(int width, int height)
```

Destroy window and renderer
```C
void destroy()
```

Change the color
```C
void color(int r, int g, int b, int a)
```

Draw a line to the current buffer
```C
void line(int x1, int y1, int x2, int y2)
```

Delay for some time
```C
void delay(int ms)
```

Draw all contents to window
```C
void draw()
```

Clear current screen
```C
void clear()
```
