
# These variables define libraries to link
# and options for the compiler
LIBS=SDL2 SDL2_image SDL2_ttf p1world m
CFLAGS=-std=gnu99 -fdiagnostics-color -D'P1_RESOURCES=$(P1_RESOURCES)'



all : experiment

experiment.o : experiment.c
	gcc $(CFLAGS) -c -o experiment.o experiment.c

experiment : experiment.o
    gcc -o experiment experiment.o$(LIBS:%=-l%)


clean:
	rm -f *.o experiment

.PHONY: all clean

