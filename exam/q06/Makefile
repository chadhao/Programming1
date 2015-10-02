LIBS=SDL2 SDL2_image SDL2_ttf p1world m
CFLAGS=-std=gnu99 -fdiagnostics-color

all : q06_test

%.c : $(Q).h

%.o : %.c
	gcc $(CFLAGS) -c -o $@ $<

q06_test : q06.o q06_test.o
	gcc -o $@ $^ $(LIBS:%=-l%)

test : q06_test
	./q06_test

clean :
	rm -f q06_test *.o

.PHONY: all test clean
