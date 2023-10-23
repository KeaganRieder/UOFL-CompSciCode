# programs and their associated classes
PROGRAM_NAME1 = testDictionary
CODE_FILE_1A = dictionary2

PROGRAM_NAME2 = testMatrix
CLASS_NAME_2A = Matrix


# Compiler information
CXX=g++
CXX_VERSION= -std=c++11
CXX_FLAGS= $(CXX_VERSION) -Wall -g

# files for the projects
HEADERS_1 = $(CODE_FILE_1A).h
OBJS_1 = $(CODE_FILE_1A).o $(PROGRAM_NAME1).o

HEADERS_2 = $(CLASS_NAME_2A).h
OBJS_2 = $(CLASS_NAME_2A).o $(PROGRAM_NAME2).o


# Default goal, used by Atom for local compilation
.DEFAULT_GOAL := all

clean:
	rm -rf *~ *.o

clean-all: clean
	rm -rf ${PROGRAM_NAME1} ${PROGRAM_NAME2}

%.o : %.cc
	$(CXX) -c $(CXX_FLAGS) $<

$(PROGRAM_NAME1) : $(OBJS_1)
	$(CXX) $^ -o $@

$(PROGRAM_NAME2) : $(OBJS_2)
	$(CXX) $^ -o $@

compile1: $(PROGRAM_NAME1)

compile2: $(PROGRAM_NAME2)

all: compile1 compile2
