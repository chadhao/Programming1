
Q=lab05ex04
OBJS=$(Q)
TEST_OBJS=test$(Q)
LIBS=
CFLAGS=-std=gnu99 -fdiagnostics-color

all : $(Q)

%.o : %.c
	gcc $(CFLAGS) -c -o $@ $<

$(Q) : $(OBJS:%=%.o) ;
	gcc -o $@ $^ $(LIBS:%=-l%)

clean:
	-rm *.o $(Q)

.PHONY: all clean

