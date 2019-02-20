C      = /Library/Developer/CommandLineTools/usr/bin/clang
CPP    = /Library/Developer/CommandLineTools/usr/bin/clang++
CFLAGS = -std=c++14 -Wall -Wextra -Weverything -Wno-c++98-compat

# GCC compiler ------------------------------------------------#
# CPP   = /usr/local/opt/gcc/bin/g++-8
# CPP   = /usr/local/opt/gcc/bin/c++-8
# CPP   = /usr/local/opt/gcc/bin/cpp-8
# CFLAGS = -std=c++14 -Wall -Wextra -Wpedantic -pedantic-errors
# GCC compiler ------------------------------------------------#

VERB   = -v
DEBUG  = -g
RM     = /bin/rm -f

SRCS   = *.cpp
OBJS   = $(subst .cpp,.o,($SRCS)
TARGET = parseLas


all: $(SRCS)
	$(CPP) $(CFLAGS) $(SRCS) -o $(TARGET)

debug: *.c
	$(CPP) $(CFLAGS) $(DEBUG) $(SRCS) -o $(TARGET)

verbose: *.c
	$(CPP) $(CFLAGS) $(VERB) $(SRCS) -o $(TARGET)

.PHONEY: clean
clean:
	$(RM) $(TARGET)
