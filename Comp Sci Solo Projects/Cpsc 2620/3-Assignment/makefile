# programs and their associated classes
PROGRAM_NAME1 = testMatrixExt
CLASS_NAME_1 = MatrixExt

PROGRAM_NAME2 = testMatrixPro
CLASS_NAME_2 = MatrixPro


# Compiler information
CXX=g++
CXX_VERSION= -std=c++11
CXX_FLAGS= $(CXX_VERSION) -Wall -g

# files for the projects
HEADERS_1 = $(CLASS_NAME_1).h
OBJS_1 = $(CLASS_NAME_1).o $(PROGRAM_NAME1).o

HEADERS_2 = $(CLASS_NAME_2).h
OBJS_2 = $(CLASS_NAME_2).o $(PROGRAM_NAME2).o


# Default goal
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
