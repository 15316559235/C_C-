# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.7

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Volumes/SD卡/Dropbox/Sync/C_C++/BTree

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Volumes/SD卡/Dropbox/Sync/C_C++/BTree/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/BTree.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/BTree.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BTree.dir/flags.make

CMakeFiles/BTree.dir/二叉树.cpp.o: CMakeFiles/BTree.dir/flags.make
CMakeFiles/BTree.dir/二叉树.cpp.o: ../二叉树.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Volumes/SD卡/Dropbox/Sync/C_C++/BTree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/BTree.dir/二叉树.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/BTree.dir/二叉树.cpp.o -c /Volumes/SD卡/Dropbox/Sync/C_C++/BTree/二叉树.cpp

CMakeFiles/BTree.dir/二叉树.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BTree.dir/二叉树.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Volumes/SD卡/Dropbox/Sync/C_C++/BTree/二叉树.cpp > CMakeFiles/BTree.dir/二叉树.cpp.i

CMakeFiles/BTree.dir/二叉树.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BTree.dir/二叉树.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Volumes/SD卡/Dropbox/Sync/C_C++/BTree/二叉树.cpp -o CMakeFiles/BTree.dir/二叉树.cpp.s

CMakeFiles/BTree.dir/二叉树.cpp.o.requires:

.PHONY : CMakeFiles/BTree.dir/二叉树.cpp.o.requires

CMakeFiles/BTree.dir/二叉树.cpp.o.provides: CMakeFiles/BTree.dir/二叉树.cpp.o.requires
	$(MAKE) -f CMakeFiles/BTree.dir/build.make CMakeFiles/BTree.dir/二叉树.cpp.o.provides.build
.PHONY : CMakeFiles/BTree.dir/二叉树.cpp.o.provides

CMakeFiles/BTree.dir/二叉树.cpp.o.provides.build: CMakeFiles/BTree.dir/二叉树.cpp.o


# Object files for target BTree
BTree_OBJECTS = \
"CMakeFiles/BTree.dir/二叉树.cpp.o"

# External object files for target BTree
BTree_EXTERNAL_OBJECTS =

BTree: CMakeFiles/BTree.dir/二叉树.cpp.o
BTree: CMakeFiles/BTree.dir/build.make
BTree: CMakeFiles/BTree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Volumes/SD卡/Dropbox/Sync/C_C++/BTree/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable BTree"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BTree.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BTree.dir/build: BTree

.PHONY : CMakeFiles/BTree.dir/build

CMakeFiles/BTree.dir/requires: CMakeFiles/BTree.dir/二叉树.cpp.o.requires

.PHONY : CMakeFiles/BTree.dir/requires

CMakeFiles/BTree.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/BTree.dir/cmake_clean.cmake
.PHONY : CMakeFiles/BTree.dir/clean

CMakeFiles/BTree.dir/depend:
	cd /Volumes/SD卡/Dropbox/Sync/C_C++/BTree/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Volumes/SD卡/Dropbox/Sync/C_C++/BTree /Volumes/SD卡/Dropbox/Sync/C_C++/BTree /Volumes/SD卡/Dropbox/Sync/C_C++/BTree/cmake-build-debug /Volumes/SD卡/Dropbox/Sync/C_C++/BTree/cmake-build-debug /Volumes/SD卡/Dropbox/Sync/C_C++/BTree/cmake-build-debug/CMakeFiles/BTree.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BTree.dir/depend
