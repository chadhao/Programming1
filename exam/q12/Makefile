
LIBS=SDL2 SDL2_image SDL2_ttf p1world m
CFLAGS=-std=gnu99 -fdiagnostics-color

all : q12

q12.o : q12.c
	gcc $(CFLAGS) -c -o $@ $<

q12 : q12.o
	gcc -o $@ $^ $(LIBS:%=-l%)

clean :
	rm -f q12 *.o

.PHONY: all clean

