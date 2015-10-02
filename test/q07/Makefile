
Q=test01q07
OBJS=$(Q)
LIBS=SDL2 SDL2_image SDL2_ttf p1world m
CFLAGS=-std=gnu99 -fdiagnostics-color

all : $(Q)

%.o : %.c
	gcc $(CFLAGS) -c -o $@ $<

$(Q) : $(OBJS:%=%.o) ;
	gcc -o $@ $^ $(LIBS:%=-l%)

clean:
	rm -f *.o $(Q)

.PHONY: all clean

