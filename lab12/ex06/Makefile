
# This is a generic makefile, intended to work without
# modification for most questions in Programming 1
# Author: James Skene
# Date: April 2014

# These variables define libraries to link
# and options for the compiler
LIBS=SDL2 SDL2_image SDL2_ttf p1world m
P1_RESOURCES=/usr/local/share/mesaclient/p1world
CFLAGS=-std=gnu99 -fdiagnostics-color -D'P1_RESOURCES="$(P1_RESOURCES)"'

# This bit works out what source files are present and
# divides them into those needed for the executable and
# those needed for testing
HEADERS=$(wildcard *.h)
SOURCES=$(wildcard *.c)

# Question sources do not include extra test sources
Q_SOURCES=$(filter-out %.test.c,$(SOURCES))
Q_OBJS=$(Q_SOURCES:%.c=%.o)


# By default just build the executable
all : life

# All object files depend on their source file and any headers
%.o : %.c $(HEADERS)
	gcc $(CFLAGS) -c -o $@ $<

# Question just depends on non-test object files
life : $(Q_OBJS)
	gcc -o $@ $^ $(LIBS:%=-l%)

clean:
	rm -f *.o life

.PHONY: all clean

