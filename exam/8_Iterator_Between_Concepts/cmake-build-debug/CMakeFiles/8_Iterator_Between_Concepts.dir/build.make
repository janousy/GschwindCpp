# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/janoschbaltensperger/repos/GeschwindCpp/exam/exercises/8_Iterator_Between_Concepts

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/janoschbaltensperger/repos/GeschwindCpp/exam/exercises/8_Iterator_Between_Concepts/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/8_Iterator_Between_Concepts.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/8_Iterator_Between_Concepts.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/8_Iterator_Between_Concepts.dir/flags.make

CMakeFiles/8_Iterator_Between_Concepts.dir/main.cpp.o: CMakeFiles/8_Iterator_Between_Concepts.dir/flags.make
CMakeFiles/8_Iterator_Between_Concepts.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/janoschbaltensperger/repos/GeschwindCpp/exam/exercises/8_Iterator_Between_Concepts/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/8_Iterator_Between_Concepts.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/8_Iterator_Between_Concepts.dir/main.cpp.o -c /Users/janoschbaltensperger/repos/GeschwindCpp/exam/exercises/8_Iterator_Between_Concepts/main.cpp

CMakeFiles/8_Iterator_Between_Concepts.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/8_Iterator_Between_Concepts.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/janoschbaltensperger/repos/GeschwindCpp/exam/exercises/8_Iterator_Between_Concepts/main.cpp > CMakeFiles/8_Iterator_Between_Concepts.dir/main.cpp.i

CMakeFiles/8_Iterator_Between_Concepts.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/8_Iterator_Between_Concepts.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/janoschbaltensperger/repos/GeschwindCpp/exam/exercises/8_Iterator_Between_Concepts/main.cpp -o CMakeFiles/8_Iterator_Between_Concepts.dir/main.cpp.s

# Object files for target 8_Iterator_Between_Concepts
8_Iterator_Between_Concepts_OBJECTS = \
"CMakeFiles/8_Iterator_Between_Concepts.dir/main.cpp.o"

# External object files for target 8_Iterator_Between_Concepts
8_Iterator_Between_Concepts_EXTERNAL_OBJECTS =

8_Iterator_Between_Concepts: CMakeFiles/8_Iterator_Between_Concepts.dir/main.cpp.o
8_Iterator_Between_Concepts: CMakeFiles/8_Iterator_Between_Concepts.dir/build.make
8_Iterator_Between_Concepts: CMakeFiles/8_Iterator_Between_Concepts.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/janoschbaltensperger/repos/GeschwindCpp/exam/exercises/8_Iterator_Between_Concepts/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 8_Iterator_Between_Concepts"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/8_Iterator_Between_Concepts.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/8_Iterator_Between_Concepts.dir/build: 8_Iterator_Between_Concepts

.PHONY : CMakeFiles/8_Iterator_Between_Concepts.dir/build

CMakeFiles/8_Iterator_Between_Concepts.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/8_Iterator_Between_Concepts.dir/cmake_clean.cmake
.PHONY : CMakeFiles/8_Iterator_Between_Concepts.dir/clean

CMakeFiles/8_Iterator_Between_Concepts.dir/depend:
	cd /Users/janoschbaltensperger/repos/GeschwindCpp/exam/exercises/8_Iterator_Between_Concepts/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/janoschbaltensperger/repos/GeschwindCpp/exam/exercises/8_Iterator_Between_Concepts /Users/janoschbaltensperger/repos/GeschwindCpp/exam/exercises/8_Iterator_Between_Concepts /Users/janoschbaltensperger/repos/GeschwindCpp/exam/exercises/8_Iterator_Between_Concepts/cmake-build-debug /Users/janoschbaltensperger/repos/GeschwindCpp/exam/exercises/8_Iterator_Between_Concepts/cmake-build-debug /Users/janoschbaltensperger/repos/GeschwindCpp/exam/exercises/8_Iterator_Between_Concepts/cmake-build-debug/CMakeFiles/8_Iterator_Between_Concepts.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/8_Iterator_Between_Concepts.dir/depend

