
LIBS=SDL2 SDL2_image SDL2_ttf p1world m
CFLAGS=-std=gnu99 -fdiagnostics-color

all : q07

q07.o : q07.c
	gcc $(CFLAGS) -c -o $@ $<

q07 : q07.o
	gcc -o $@ $^ $(LIBS:%=-l%)

clean :
	rm -f q07 *.o

.PHONY: all clean

