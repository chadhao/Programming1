
LIBS=SDL2 SDL2_image SDL2_ttf p1world m
CFLAGS=-std=gnu99 -fdiagnostics-color

all : q10

q10.o : q10.c
	gcc $(CFLAGS) -c -o $@ $<

q10 : q10.o
	gcc -o $@ $^ $(LIBS:%=-l%)

clean :
	rm -f q10 *.o

.PHONY: all clean

