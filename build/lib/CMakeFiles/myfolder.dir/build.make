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
CMAKE_SOURCE_DIR = /workspaces/CS225/Social-Media-Group-Visualizer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /workspaces/CS225/Social-Media-Group-Visualizer/build

# Include any dependencies generated for this target.
include lib/CMakeFiles/myfolder.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include lib/CMakeFiles/myfolder.dir/compiler_depend.make

# Include the progress variables for this target.
include lib/CMakeFiles/myfolder.dir/progress.make

# Include the compile flags for this target's objects.
include lib/CMakeFiles/myfolder.dir/flags.make

lib/CMakeFiles/myfolder.dir/myfolder/myfolderfile.cpp.o: lib/CMakeFiles/myfolder.dir/flags.make
lib/CMakeFiles/myfolder.dir/myfolder/myfolderfile.cpp.o: ../lib/myfolder/myfolderfile.cpp
lib/CMakeFiles/myfolder.dir/myfolder/myfolderfile.cpp.o: lib/CMakeFiles/myfolder.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/workspaces/CS225/Social-Media-Group-Visualizer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/CMakeFiles/myfolder.dir/myfolder/myfolderfile.cpp.o"
	cd /workspaces/CS225/Social-Media-Group-Visualizer/build/lib && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT lib/CMakeFiles/myfolder.dir/myfolder/myfolderfile.cpp.o -MF CMakeFiles/myfolder.dir/myfolder/myfolderfile.cpp.o.d -o CMakeFiles/myfolder.dir/myfolder/myfolderfile.cpp.o -c /workspaces/CS225/Social-Media-Group-Visualizer/lib/myfolder/myfolderfile.cpp

lib/CMakeFiles/myfolder.dir/myfolder/myfolderfile.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/myfolder.dir/myfolder/myfolderfile.cpp.i"
	cd /workspaces/CS225/Social-Media-Group-Visualizer/build/lib && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/CS225/Social-Media-Group-Visualizer/lib/myfolder/myfolderfile.cpp > CMakeFiles/myfolder.dir/myfolder/myfolderfile.cpp.i

lib/CMakeFiles/myfolder.dir/myfolder/myfolderfile.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/myfolder.dir/myfolder/myfolderfile.cpp.s"
	cd /workspaces/CS225/Social-Media-Group-Visualizer/build/lib && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/CS225/Social-Media-Group-Visualizer/lib/myfolder/myfolderfile.cpp -o CMakeFiles/myfolder.dir/myfolder/myfolderfile.cpp.s

# Object files for target myfolder
myfolder_OBJECTS = \
"CMakeFiles/myfolder.dir/myfolder/myfolderfile.cpp.o"

# External object files for target myfolder
myfolder_EXTERNAL_OBJECTS =

lib/libmyfolder.a: lib/CMakeFiles/myfolder.dir/myfolder/myfolderfile.cpp.o
lib/libmyfolder.a: lib/CMakeFiles/myfolder.dir/build.make
lib/libmyfolder.a: lib/CMakeFiles/myfolder.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/workspaces/CS225/Social-Media-Group-Visualizer/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libmyfolder.a"
	cd /workspaces/CS225/Social-Media-Group-Visualizer/build/lib && $(CMAKE_COMMAND) -P CMakeFiles/myfolder.dir/cmake_clean_target.cmake
	cd /workspaces/CS225/Social-Media-Group-Visualizer/build/lib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/myfolder.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/CMakeFiles/myfolder.dir/build: lib/libmyfolder.a
.PHONY : lib/CMakeFiles/myfolder.dir/build

lib/CMakeFiles/myfolder.dir/clean:
	cd /workspaces/CS225/Social-Media-Group-Visualizer/build/lib && $(CMAKE_COMMAND) -P CMakeFiles/myfolder.dir/cmake_clean.cmake
.PHONY : lib/CMakeFiles/myfolder.dir/clean

lib/CMakeFiles/myfolder.dir/depend:
	cd /workspaces/CS225/Social-Media-Group-Visualizer/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /workspaces/CS225/Social-Media-Group-Visualizer /workspaces/CS225/Social-Media-Group-Visualizer/lib /workspaces/CS225/Social-Media-Group-Visualizer/build /workspaces/CS225/Social-Media-Group-Visualizer/build/lib /workspaces/CS225/Social-Media-Group-Visualizer/build/lib/CMakeFiles/myfolder.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/CMakeFiles/myfolder.dir/depend

