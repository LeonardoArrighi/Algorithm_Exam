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
CMAKE_COMMAND = /snap/cmake/549/bin/cmake

# The command to remove a file.
RM = /snap/cmake/549/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/04

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/04

# Include any dependencies generated for this target.
include CMakeFiles/test_sorting.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test_sorting.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_sorting.dir/flags.make

CMakeFiles/test_sorting.dir/src/binheap.c.o: CMakeFiles/test_sorting.dir/flags.make
CMakeFiles/test_sorting.dir/src/binheap.c.o: src/binheap.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/04/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/test_sorting.dir/src/binheap.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test_sorting.dir/src/binheap.c.o -c /home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/04/src/binheap.c

CMakeFiles/test_sorting.dir/src/binheap.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_sorting.dir/src/binheap.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/04/src/binheap.c > CMakeFiles/test_sorting.dir/src/binheap.c.i

CMakeFiles/test_sorting.dir/src/binheap.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_sorting.dir/src/binheap.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/04/src/binheap.c -o CMakeFiles/test_sorting.dir/src/binheap.c.s

CMakeFiles/test_sorting.dir/src/bubble_sort.c.o: CMakeFiles/test_sorting.dir/flags.make
CMakeFiles/test_sorting.dir/src/bubble_sort.c.o: src/bubble_sort.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/04/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/test_sorting.dir/src/bubble_sort.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test_sorting.dir/src/bubble_sort.c.o -c /home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/04/src/bubble_sort.c

CMakeFiles/test_sorting.dir/src/bubble_sort.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_sorting.dir/src/bubble_sort.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/04/src/bubble_sort.c > CMakeFiles/test_sorting.dir/src/bubble_sort.c.i

CMakeFiles/test_sorting.dir/src/bubble_sort.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_sorting.dir/src/bubble_sort.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/04/src/bubble_sort.c -o CMakeFiles/test_sorting.dir/src/bubble_sort.c.s

CMakeFiles/test_sorting.dir/src/heap_sort.c.o: CMakeFiles/test_sorting.dir/flags.make
CMakeFiles/test_sorting.dir/src/heap_sort.c.o: src/heap_sort.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/04/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/test_sorting.dir/src/heap_sort.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test_sorting.dir/src/heap_sort.c.o -c /home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/04/src/heap_sort.c

CMakeFiles/test_sorting.dir/src/heap_sort.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_sorting.dir/src/heap_sort.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/04/src/heap_sort.c > CMakeFiles/test_sorting.dir/src/heap_sort.c.i

CMakeFiles/test_sorting.dir/src/heap_sort.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_sorting.dir/src/heap_sort.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/04/src/heap_sort.c -o CMakeFiles/test_sorting.dir/src/heap_sort.c.s

CMakeFiles/test_sorting.dir/src/insertion_sort.c.o: CMakeFiles/test_sorting.dir/flags.make
CMakeFiles/test_sorting.dir/src/insertion_sort.c.o: src/insertion_sort.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/04/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/test_sorting.dir/src/insertion_sort.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test_sorting.dir/src/insertion_sort.c.o -c /home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/04/src/insertion_sort.c

CMakeFiles/test_sorting.dir/src/insertion_sort.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_sorting.dir/src/insertion_sort.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/04/src/insertion_sort.c > CMakeFiles/test_sorting.dir/src/insertion_sort.c.i

CMakeFiles/test_sorting.dir/src/insertion_sort.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_sorting.dir/src/insertion_sort.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/04/src/insertion_sort.c -o CMakeFiles/test_sorting.dir/src/insertion_sort.c.s

CMakeFiles/test_sorting.dir/src/main.c.o: CMakeFiles/test_sorting.dir/flags.make
CMakeFiles/test_sorting.dir/src/main.c.o: src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/04/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/test_sorting.dir/src/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test_sorting.dir/src/main.c.o -c /home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/04/src/main.c

CMakeFiles/test_sorting.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_sorting.dir/src/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/04/src/main.c > CMakeFiles/test_sorting.dir/src/main.c.i

CMakeFiles/test_sorting.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_sorting.dir/src/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/04/src/main.c -o CMakeFiles/test_sorting.dir/src/main.c.s

CMakeFiles/test_sorting.dir/src/quick_sort.c.o: CMakeFiles/test_sorting.dir/flags.make
CMakeFiles/test_sorting.dir/src/quick_sort.c.o: src/quick_sort.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/04/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/test_sorting.dir/src/quick_sort.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test_sorting.dir/src/quick_sort.c.o -c /home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/04/src/quick_sort.c

CMakeFiles/test_sorting.dir/src/quick_sort.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_sorting.dir/src/quick_sort.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/04/src/quick_sort.c > CMakeFiles/test_sorting.dir/src/quick_sort.c.i

CMakeFiles/test_sorting.dir/src/quick_sort.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_sorting.dir/src/quick_sort.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/04/src/quick_sort.c -o CMakeFiles/test_sorting.dir/src/quick_sort.c.s

CMakeFiles/test_sorting.dir/src/select.c.o: CMakeFiles/test_sorting.dir/flags.make
CMakeFiles/test_sorting.dir/src/select.c.o: src/select.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/04/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/test_sorting.dir/src/select.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test_sorting.dir/src/select.c.o -c /home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/04/src/select.c

CMakeFiles/test_sorting.dir/src/select.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_sorting.dir/src/select.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/04/src/select.c > CMakeFiles/test_sorting.dir/src/select.c.i

CMakeFiles/test_sorting.dir/src/select.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_sorting.dir/src/select.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/04/src/select.c -o CMakeFiles/test_sorting.dir/src/select.c.s

