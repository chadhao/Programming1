# No suffix rules
.SUFFIXES:
# Include configuration
# Source directory
SRCDIR := .

# Compilation details
CC := gcc
CXX := g++
OPTIMIZE := -g -O2
WARNING := 
CFLAGS := $(OPTIMIZE) $(WARNING) -g -O2 -fstack-protector-strong -Wformat -Werror=format-security -D_FORTIFY_SOURCE=2
LDFLAGS := -Wl,-z,relro
FGETLN_DEFS := 
GETLOADAVG_DEFS := 
STRLCPY_DEFS := 
GETPROGNAME_DEFS := 
NCURSES_LIB := -lncurses
NCURSES_INCS := 
OPENSSL_LIB := 
OPENSSL_INCS := 
BASE_INCS := -Iinclude $(NCURSES_INCS) $(OPENSSL_INCS)
BASE_LIBS := 
YACC := bison -y
LEX := flex
LEX_LIB := -lfl


.PHONY:	all 
all:	 adventure

data.c:	glorkz setup
	./setup $< >$@

%.o:	%.c
	$(CC) $(CFLAGS) $(BASE_INCS) -c $< -o $@

%.d:	%.c
	./mkdep $< $@ $(CC) $(CFLAGS) $(BASE_INCS)

include setup.d crc.d data.d done.d init.d io.d main.d save.d subr.d vocab.d wizard.d

setup:	 setup.o
	$(CC) $(LDFLAGS) $^  $(BASE_LIBS) -o $@

adventure:	 crc.o data.o done.o init.o io.o main.o save.o subr.o vocab.o wizard.o
	$(CC) $(LDFLAGS) $^  $(BASE_LIBS) -o $@


.PHONY: clean
clean:
	rm -f adventure setup *.d *.o data.c