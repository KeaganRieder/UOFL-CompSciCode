# Makefile for one program stored in one file
# assign the variable PROGRAM_NAME to desired program name
PROGRAM1_NAME = dp
PROGRAM2_NAME = greedy
SOURCE1 = Dp
SOURCE2 = Greedy

# Compiler information
CC=g++
CC_VERSION= -std=c++11
CC_FLAGS= $(CC_VERSION) -Wall

# Default goal, used by Atom for local compilation
.DEFAULT_GOAL := all

# compilation targets
all: ${PROGRAM1_NAME} ${PROGRAM2_NAME}

${PROGRAM1_NAME}: ${SOURCE1}.cc
	$(CC) $(CC_FLAGS) -o $@ $^

${PROGRAM2_NAME}: ${SOURCE2}.cc
	$(CC) $(CC_FLAGS) -o $@ $^

clean:
	rm -rf ???*~ *.o

clean-all: clean
	rm -rf ${PROGRAM1_NAME}
	rm -rf ${PROGRAM2_NAME}