CMakeFiles/test_sorting.dir/src/selection_sort.c.o: CMakeFiles/test_sorting.dir/flags.make
CMakeFiles/test_sorting.dir/src/selection_sort.c.o: src/selection_sort.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/04/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/test_sorting.dir/src/selection_sort.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test_sorting.dir/src/selection_sort.c.o -c /home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/04/src/selection_sort.c

CMakeFiles/test_sorting.dir/src/selection_sort.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_sorting.dir/src/selection_sort.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/04/src/selection_sort.c > CMakeFiles/test_sorting.dir/src/selection_sort.c.i

CMakeFiles/test_sorting.dir/src/selection_sort.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_sorting.dir/src/selection_sort.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/04/src/selection_sort.c -o CMakeFiles/test_sorting.dir/src/selection_sort.c.s

CMakeFiles/test_sorting.dir/src/swap.c.o: CMakeFiles/test_sorting.dir/flags.make
CMakeFiles/test_sorting.dir/src/swap.c.o: src/swap.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/04/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/test_sorting.dir/src/swap.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test_sorting.dir/src/swap.c.o -c /home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/04/src/swap.c

CMakeFiles/test_sorting.dir/src/swap.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_sorting.dir/src/swap.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/04/src/swap.c > CMakeFiles/test_sorting.dir/src/swap.c.i

CMakeFiles/test_sorting.dir/src/swap.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_sorting.dir/src/swap.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/04/src/swap.c -o CMakeFiles/test_sorting.dir/src/swap.c.s

CMakeFiles/test_sorting.dir/src/total_order.c.o: CMakeFiles/test_sorting.dir/flags.make
CMakeFiles/test_sorting.dir/src/total_order.c.o: src/total_order.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/04/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/test_sorting.dir/src/total_order.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test_sorting.dir/src/total_order.c.o -c /home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/04/src/total_order.c

CMakeFiles/test_sorting.dir/src/total_order.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_sorting.dir/src/total_order.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/04/src/total_order.c > CMakeFiles/test_sorting.dir/src/total_order.c.i

CMakeFiles/test_sorting.dir/src/total_order.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_sorting.dir/src/total_order.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/04/src/total_order.c -o CMakeFiles/test_sorting.dir/src/total_order.c.s

CMakeFiles/test_sorting.dir/src/utilities.c.o: CMakeFiles/test_sorting.dir/flags.make
CMakeFiles/test_sorting.dir/src/utilities.c.o: src/utilities.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/04/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object CMakeFiles/test_sorting.dir/src/utilities.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test_sorting.dir/src/utilities.c.o -c /home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/04/src/utilities.c

CMakeFiles/test_sorting.dir/src/utilities.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_sorting.dir/src/utilities.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/04/src/utilities.c > CMakeFiles/test_sorting.dir/src/utilities.c.i

CMakeFiles/test_sorting.dir/src/utilities.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_sorting.dir/src/utilities.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/04/src/utilities.c -o CMakeFiles/test_sorting.dir/src/utilities.c.s

# Object files for target test_sorting
test_sorting_OBJECTS = \
"CMakeFiles/test_sorting.dir/src/binheap.c.o" \
"CMakeFiles/test_sorting.dir/src/bubble_sort.c.o" \
"CMakeFiles/test_sorting.dir/src/heap_sort.c.o" \
"CMakeFiles/test_sorting.dir/src/insertion_sort.c.o" \
"CMakeFiles/test_sorting.dir/src/main.c.o" \
"CMakeFiles/test_sorting.dir/src/quick_sort.c.o" \
"CMakeFiles/test_sorting.dir/src/select.c.o" \
"CMakeFiles/test_sorting.dir/src/selection_sort.c.o" \
"CMakeFiles/test_sorting.dir/src/swap.c.o" \
"CMakeFiles/test_sorting.dir/src/total_order.c.o" \
"CMakeFiles/test_sorting.dir/src/utilities.c.o"

# External object files for target test_sorting
test_sorting_EXTERNAL_OBJECTS =

test_sorting: CMakeFiles/test_sorting.dir/src/binheap.c.o
test_sorting: CMakeFiles/test_sorting.dir/src/bubble_sort.c.o
test_sorting: CMakeFiles/test_sorting.dir/src/heap_sort.c.o
test_sorting: CMakeFiles/test_sorting.dir/src/insertion_sort.c.o
test_sorting: CMakeFiles/test_sorting.dir/src/main.c.o
test_sorting: CMakeFiles/test_sorting.dir/src/quick_sort.c.o
test_sorting: CMakeFiles/test_sorting.dir/src/select.c.o
test_sorting: CMakeFiles/test_sorting.dir/src/selection_sort.c.o
test_sorting: CMakeFiles/test_sorting.dir/src/swap.c.o
test_sorting: CMakeFiles/test_sorting.dir/src/total_order.c.o
test_sorting: CMakeFiles/test_sorting.dir/src/utilities.c.o
test_sorting: CMakeFiles/test_sorting.dir/build.make
test_sorting: CMakeFiles/test_sorting.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/04/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking C executable test_sorting"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_sorting.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_sorting.dir/build: test_sorting

.PHONY : CMakeFiles/test_sorting.dir/build

CMakeFiles/test_sorting.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_sorting.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_sorting.dir/clean

CMakeFiles/test_sorting.dir/depend:
	cd /home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/04 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/04 /home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/04 /home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/04 /home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/04 /home/leonardo/DSSC/Algorithms/Homeworks/Algorithm_Exam/04/CMakeFiles/test_sorting.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_sorting.dir/depend

