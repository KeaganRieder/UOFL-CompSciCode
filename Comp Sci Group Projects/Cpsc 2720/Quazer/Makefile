# Revision History -- at the bottom of the document
################################################################################
# The targets in this file are used in .gitlab-ci.yml and  the files created
# are found in the .gitignore
################################################################################
# Changing any names below can change the target names which will require that
# you update .gitlab_ci.yml and .gitignore
################################################################################

################################################################################
# Variable definitions
################################################################################

# Executable names
PROJECT = quazar

# Compilation command and flags
CXX=g++
CXXVERSION= -std=c++14
CXXFLAGS= ${CXXVERSION} -g

# Directories
SRC_DIR = src
PROJECT_SRC_DIR = src/project
SRC_INCLUDE = include
INCLUDE = -I ${SRC_INCLUDE}

# Tool variables
STATIC_ANALYSIS = cppcheck
STYLE_CHECK = cpplint

################################################################################
# Targets
################################################################################

# Default goal
.DEFAULT_GOAL := compileProject

################################################################################
# Clean-up targets
################################################################################

.PHONY: clean-docs
clean-docs:
	rm -rf docs/code/html

.PHONY: clean-exec
clean-exec:
	rm -rf ${PROJECT} ${GTEST} ${PROJECT}.exe

.PHONY: clean-obj
clean-obj:
	rm -rf ${SRC}/*.o

.PHONY: clean-temp
clean-temp:
	rm -rf *~ \#* .\#* \
	${SRC_DIR}/*~ ${SRC_DIR}/\#* ${SRC_DIR}/.\#* \
	${GTEST_DIR}/*~ ${GTEST_DIR}/\#* ${GTEST_DIR}/.\#* \
	${SRC_INCLUDE}/*~ ${SRC_INCLUDE}/\#* ${SRC_INCLUDE}/.\#* \
	${PROJECT_SRC_DIR}/*~ ${PROJECT_SRC_DIR}/\#* ${PROJECT_SRC_DIR}/.\#* \
	${DESIGN_DIR}/*~ ${DESIGN_DIR}/\#* ${DESIGN_DIR}/.\#* \
	${DOXY_DIR}/*~ ${DOXY_DIR}/\#* ${DOXY_DIR}/.\#* \
	*.gcov *.gcda *.gcno

.PHONY: clean
clean: clean-docs clean-exec clean-obj clean-temp

################################################################################
# Compilaton targets
################################################################################

# default rule for compiling .cc to .o
%.o: %.cpp
	${CXX} ${CXXFLAGS} -c $< -o $@

# Compilation targets

# compilation for making the project
# using the files in include, src, and src/project, but not test
compileProject: ${SRC_DIR} ${PROJECT_SRC_DIR} clean-exec
	${CXX} ${CXXVERSION} -o ${PROJECT} ${INCLUDE} \
	${SRC_DIR}/*.cpp ${PROJECT_SRC_DIR}/*.cpp

################################################################################
# Test targets
################################################################################

# To perform the static check
static: ${SRC_DIR} ${GTEST_DIR}
	${STATIC_ANALYSIS} --verbose --enable=all ${SRC_DIR} ${GTEST_DIR} \
	${SRC_INCLUDE} --suppress=missingInclude --error-exitcode=1

# To perform the style check
style: ${SRC_DIR} ${GTEST_DIR} ${SRC_INCLUDE} ${PROJECT_SRC_DIR}
	${STYLE_CHECK} ${SRC_DIR}/* ${GTEST_DIR}/* ${SRC_INCLUDE}/* \
	${PROJECT_SRC_DIR}/*


################################################################################
# Revision History
################################################################################
# Updated: 2023-01-19 Dr. Anvik <john.anvik@uleth.ca>
#  Remove the unit tests and docs, as not needed for project.
################################################################################
# Updated: 2022-12-19 Nicole wilson <n.wilson@uleth.ca>
#  Remove the memcheck and coverage tests.
################################################################################
# Updated: 2022-12-15 Nicole Wilson <n.wilson@uleth.ca>
#  Removed all references to OS as the pipelines are now running on Ubuntu
################################################################################
# Updated: 2022-10-19 Dr. J. Anvik <john.anvik@uleth.ca>
#  Changed the static command to make the pipeline fail on exit with errors.
################################################################################
# Updated: 2022-09-11 Nicole Wilson <n.wilson@uleth.ca>
#  Added reference to OS in setting of STYLE_CHECK.
#  This is a temporary measure until the pipelines are running on Ubuntu
################################################################################
