CC=gcc
CFLAGS=-Wall -g
# IFLAGS=-I./
LDFLAGS=-L./
LDLIBS=-lstack

# USAGE:
# The code must be organized in the following way:
# - a driver program $(MAIN) which contains the main() function, and runs the desired tests
# - files $(SRC) and headers $(HDR) common to our solution and student submissions
# - file(s) $(FUNCTIONS) containing the functions required in the assignment
# 
# See examples below
#
# Use IFLAGS, LDFLAGS and LDLIBS as needed

# file with main() - driver for test program 
# - different test driver programs can be used by changing this var 

MAIN=test_reverse.c

# source files needed for all programs
# SRC=
# header files needed
HDR=stack.h reverse.h
# library files needed for all programs
LIBS=libstack.a
# source file with additional functions, either our solution or the student solution
FUNCTIONS=reverse.c 
TARGET=$(MAIN:.c=)-$(FUNCTIONS:.c=)

all: $(MAIN) $(SRC) $(HDR) $(FUNCTIONS) $(LIBS)
	$(CC) $(CFLAGS) -o $(TARGET) $(MAIN) $(SRC) $(FUNCTIONS) $(LDFLAGS) $(LDLIBS)

clean:
	rm $(TARGET)
