
LIBS=SDL2 SDL2_image SDL2_ttf p1world m
CFLAGS=-std=gnu99 -fdiagnostics-color

all : q09

q09.o : q09.c
	gcc $(CFLAGS) -c -o $@ $<

q09 : q09.o
	gcc -o $@ $^ $(LIBS:%=-l%)

clean :
	rm -f q09 *.o

.PHONY: all clean

