# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = "C:/Program Files/CMake/bin/cmake.exe"

# The command to remove a file.
RM = "C:/Program Files/CMake/bin/cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:/Users/malef/dev/C++/dsa

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:/Users/malef/dev/C++/dsa/build

# Include any dependencies generated for this target.
include src/CMakeFiles/dsa.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/dsa.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/dsa.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/dsa.dir/flags.make

src/CMakeFiles/dsa.dir/bst.cpp.obj: src/CMakeFiles/dsa.dir/flags.make
src/CMakeFiles/dsa.dir/bst.cpp.obj: src/CMakeFiles/dsa.dir/includes_CXX.rsp
src/CMakeFiles/dsa.dir/bst.cpp.obj: C:/Users/malef/dev/C++/dsa/src/bst.cpp
src/CMakeFiles/dsa.dir/bst.cpp.obj: src/CMakeFiles/dsa.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:/Users/malef/dev/C++/dsa/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/dsa.dir/bst.cpp.obj"
	cd C:/Users/malef/dev/C++/dsa/build/src && C:/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/dsa.dir/bst.cpp.obj -MF CMakeFiles/dsa.dir/bst.cpp.obj.d -o CMakeFiles/dsa.dir/bst.cpp.obj -c C:/Users/malef/dev/C++/dsa/src/bst.cpp

src/CMakeFiles/dsa.dir/bst.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/dsa.dir/bst.cpp.i"
	cd C:/Users/malef/dev/C++/dsa/build/src && C:/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:/Users/malef/dev/C++/dsa/src/bst.cpp > CMakeFiles/dsa.dir/bst.cpp.i

src/CMakeFiles/dsa.dir/bst.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/dsa.dir/bst.cpp.s"
	cd C:/Users/malef/dev/C++/dsa/build/src && C:/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:/Users/malef/dev/C++/dsa/src/bst.cpp -o CMakeFiles/dsa.dir/bst.cpp.s

src/CMakeFiles/dsa.dir/tree.cpp.obj: src/CMakeFiles/dsa.dir/flags.make
src/CMakeFiles/dsa.dir/tree.cpp.obj: src/CMakeFiles/dsa.dir/includes_CXX.rsp
src/CMakeFiles/dsa.dir/tree.cpp.obj: C:/Users/malef/dev/C++/dsa/src/tree.cpp
src/CMakeFiles/dsa.dir/tree.cpp.obj: src/CMakeFiles/dsa.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:/Users/malef/dev/C++/dsa/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/dsa.dir/tree.cpp.obj"
	cd C:/Users/malef/dev/C++/dsa/build/src && C:/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/dsa.dir/tree.cpp.obj -MF CMakeFiles/dsa.dir/tree.cpp.obj.d -o CMakeFiles/dsa.dir/tree.cpp.obj -c C:/Users/malef/dev/C++/dsa/src/tree.cpp

src/CMakeFiles/dsa.dir/tree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/dsa.dir/tree.cpp.i"
	cd C:/Users/malef/dev/C++/dsa/build/src && C:/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:/Users/malef/dev/C++/dsa/src/tree.cpp > CMakeFiles/dsa.dir/tree.cpp.i

src/CMakeFiles/dsa.dir/tree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/dsa.dir/tree.cpp.s"
	cd C:/Users/malef/dev/C++/dsa/build/src && C:/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:/Users/malef/dev/C++/dsa/src/tree.cpp -o CMakeFiles/dsa.dir/tree.cpp.s

# Object files for target dsa
dsa_OBJECTS = \
"CMakeFiles/dsa.dir/bst.cpp.obj" \
"CMakeFiles/dsa.dir/tree.cpp.obj"

# External object files for target dsa
dsa_EXTERNAL_OBJECTS =

src/libdsa.a: src/CMakeFiles/dsa.dir/bst.cpp.obj
src/libdsa.a: src/CMakeFiles/dsa.dir/tree.cpp.obj
src/libdsa.a: src/CMakeFiles/dsa.dir/build.make
src/libdsa.a: src/CMakeFiles/dsa.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:/Users/malef/dev/C++/dsa/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libdsa.a"
	cd C:/Users/malef/dev/C++/dsa/build/src && $(CMAKE_COMMAND) -P CMakeFiles/dsa.dir/cmake_clean_target.cmake
	cd C:/Users/malef/dev/C++/dsa/build/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dsa.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/dsa.dir/build: src/libdsa.a
.PHONY : src/CMakeFiles/dsa.dir/build

src/CMakeFiles/dsa.dir/clean:
	cd C:/Users/malef/dev/C++/dsa/build/src && $(CMAKE_COMMAND) -P CMakeFiles/dsa.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/dsa.dir/clean

src/CMakeFiles/dsa.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" C:/Users/malef/dev/C++/dsa C:/Users/malef/dev/C++/dsa/src C:/Users/malef/dev/C++/dsa/build C:/Users/malef/dev/C++/dsa/build/src C:/Users/malef/dev/C++/dsa/build/src/CMakeFiles/dsa.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/CMakeFiles/dsa.dir/depend

