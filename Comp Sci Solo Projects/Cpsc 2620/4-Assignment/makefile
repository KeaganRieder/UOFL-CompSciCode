# programs and their associated classes, if any
PROGRAM_NAME1 = testMatrixPro2
CLASS_NAME_1 = MatrixPro2
# CLASS_NAME_1_1 = 

PROGRAM_NAME2 = FreqCalc
# CLASS_NAME_2 = 


# Compiler information
CXX=g++
CXX_VERSION= -std=c++11
CXX_FLAGS= $(CXX_VERSION) -Wall -g

# files for the projects
HEADERS_1 = $(CLASS_NAME_1).h
OBJS_1 = $(CLASS_NAME_1).o $(PROGRAM_NAME1).o

# HEADERS_1_1 = $(CLASS_NAME_1_1).h
# OBJS_1_1 = $(CLASS_NAME_1_1).o $(PROGRAM_NAME1).o

# HEADERS_2 = $(CLASS_NAME_2).h
# OBJS_2 = $(CLASS_NAME_2).o $(PROGRAM_NAME2).o

# Default goal, used by Atom for local compilation
.DEFAULT_GOAL := all

clean:
	rm -rf *~ *.o

clean-all: clean
	rm -rf ${PROGRAM_NAME1} ${PROGRAM_NAME2}

%.o : %.cc
	$(CXX) -c $(CXX_FLAGS) $<

# Without a class
# $(PROGRAM_NAME1) :
#	$(CXX) $(CXX_FLAGS) -o $(PROGRAM_NAME1) $(PROGRAM_NAME1).cc

# With a class
$(PROGRAM_NAME1) : $(OBJS_1)
	$(CXX) $^ -o $@

# Without a class
$(PROGRAM_NAME2) :
	$(CXX) $(CXX_FLAGS) -o $(PROGRAM_NAME2) $(PROGRAM_NAME2).cc

# With a class
#$(PROGRAM_NAME2) : $(OBJS_2)
#	$(CXX) $^ -o $@

compile1: $(PROGRAM_NAME1)

compile2: $(PROGRAM_NAME2)

all: compile1 compile2
