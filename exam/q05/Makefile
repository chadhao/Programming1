
LIBS=SDL2 SDL2_image SDL2_ttf p1world m
CFLAGS=-std=gnu99 -fdiagnostics-color

all : q05

q05.o : q05.c
	gcc $(CFLAGS) -c -o $@ $<

q05 : q05.o
	gcc -o $@ $^ $(LIBS:%=-l%)

clean :
	rm -f q05 *.o

.PHONY: all clean

