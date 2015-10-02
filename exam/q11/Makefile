
LIBS=SDL2 SDL2_image SDL2_ttf p1world m
CFLAGS=-std=gnu99 -fdiagnostics-color

all : q11

q11.o : q11.c
	gcc $(CFLAGS) -c -o $@ $<

q11 : q11.o
	gcc -o $@ $^ $(LIBS:%=-l%)

clean :
	rm -f q11 *.o

.PHONY: all clean

