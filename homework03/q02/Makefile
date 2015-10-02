Q=hw03q02
OBJS=$(Q)
TEST_OBJS=$(Q)_test
LIBS=SDL2 SDL2_image SDL2_ttf p1world m
CFLAGS=-std=gnu99 -fdiagnostics-color

all : $(Q)_test

%.c : $(Q).h

%.o : %.c
	gcc $(CFLAGS) -c -o $@ $<

$(Q)_test : $(OBJS:%=%.o) $(TEST_OBJS:%=%.o)
	gcc -o $(Q)_test $^ $(LIBS:%=-l%)

test : $(Q)_test
	./$(Q)_test

clean :
	-rm $(OBJS:%=%.o) $(TEST_OBJS:%=%.o) $(Q)_test

.PHONY: all test clean
