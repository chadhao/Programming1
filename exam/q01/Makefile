
LIBS=SDL2 SDL2_image SDL2_ttf p1world m
CFLAGS=-std=gnu99 -fdiagnostics-color

all : q01

q01.o : q01.c
	gcc $(CFLAGS) -c -o $@ $<

q01 : q01.o
	gcc -o $@ $^ $(LIBS:%=-l%)

clean :
	rm -f q01 *.o

.PHONY: all clean

