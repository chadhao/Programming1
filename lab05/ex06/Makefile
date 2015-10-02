Q=lab05ex06
OBJS=$(Q) p1image p1renderer
TEST_OBJS=$(Q)_test
LIBS=SDL2 SDL2_image SDL2_ttf m 
P1_RESOURCES=/usr/local/share/mesaclient/p1world
CFLAGS=-std=gnu99 -fdiagnostics-color -D'P1_RESOURCES="$(P1_RESOURCES)"'


all : $(Q)

%.c : p1image.h p1renderer.h

%.o : %.c
	gcc $(CFLAGS) -c -o $@ $<

$(Q) : $(OBJS:%=%.o)
	gcc -o $@  $^ $(LIBS:%=-l%)

clean :
	-rm $(OBJS:%=%.o) $(Q)

.PHONY: all test clean
