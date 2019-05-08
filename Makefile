CC=gcc
CFLAGS=-g
AR=ar
ARFLAGS=rcs
SDLFLAGS = $(shell sdl2-config --libs --cflags)
EZFLAGS =-L. -lezsdl

default: main

main: main.c lib
	$(CC) $(CFLAGS) main.c -o main $(EZFLAGS) $(SDLFLAGS)

lib:
	$(CC) $(CFLAGS) -c ezsdl.c $(SDLFLAGS)
	$(AR) $(ARFLAGS) libezsdl.a ezsdl.o


install: lib
	cp ezsdl.h /usr/local/inlude/
	cp libezsdl.a /usr/lib/
    
uninstall: x
	rm -f /usr/local/include/ezsdl.h
	rm -f /usr/lib/libezsdl.a

.PHONY:
clean:
	rm -f *.o *.a main
