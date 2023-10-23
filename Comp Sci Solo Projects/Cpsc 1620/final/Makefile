# Names of all required programs,
# change prog1, prog2, prog3 to desired program names
PROGRAM_NAME1 = final
PROGRAM_NAME2 =
PROGRAM_NAME3 =

# Compiler information
CXX=g++
CXX_VERSION= -std=c++11
CXX_FLAGS= $(CXX_VERSION) -Wall

# Default goal, used by Atom for local compilation
.DEFAULT_GOAL := compileAll

# compilation targets
compile1:
	$(CXX) $(CXX_FLAGS) -o $(PROGRAM_NAME1) $(PROGRAM_NAME1).cc

compile2:
#	$(CXX) $(CXX_FLAGS) -o $(PROGRAM_NAME2) $(PROGRAM_NAME2).cc

compile3:
#	$(CXX) $(CXX_FLAGS) -o $(PROGRAM_NAME3) $(PROGRAM_NAME3).cc

compileAll: compile1 compile2 compile3

# test targets
# For marking purposes, the instructor can, where appropriate,
# provide a URL for a file that may be changed after the due date
# to fresh test data. This file is available when the pipeline
# activates but will not be added to the student's project/repo.

# START OF TEST1
#     uncomment the test you wish to use
#   replace the URL with the address of the file
test1: compile1
#   No input from standard input test
		echo final.in | $(PROGRAM_NAME1)

#   No input from standard input but get remote file that the program will read (and replace local file)
#     replace "q1test.txt" with the appropriate file name
#     NOTE: the q1test.txt file in the repo will remain unchanged the files are created in a temp
#     directory while the pipeline runs
#	rm q1test.txt
#	wget http://gitlab.cs.uleth.ca/myFabDataRepo/-/raw/master/q1test.txt
#	$(PROGRAM_NAME1)

#   Display and pipe to get standard input from this command line
#   echo 125 | $(PROGRAM_NAME1)

#   Redirect to get standard input from local file
#     replace "q1test.txt" with the appropriate file name
#	$(PROGRAM_NAME1) < q1test.txt

#   Copy file from elsewhere in gitlab and redirect to get standard input from the new file
#     replace "myFabDataRepo" and "q1test.txt" with the appropriate repo and file names respectively
#	wget http://gitlab.cs.uleth.ca/myFabDataRepo/-/raw/master/q1test.txt
#	$(PROGRAM_NAME1) < q1test.txt
# END OF TEST 1

# START OF TEST2
#     uncomment the test you wish to use
#   replace the URL with the address of the file
test2: compile2
#   No input from standard input test
#	$(PROGRAM_NAME2)

#   No input from standard input but get remote file that the program will read (and replace local file)
#     replace "q2test.txt" with the appropriate file name
#     NOTE: the q2test.txt file in the repo will remain unchanged the files are created in a temp
#     directory while the pipeline runs
#	rm q2test.txt
#	wget http://gitlab.cs.uleth.ca/myFabDataRepo/-/raw/master/q2test.txt
#	$(PROGRAM_NAME2)

#   Display and pipe to get standard input from this command line
#   echo 10 | $(PROGRAM_NAME2)

#   Redirect to get standard input from local file
#     replace "q2test.txt" with the appropriate file name
#	$(PROGRAM_NAME2) < q2test.txt

#   Copy file from elsewhere in gitlab and redirect to get standard input from the new file
#     replace "myFabDataRepo" and "q2test.txt" with the appropriate repo and file names respectively
#	wget http://gitlab.cs.uleth.ca/myFabDataRepo/-/raw/master/q2test.txt
#	$(PROGRAM_NAME2) < q2test.txt
# END OF TEST 2

# START OF TEST3
#     uncomment the test you wish to use
#   replace the URL with the address of the file
test3: compile3
#   No input from standard input test
#	$(PROGRAM_NAME3)

#   No input from standard input but get remote file that the program will read (and replace local file)
#     replace "q3test.txt" with the appropriate file name
#     NOTE: the q3test.txt file in the repo will remain unchanged the files are created in a temp
#     directory while the pipeline runs
#	rm q3test.txt
#	wget http://gitlab.cs.uleth.ca/myFabDataRepo/-/raw/master/q3test.txt
#	$(PROGRAM_NAME3)

#   Display and pipe to get standard input from this command line
#   echo 10 | $(PROGRAM_NAME3)

#   Redirect to get standard input from local file
#     replace "q3test.txt" with the appropriate file name
#	$(PROGRAM_NAME3) < q3test.txt

#   Copy file from elsewhere in gitlab and redirect to get standard input from the new file
#     replace "myFabDataRepo" and "q2test.txt" with the appropriate repo and file names respectively
#	wget http://gitlab.cs.uleth.ca/myFabDataRepo/-/raw/master/q2test.txt
#	$(PROGRAM_NAME3) < q3test.txt
# END OF TEST 3

# target to run all the tests
tests: test1 test2 test3
