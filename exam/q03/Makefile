
LIBS=SDL2 SDL2_image SDL2_ttf p1world m
CFLAGS=-std=gnu99 -fdiagnostics-color

all : q03

q03.o : q03.c
	gcc $(CFLAGS) -c -o $@ $<

q03 : q03.o
	gcc -o $@ $^ $(LIBS:%=-l%)

clean :
	rm -f q03 *.o

.PHONY: all clean

