# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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
CMAKE_SOURCE_DIR = /mnt/c/Users/boris/Desktop/3.semester/pt/z4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/boris/Desktop/3.semester/pt/z4/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/z4.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/z4.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/z4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/z4.dir/flags.make

CMakeFiles/z4.dir/zadanie04.cpp.o: CMakeFiles/z4.dir/flags.make
CMakeFiles/z4.dir/zadanie04.cpp.o: /mnt/c/Users/boris/Desktop/3.semester/pt/z4/zadanie04.cpp
CMakeFiles/z4.dir/zadanie04.cpp.o: CMakeFiles/z4.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/c/Users/boris/Desktop/3.semester/pt/z4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/z4.dir/zadanie04.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/z4.dir/zadanie04.cpp.o -MF CMakeFiles/z4.dir/zadanie04.cpp.o.d -o CMakeFiles/z4.dir/zadanie04.cpp.o -c /mnt/c/Users/boris/Desktop/3.semester/pt/z4/zadanie04.cpp

CMakeFiles/z4.dir/zadanie04.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/z4.dir/zadanie04.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/c/Users/boris/Desktop/3.semester/pt/z4/zadanie04.cpp > CMakeFiles/z4.dir/zadanie04.cpp.i

CMakeFiles/z4.dir/zadanie04.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/z4.dir/zadanie04.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/c/Users/boris/Desktop/3.semester/pt/z4/zadanie04.cpp -o CMakeFiles/z4.dir/zadanie04.cpp.s

# Object files for target z4
z4_OBJECTS = \
"CMakeFiles/z4.dir/zadanie04.cpp.o"

# External object files for target z4
z4_EXTERNAL_OBJECTS =

z4: CMakeFiles/z4.dir/zadanie04.cpp.o
z4: CMakeFiles/z4.dir/build.make
z4: CMakeFiles/z4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/c/Users/boris/Desktop/3.semester/pt/z4/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable z4"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/z4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/z4.dir/build: z4
.PHONY : CMakeFiles/z4.dir/build

CMakeFiles/z4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/z4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/z4.dir/clean

CMakeFiles/z4.dir/depend:
	cd /mnt/c/Users/boris/Desktop/3.semester/pt/z4/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/Users/boris/Desktop/3.semester/pt/z4 /mnt/c/Users/boris/Desktop/3.semester/pt/z4 /mnt/c/Users/boris/Desktop/3.semester/pt/z4/cmake-build-debug /mnt/c/Users/boris/Desktop/3.semester/pt/z4/cmake-build-debug /mnt/c/Users/boris/Desktop/3.semester/pt/z4/cmake-build-debug/CMakeFiles/z4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/z4.dir/depend
