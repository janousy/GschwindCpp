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
CMAKE_SOURCE_DIR = /Users/janoschbaltensperger/repos/GeschwindCpp/LE6/exercise2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/janoschbaltensperger/repos/GeschwindCpp/LE6/exercise2/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/exercise2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/exercise2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/exercise2.dir/flags.make

CMakeFiles/exercise2.dir/main.cpp.o: CMakeFiles/exercise2.dir/flags.make
CMakeFiles/exercise2.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/janoschbaltensperger/repos/GeschwindCpp/LE6/exercise2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/exercise2.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/exercise2.dir/main.cpp.o -c /Users/janoschbaltensperger/repos/GeschwindCpp/LE6/exercise2/main.cpp

CMakeFiles/exercise2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/exercise2.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/janoschbaltensperger/repos/GeschwindCpp/LE6/exercise2/main.cpp > CMakeFiles/exercise2.dir/main.cpp.i

CMakeFiles/exercise2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/exercise2.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/janoschbaltensperger/repos/GeschwindCpp/LE6/exercise2/main.cpp -o CMakeFiles/exercise2.dir/main.cpp.s

CMakeFiles/exercise2.dir/pvector.cpp.o: CMakeFiles/exercise2.dir/flags.make
CMakeFiles/exercise2.dir/pvector.cpp.o: ../pvector.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/janoschbaltensperger/repos/GeschwindCpp/LE6/exercise2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/exercise2.dir/pvector.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/exercise2.dir/pvector.cpp.o -c /Users/janoschbaltensperger/repos/GeschwindCpp/LE6/exercise2/pvector.cpp

CMakeFiles/exercise2.dir/pvector.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/exercise2.dir/pvector.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/janoschbaltensperger/repos/GeschwindCpp/LE6/exercise2/pvector.cpp > CMakeFiles/exercise2.dir/pvector.cpp.i

CMakeFiles/exercise2.dir/pvector.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/exercise2.dir/pvector.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/janoschbaltensperger/repos/GeschwindCpp/LE6/exercise2/pvector.cpp -o CMakeFiles/exercise2.dir/pvector.cpp.s

# Object files for target exercise2
exercise2_OBJECTS = \
"CMakeFiles/exercise2.dir/main.cpp.o" \
"CMakeFiles/exercise2.dir/pvector.cpp.o"

# External object files for target exercise2
exercise2_EXTERNAL_OBJECTS =

exercise2: CMakeFiles/exercise2.dir/main.cpp.o
exercise2: CMakeFiles/exercise2.dir/pvector.cpp.o
exercise2: CMakeFiles/exercise2.dir/build.make
exercise2: CMakeFiles/exercise2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/janoschbaltensperger/repos/GeschwindCpp/LE6/exercise2/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable exercise2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/exercise2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/exercise2.dir/build: exercise2

.PHONY : CMakeFiles/exercise2.dir/build

CMakeFiles/exercise2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/exercise2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/exercise2.dir/clean

CMakeFiles/exercise2.dir/depend:
	cd /Users/janoschbaltensperger/repos/GeschwindCpp/LE6/exercise2/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/janoschbaltensperger/repos/GeschwindCpp/LE6/exercise2 /Users/janoschbaltensperger/repos/GeschwindCpp/LE6/exercise2 /Users/janoschbaltensperger/repos/GeschwindCpp/LE6/exercise2/cmake-build-debug /Users/janoschbaltensperger/repos/GeschwindCpp/LE6/exercise2/cmake-build-debug /Users/janoschbaltensperger/repos/GeschwindCpp/LE6/exercise2/cmake-build-debug/CMakeFiles/exercise2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/exercise2.dir/depend

