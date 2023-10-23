# Makefile for one program stored in one file
# assign the variable PROGRAM_NAME to desired program name
PROGRAM_NAME = dictionary1

# Compiler information
CC=g++
CC_VERSION= -std=c++11
CC_FLAGS= $(CC_VERSION) -Wall

# Default goal, used by Atom for local compilation
.DEFAULT_GOAL := all

# compilation targets
all: ${PROGRAM_NAME}

${PROGRAM_NAME}: ${PROGRAM_NAME}.cc
	$(CC) $(CC_FLAGS) -o $@ $^

clean:
	rm -rf ???*~ *.o

clean-all: clean
	rm -rf ${PROGRAM_NAME}
