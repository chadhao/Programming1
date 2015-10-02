LIBS=SDL2 SDL2_image SDL2_ttf p1world m
CFLAGS=-std=gnu99 -fdiagnostics-color

all : q04_test

%.c : $(Q).h

%.o : %.c
	gcc $(CFLAGS) -c -o $@ $<

q04_test : q04.o q04_test.o
	gcc -o $@ $^ $(LIBS:%=-l%)

test : q04_test
	./q04_test

clean :
	rm -f q04_test *.o

.PHONY: all test clean
