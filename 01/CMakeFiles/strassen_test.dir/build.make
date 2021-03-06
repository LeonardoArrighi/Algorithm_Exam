# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /snap/cmake/513/bin/cmake

# The command to remove a file.
RM = /snap/cmake/513/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/01

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/01

# Include any dependencies generated for this target.
include CMakeFiles/strassen_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/strassen_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/strassen_test.dir/flags.make

CMakeFiles/strassen_test.dir/src/main.c.o: CMakeFiles/strassen_test.dir/flags.make
CMakeFiles/strassen_test.dir/src/main.c.o: src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/01/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/strassen_test.dir/src/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/strassen_test.dir/src/main.c.o -c /home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/01/src/main.c

CMakeFiles/strassen_test.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/strassen_test.dir/src/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/01/src/main.c > CMakeFiles/strassen_test.dir/src/main.c.i

CMakeFiles/strassen_test.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/strassen_test.dir/src/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/01/src/main.c -o CMakeFiles/strassen_test.dir/src/main.c.s

CMakeFiles/strassen_test.dir/src/matrix.c.o: CMakeFiles/strassen_test.dir/flags.make
CMakeFiles/strassen_test.dir/src/matrix.c.o: src/matrix.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/01/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/strassen_test.dir/src/matrix.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/strassen_test.dir/src/matrix.c.o -c /home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/01/src/matrix.c

CMakeFiles/strassen_test.dir/src/matrix.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/strassen_test.dir/src/matrix.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/01/src/matrix.c > CMakeFiles/strassen_test.dir/src/matrix.c.i

CMakeFiles/strassen_test.dir/src/matrix.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/strassen_test.dir/src/matrix.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/01/src/matrix.c -o CMakeFiles/strassen_test.dir/src/matrix.c.s

CMakeFiles/strassen_test.dir/src/strassen.c.o: CMakeFiles/strassen_test.dir/flags.make
CMakeFiles/strassen_test.dir/src/strassen.c.o: src/strassen.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/01/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/strassen_test.dir/src/strassen.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/strassen_test.dir/src/strassen.c.o -c /home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/01/src/strassen.c

CMakeFiles/strassen_test.dir/src/strassen.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/strassen_test.dir/src/strassen.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/01/src/strassen.c > CMakeFiles/strassen_test.dir/src/strassen.c.i

CMakeFiles/strassen_test.dir/src/strassen.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/strassen_test.dir/src/strassen.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/01/src/strassen.c -o CMakeFiles/strassen_test.dir/src/strassen.c.s

CMakeFiles/strassen_test.dir/src/test.c.o: CMakeFiles/strassen_test.dir/flags.make
CMakeFiles/strassen_test.dir/src/test.c.o: src/test.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/01/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/strassen_test.dir/src/test.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/strassen_test.dir/src/test.c.o -c /home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/01/src/test.c

CMakeFiles/strassen_test.dir/src/test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/strassen_test.dir/src/test.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/01/src/test.c > CMakeFiles/strassen_test.dir/src/test.c.i

CMakeFiles/strassen_test.dir/src/test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/strassen_test.dir/src/test.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/01/src/test.c -o CMakeFiles/strassen_test.dir/src/test.c.s

# Object files for target strassen_test
strassen_test_OBJECTS = \
"CMakeFiles/strassen_test.dir/src/main.c.o" \
"CMakeFiles/strassen_test.dir/src/matrix.c.o" \
"CMakeFiles/strassen_test.dir/src/strassen.c.o" \
"CMakeFiles/strassen_test.dir/src/test.c.o"

# External object files for target strassen_test
strassen_test_EXTERNAL_OBJECTS =

strassen_test: CMakeFiles/strassen_test.dir/src/main.c.o
strassen_test: CMakeFiles/strassen_test.dir/src/matrix.c.o
strassen_test: CMakeFiles/strassen_test.dir/src/strassen.c.o
strassen_test: CMakeFiles/strassen_test.dir/src/test.c.o
strassen_test: CMakeFiles/strassen_test.dir/build.make
strassen_test: CMakeFiles/strassen_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/01/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable strassen_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/strassen_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/strassen_test.dir/build: strassen_test

.PHONY : CMakeFiles/strassen_test.dir/build

CMakeFiles/strassen_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/strassen_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/strassen_test.dir/clean

CMakeFiles/strassen_test.dir/depend:
	cd /home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/01 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/01 /home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/01 /home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/01 /home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/01 /home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/01/CMakeFiles/strassen_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/strassen_test.dir/depend

