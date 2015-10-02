
LIBS=SDL2 SDL2_image SDL2_ttf p1world m
CFLAGS=-std=gnu99 -fdiagnostics-color

all : q08

q08.o : q08.c
	gcc $(CFLAGS) -c -o $@ $<

q08 : q08.o
	gcc -o $@ $^ $(LIBS:%=-l%)

clean :
	rm -f q08 *.o

.PHONY: all clean

