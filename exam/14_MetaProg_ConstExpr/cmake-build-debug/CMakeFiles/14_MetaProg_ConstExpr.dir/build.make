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
CMAKE_SOURCE_DIR = /Users/janoschbaltensperger/repos/GeschwindCpp/exam/14_MetaProg_ConstExpr

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/janoschbaltensperger/repos/GeschwindCpp/exam/14_MetaProg_ConstExpr/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/14_MetaProg_ConstExpr.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/14_MetaProg_ConstExpr.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/14_MetaProg_ConstExpr.dir/flags.make

CMakeFiles/14_MetaProg_ConstExpr.dir/main.cpp.o: CMakeFiles/14_MetaProg_ConstExpr.dir/flags.make
CMakeFiles/14_MetaProg_ConstExpr.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/janoschbaltensperger/repos/GeschwindCpp/exam/14_MetaProg_ConstExpr/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/14_MetaProg_ConstExpr.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/14_MetaProg_ConstExpr.dir/main.cpp.o -c /Users/janoschbaltensperger/repos/GeschwindCpp/exam/14_MetaProg_ConstExpr/main.cpp

CMakeFiles/14_MetaProg_ConstExpr.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/14_MetaProg_ConstExpr.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/janoschbaltensperger/repos/GeschwindCpp/exam/14_MetaProg_ConstExpr/main.cpp > CMakeFiles/14_MetaProg_ConstExpr.dir/main.cpp.i

CMakeFiles/14_MetaProg_ConstExpr.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/14_MetaProg_ConstExpr.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/janoschbaltensperger/repos/GeschwindCpp/exam/14_MetaProg_ConstExpr/main.cpp -o CMakeFiles/14_MetaProg_ConstExpr.dir/main.cpp.s

# Object files for target 14_MetaProg_ConstExpr
14_MetaProg_ConstExpr_OBJECTS = \
"CMakeFiles/14_MetaProg_ConstExpr.dir/main.cpp.o"

# External object files for target 14_MetaProg_ConstExpr
14_MetaProg_ConstExpr_EXTERNAL_OBJECTS =

14_MetaProg_ConstExpr: CMakeFiles/14_MetaProg_ConstExpr.dir/main.cpp.o
14_MetaProg_ConstExpr: CMakeFiles/14_MetaProg_ConstExpr.dir/build.make
14_MetaProg_ConstExpr: CMakeFiles/14_MetaProg_ConstExpr.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/janoschbaltensperger/repos/GeschwindCpp/exam/14_MetaProg_ConstExpr/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 14_MetaProg_ConstExpr"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/14_MetaProg_ConstExpr.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/14_MetaProg_ConstExpr.dir/build: 14_MetaProg_ConstExpr

.PHONY : CMakeFiles/14_MetaProg_ConstExpr.dir/build

CMakeFiles/14_MetaProg_ConstExpr.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/14_MetaProg_ConstExpr.dir/cmake_clean.cmake
.PHONY : CMakeFiles/14_MetaProg_ConstExpr.dir/clean

CMakeFiles/14_MetaProg_ConstExpr.dir/depend:
	cd /Users/janoschbaltensperger/repos/GeschwindCpp/exam/14_MetaProg_ConstExpr/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/janoschbaltensperger/repos/GeschwindCpp/exam/14_MetaProg_ConstExpr /Users/janoschbaltensperger/repos/GeschwindCpp/exam/14_MetaProg_ConstExpr /Users/janoschbaltensperger/repos/GeschwindCpp/exam/14_MetaProg_ConstExpr/cmake-build-debug /Users/janoschbaltensperger/repos/GeschwindCpp/exam/14_MetaProg_ConstExpr/cmake-build-debug /Users/janoschbaltensperger/repos/GeschwindCpp/exam/14_MetaProg_ConstExpr/cmake-build-debug/CMakeFiles/14_MetaProg_ConstExpr.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/14_MetaProg_ConstExpr.dir/depend
