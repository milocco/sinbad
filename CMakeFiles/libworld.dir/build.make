# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.3

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/alberto/nea/aspis/cl

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alberto/nea/aspis/cl

# Include any dependencies generated for this target.
include CMakeFiles/libworld.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/libworld.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/libworld.dir/flags.make

CMakeFiles/libworld.dir/System/world/World.cxx.o: CMakeFiles/libworld.dir/flags.make
CMakeFiles/libworld.dir/System/world/World.cxx.o: System/world/World.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alberto/nea/aspis/cl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/libworld.dir/System/world/World.cxx.o"
	clang   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/libworld.dir/System/world/World.cxx.o -c /home/alberto/nea/aspis/cl/System/world/World.cxx

CMakeFiles/libworld.dir/System/world/World.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libworld.dir/System/world/World.cxx.i"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alberto/nea/aspis/cl/System/world/World.cxx > CMakeFiles/libworld.dir/System/world/World.cxx.i

CMakeFiles/libworld.dir/System/world/World.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libworld.dir/System/world/World.cxx.s"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alberto/nea/aspis/cl/System/world/World.cxx -o CMakeFiles/libworld.dir/System/world/World.cxx.s

CMakeFiles/libworld.dir/System/world/World.cxx.o.requires:

.PHONY : CMakeFiles/libworld.dir/System/world/World.cxx.o.requires

CMakeFiles/libworld.dir/System/world/World.cxx.o.provides: CMakeFiles/libworld.dir/System/world/World.cxx.o.requires
	$(MAKE) -f CMakeFiles/libworld.dir/build.make CMakeFiles/libworld.dir/System/world/World.cxx.o.provides.build
.PHONY : CMakeFiles/libworld.dir/System/world/World.cxx.o.provides

CMakeFiles/libworld.dir/System/world/World.cxx.o.provides.build: CMakeFiles/libworld.dir/System/world/World.cxx.o


# Object files for target libworld
libworld_OBJECTS = \
"CMakeFiles/libworld.dir/System/world/World.cxx.o"

# External object files for target libworld
libworld_EXTERNAL_OBJECTS =

lib/liblibworld.so: CMakeFiles/libworld.dir/System/world/World.cxx.o
lib/liblibworld.so: CMakeFiles/libworld.dir/build.make
lib/liblibworld.so: CMakeFiles/libworld.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alberto/nea/aspis/cl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library lib/liblibworld.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/libworld.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/libworld.dir/build: lib/liblibworld.so

.PHONY : CMakeFiles/libworld.dir/build

CMakeFiles/libworld.dir/requires: CMakeFiles/libworld.dir/System/world/World.cxx.o.requires

.PHONY : CMakeFiles/libworld.dir/requires

CMakeFiles/libworld.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/libworld.dir/cmake_clean.cmake
.PHONY : CMakeFiles/libworld.dir/clean

CMakeFiles/libworld.dir/depend:
	cd /home/alberto/nea/aspis/cl && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alberto/nea/aspis/cl /home/alberto/nea/aspis/cl /home/alberto/nea/aspis/cl /home/alberto/nea/aspis/cl /home/alberto/nea/aspis/cl/CMakeFiles/libworld.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/libworld.dir/depend

