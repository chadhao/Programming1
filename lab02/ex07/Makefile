
Q=lab02ex07
OBJS=$(Q)
TEST_OBJS=test$(Q)
LIBS=SDL2 SDL2_image SDL2_ttf p1world m
CFLAGS=-std=gnu99 -fdiagnostics-color

all : $(Q)

%.o : %.c
	gcc $(CFLAGS) -c -o $@ $<

$(Q) : $(OBJS:%=%.o) ;
	gcc -o $@ $^ $(LIBS:%=-l%)

.PHONY: all test clean

