# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


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
CMAKE_COMMAND = /Applications/apps/CLion/ch-0/173.3727.114/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/apps/CLion/ch-0/173.3727.114/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/sc/CloudStation/Sync/C_C++/Algorithm/12_1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/sc/CloudStation/Sync/C_C++/Algorithm/12_1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/12_1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/12_1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/12_1.dir/flags.make

CMakeFiles/12_1.dir/main.cpp.o: CMakeFiles/12_1.dir/flags.make
CMakeFiles/12_1.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/sc/CloudStation/Sync/C_C++/Algorithm/12_1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/12_1.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/12_1.dir/main.cpp.o -c /Users/sc/CloudStation/Sync/C_C++/Algorithm/12_1/main.cpp

CMakeFiles/12_1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/12_1.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/sc/CloudStation/Sync/C_C++/Algorithm/12_1/main.cpp > CMakeFiles/12_1.dir/main.cpp.i

CMakeFiles/12_1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/12_1.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/sc/CloudStation/Sync/C_C++/Algorithm/12_1/main.cpp -o CMakeFiles/12_1.dir/main.cpp.s

CMakeFiles/12_1.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/12_1.dir/main.cpp.o.requires

CMakeFiles/12_1.dir/main.cpp.o.provides: CMakeFiles/12_1.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/12_1.dir/build.make CMakeFiles/12_1.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/12_1.dir/main.cpp.o.provides

CMakeFiles/12_1.dir/main.cpp.o.provides.build: CMakeFiles/12_1.dir/main.cpp.o


# Object files for target 12_1
12_1_OBJECTS = \
"CMakeFiles/12_1.dir/main.cpp.o"

# External object files for target 12_1
12_1_EXTERNAL_OBJECTS =

12_1: CMakeFiles/12_1.dir/main.cpp.o
12_1: CMakeFiles/12_1.dir/build.make
12_1: CMakeFiles/12_1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/sc/CloudStation/Sync/C_C++/Algorithm/12_1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 12_1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/12_1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/12_1.dir/build: 12_1

.PHONY : CMakeFiles/12_1.dir/build

CMakeFiles/12_1.dir/requires: CMakeFiles/12_1.dir/main.cpp.o.requires

.PHONY : CMakeFiles/12_1.dir/requires

CMakeFiles/12_1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/12_1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/12_1.dir/clean

CMakeFiles/12_1.dir/depend:
	cd /Users/sc/CloudStation/Sync/C_C++/Algorithm/12_1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/sc/CloudStation/Sync/C_C++/Algorithm/12_1 /Users/sc/CloudStation/Sync/C_C++/Algorithm/12_1 /Users/sc/CloudStation/Sync/C_C++/Algorithm/12_1/cmake-build-debug /Users/sc/CloudStation/Sync/C_C++/Algorithm/12_1/cmake-build-debug /Users/sc/CloudStation/Sync/C_C++/Algorithm/12_1/cmake-build-debug/CMakeFiles/12_1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/12_1.dir/depend

