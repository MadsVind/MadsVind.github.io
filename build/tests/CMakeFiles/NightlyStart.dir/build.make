# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/vind/dpl

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/vind/dpl/build

# Utility rule file for NightlyStart.

# Include any custom commands dependencies for this target.
include tests/CMakeFiles/NightlyStart.dir/compiler_depend.make

# Include the progress variables for this target.
include tests/CMakeFiles/NightlyStart.dir/progress.make

tests/CMakeFiles/NightlyStart:
	cd /home/vind/dpl/build/tests && /usr/bin/ctest -D NightlyStart

NightlyStart: tests/CMakeFiles/NightlyStart
NightlyStart: tests/CMakeFiles/NightlyStart.dir/build.make
.PHONY : NightlyStart

# Rule to build all files generated by this target.
tests/CMakeFiles/NightlyStart.dir/build: NightlyStart
.PHONY : tests/CMakeFiles/NightlyStart.dir/build

tests/CMakeFiles/NightlyStart.dir/clean:
	cd /home/vind/dpl/build/tests && $(CMAKE_COMMAND) -P CMakeFiles/NightlyStart.dir/cmake_clean.cmake
.PHONY : tests/CMakeFiles/NightlyStart.dir/clean

tests/CMakeFiles/NightlyStart.dir/depend:
	cd /home/vind/dpl/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/vind/dpl /home/vind/dpl/tests /home/vind/dpl/build /home/vind/dpl/build/tests /home/vind/dpl/build/tests/CMakeFiles/NightlyStart.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tests/CMakeFiles/NightlyStart.dir/depend

