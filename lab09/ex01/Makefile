
Q=lab09ex01
OBJS=$(Q)
LIBS=
CFLAGS=-std=gnu99 -fdiagnostics-color

all : $(Q)

%.o : %.c
	gcc $(CFLAGS) -c -o $@ $<

$(Q) : $(OBJS:%=%.o) ;
	gcc -o $@ $^ $(LIBS:%=-l%)

clean:
	rm -f *.o $(Q)

.PHONY: all clean

