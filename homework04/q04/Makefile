Q=hw04q04
OBJS=$(Q:%=%.o)
LIBS=SDL2 SDL2_image SDL2_ttf p1world m
CFLAGS=-std=gnu99 -fdiagnostics-color


all : $(Q)


%.o :: %.c $(Q).h iotest.h
	gcc $(CFLAGS) -c -o $@ $<

$(Q) : $(OBJS)
	gcc -o $@ $^ $(LIBS:%=-l%)

clean :
	rm -f $(OBJS) $(Q)

.PHONY: all test clean
