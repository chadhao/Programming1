
# This is a generic makefile, intended to work without
# modification for most questions in Programming 1
# Author: James Skene
# Date: April 2014

# These variables define libraries to link
# and options for the compiler
LIBS=SDL2 SDL2_image SDL2_ttf p1world m
P1_RESOURCES=/usr/local/share/mesaclient/p1world
CFLAGS=-std=gnu99 -fdiagnostics-color -D'P1_RESOURCES="$(P1_RESOURCES)"'
TEST_CFLAGS=$(CFLAGS) -DTEST



# This bit works out what source files are present and
# divides them into those needed for the executable and
# those needed for testing
HEADERS=$(wildcard *.h)
SOURCES=$(wildcard *.c)

# Question sources do not include extra test sources
Q_SOURCES=$(filter-out %.test.c,$(SOURCES))
Q_OBJS=$(Q_SOURCES:%.c=%.o)
TEST_SOURCES=$(filter %.test.c,$(SOURCES))
TEST_OBJS_IMPL=$(Q_SOURCES:%.c=%.to)
TEST_OBJS_TEST=$(TEST_SOURCES:%.c=%.to)

# This bit figures out the name of the question by looking for
# source files with any of the standard names
HWS=$(wildcard hw??q??.c)
LABS=$(wildcard lab??ex??.c)
TESTS=$(wildcard test??q??.c)

# This removes the .c part from the question name
Q=$(basename $(HWS) $(LABS) $(TESTS))
Q_TEST=$(Q).test

# By default just build the executable
all : $(Q)

# Object files for test
%.to : %.c $(HEADERS)
	gcc $(TEST_CFLAGS) -c -o $@ $<

# Compile all sources into test objects, strip
# our main() from the implementation files then link
$(Q_TEST) : $(TEST_OBJS_IMPL) $(TEST_OBJS_TEST)
	strip -N main $(TEST_OBJS_IMPL)
	gcc -o $@ $^ $(LIBS:%=-l%)

# All object files depend on their source file and any headers
%.o : %.c $(HEADERS)
	gcc $(CFLAGS) -c -o $@ $<

# Question just depends on non-test object files
$(Q) : $(Q_OBJS)
	gcc -o $@ $^ $(LIBS:%=-l%)

test : $(Q_TEST)
	./$(Q_TEST)

clean:
	rm -f *.o *.to $(Q) $(Q_TEST)

.PHONY: all test clean

