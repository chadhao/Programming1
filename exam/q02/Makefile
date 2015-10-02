
LIBS=SDL2 SDL2_image SDL2_ttf p1world m
CFLAGS=-std=gnu99 -fdiagnostics-color

all : q02

q02.o : q02.c
	gcc $(CFLAGS) -c -o $@ $<

q02 : q02.o
	gcc -o $@ $^ $(LIBS:%=-l%)

clean :
	rm -f q02 *.o

.PHONY: all clean

