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
include CMakeFiles/libpoly.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/libpoly.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/libpoly.dir/flags.make

CMakeFiles/libpoly.dir/System/poly/PolyFunction.cxx.o: CMakeFiles/libpoly.dir/flags.make
CMakeFiles/libpoly.dir/System/poly/PolyFunction.cxx.o: System/poly/PolyFunction.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alberto/nea/aspis/cl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/libpoly.dir/System/poly/PolyFunction.cxx.o"
	clang   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/libpoly.dir/System/poly/PolyFunction.cxx.o -c /home/alberto/nea/aspis/cl/System/poly/PolyFunction.cxx

CMakeFiles/libpoly.dir/System/poly/PolyFunction.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libpoly.dir/System/poly/PolyFunction.cxx.i"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alberto/nea/aspis/cl/System/poly/PolyFunction.cxx > CMakeFiles/libpoly.dir/System/poly/PolyFunction.cxx.i

CMakeFiles/libpoly.dir/System/poly/PolyFunction.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libpoly.dir/System/poly/PolyFunction.cxx.s"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alberto/nea/aspis/cl/System/poly/PolyFunction.cxx -o CMakeFiles/libpoly.dir/System/poly/PolyFunction.cxx.s

CMakeFiles/libpoly.dir/System/poly/PolyFunction.cxx.o.requires:

.PHONY : CMakeFiles/libpoly.dir/System/poly/PolyFunction.cxx.o.requires

CMakeFiles/libpoly.dir/System/poly/PolyFunction.cxx.o.provides: CMakeFiles/libpoly.dir/System/poly/PolyFunction.cxx.o.requires
	$(MAKE) -f CMakeFiles/libpoly.dir/build.make CMakeFiles/libpoly.dir/System/poly/PolyFunction.cxx.o.provides.build
.PHONY : CMakeFiles/libpoly.dir/System/poly/PolyFunction.cxx.o.provides

CMakeFiles/libpoly.dir/System/poly/PolyFunction.cxx.o.provides.build: CMakeFiles/libpoly.dir/System/poly/PolyFunction.cxx.o


CMakeFiles/libpoly.dir/System/poly/PolyVar.cxx.o: CMakeFiles/libpoly.dir/flags.make
CMakeFiles/libpoly.dir/System/poly/PolyVar.cxx.o: System/poly/PolyVar.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alberto/nea/aspis/cl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/libpoly.dir/System/poly/PolyVar.cxx.o"
	clang   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/libpoly.dir/System/poly/PolyVar.cxx.o -c /home/alberto/nea/aspis/cl/System/poly/PolyVar.cxx

CMakeFiles/libpoly.dir/System/poly/PolyVar.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libpoly.dir/System/poly/PolyVar.cxx.i"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alberto/nea/aspis/cl/System/poly/PolyVar.cxx > CMakeFiles/libpoly.dir/System/poly/PolyVar.cxx.i

CMakeFiles/libpoly.dir/System/poly/PolyVar.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libpoly.dir/System/poly/PolyVar.cxx.s"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alberto/nea/aspis/cl/System/poly/PolyVar.cxx -o CMakeFiles/libpoly.dir/System/poly/PolyVar.cxx.s

CMakeFiles/libpoly.dir/System/poly/PolyVar.cxx.o.requires:

.PHONY : CMakeFiles/libpoly.dir/System/poly/PolyVar.cxx.o.requires

CMakeFiles/libpoly.dir/System/poly/PolyVar.cxx.o.provides: CMakeFiles/libpoly.dir/System/poly/PolyVar.cxx.o.requires
	$(MAKE) -f CMakeFiles/libpoly.dir/build.make CMakeFiles/libpoly.dir/System/poly/PolyVar.cxx.o.provides.build
.PHONY : CMakeFiles/libpoly.dir/System/poly/PolyVar.cxx.o.provides

CMakeFiles/libpoly.dir/System/poly/PolyVar.cxx.o.provides.build: CMakeFiles/libpoly.dir/System/poly/PolyVar.cxx.o


CMakeFiles/libpoly.dir/System/poly/PolyVarOne.cxx.o: CMakeFiles/libpoly.dir/flags.make
CMakeFiles/libpoly.dir/System/poly/PolyVarOne.cxx.o: System/poly/PolyVarOne.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alberto/nea/aspis/cl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/libpoly.dir/System/poly/PolyVarOne.cxx.o"
	clang   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/libpoly.dir/System/poly/PolyVarOne.cxx.o -c /home/alberto/nea/aspis/cl/System/poly/PolyVarOne.cxx

CMakeFiles/libpoly.dir/System/poly/PolyVarOne.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libpoly.dir/System/poly/PolyVarOne.cxx.i"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alberto/nea/aspis/cl/System/poly/PolyVarOne.cxx > CMakeFiles/libpoly.dir/System/poly/PolyVarOne.cxx.i

CMakeFiles/libpoly.dir/System/poly/PolyVarOne.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libpoly.dir/System/poly/PolyVarOne.cxx.s"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alberto/nea/aspis/cl/System/poly/PolyVarOne.cxx -o CMakeFiles/libpoly.dir/System/poly/PolyVarOne.cxx.s

CMakeFiles/libpoly.dir/System/poly/PolyVarOne.cxx.o.requires:

.PHONY : CMakeFiles/libpoly.dir/System/poly/PolyVarOne.cxx.o.requires

CMakeFiles/libpoly.dir/System/poly/PolyVarOne.cxx.o.provides: CMakeFiles/libpoly.dir/System/poly/PolyVarOne.cxx.o.requires
	$(MAKE) -f CMakeFiles/libpoly.dir/build.make CMakeFiles/libpoly.dir/System/poly/PolyVarOne.cxx.o.provides.build
.PHONY : CMakeFiles/libpoly.dir/System/poly/PolyVarOne.cxx.o.provides

CMakeFiles/libpoly.dir/System/poly/PolyVarOne.cxx.o.provides.build: CMakeFiles/libpoly.dir/System/poly/PolyVarOne.cxx.o


CMakeFiles/libpoly.dir/System/poly/solveValues.cxx.o: CMakeFiles/libpoly.dir/flags.make
CMakeFiles/libpoly.dir/System/poly/solveValues.cxx.o: System/poly/solveValues.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alberto/nea/aspis/cl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/libpoly.dir/System/poly/solveValues.cxx.o"
	clang   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/libpoly.dir/System/poly/solveValues.cxx.o -c /home/alberto/nea/aspis/cl/System/poly/solveValues.cxx

CMakeFiles/libpoly.dir/System/poly/solveValues.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libpoly.dir/System/poly/solveValues.cxx.i"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alberto/nea/aspis/cl/System/poly/solveValues.cxx > CMakeFiles/libpoly.dir/System/poly/solveValues.cxx.i

CMakeFiles/libpoly.dir/System/poly/solveValues.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libpoly.dir/System/poly/solveValues.cxx.s"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alberto/nea/aspis/cl/System/poly/solveValues.cxx -o CMakeFiles/libpoly.dir/System/poly/solveValues.cxx.s

CMakeFiles/libpoly.dir/System/poly/solveValues.cxx.o.requires:

.PHONY : CMakeFiles/libpoly.dir/System/poly/solveValues.cxx.o.requires

CMakeFiles/libpoly.dir/System/poly/solveValues.cxx.o.provides: CMakeFiles/libpoly.dir/System/poly/solveValues.cxx.o.requires
	$(MAKE) -f CMakeFiles/libpoly.dir/build.make CMakeFiles/libpoly.dir/System/poly/solveValues.cxx.o.provides.build
.PHONY : CMakeFiles/libpoly.dir/System/poly/solveValues.cxx.o.provides

CMakeFiles/libpoly.dir/System/poly/solveValues.cxx.o.provides.build: CMakeFiles/libpoly.dir/System/poly/solveValues.cxx.o


# Object files for target libpoly
libpoly_OBJECTS = \
"CMakeFiles/libpoly.dir/System/poly/PolyFunction.cxx.o" \
"CMakeFiles/libpoly.dir/System/poly/PolyVar.cxx.o" \
"CMakeFiles/libpoly.dir/System/poly/PolyVarOne.cxx.o" \
"CMakeFiles/libpoly.dir/System/poly/solveValues.cxx.o"

# External object files for target libpoly
libpoly_EXTERNAL_OBJECTS =

lib/liblibpoly.so: CMakeFiles/libpoly.dir/System/poly/PolyFunction.cxx.o
lib/liblibpoly.so: CMakeFiles/libpoly.dir/System/poly/PolyVar.cxx.o
lib/liblibpoly.so: CMakeFiles/libpoly.dir/System/poly/PolyVarOne.cxx.o
lib/liblibpoly.so: CMakeFiles/libpoly.dir/System/poly/solveValues.cxx.o
lib/liblibpoly.so: CMakeFiles/libpoly.dir/build.make
lib/liblibpoly.so: CMakeFiles/libpoly.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alberto/nea/aspis/cl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX shared library lib/liblibpoly.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/libpoly.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/libpoly.dir/build: lib/liblibpoly.so

.PHONY : CMakeFiles/libpoly.dir/build

CMakeFiles/libpoly.dir/requires: CMakeFiles/libpoly.dir/System/poly/PolyFunction.cxx.o.requires
CMakeFiles/libpoly.dir/requires: CMakeFiles/libpoly.dir/System/poly/PolyVar.cxx.o.requires
CMakeFiles/libpoly.dir/requires: CMakeFiles/libpoly.dir/System/poly/PolyVarOne.cxx.o.requires
CMakeFiles/libpoly.dir/requires: CMakeFiles/libpoly.dir/System/poly/solveValues.cxx.o.requires

.PHONY : CMakeFiles/libpoly.dir/requires

CMakeFiles/libpoly.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/libpoly.dir/cmake_clean.cmake
.PHONY : CMakeFiles/libpoly.dir/clean

CMakeFiles/libpoly.dir/depend:
	cd /home/alberto/nea/aspis/cl && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alberto/nea/aspis/cl /home/alberto/nea/aspis/cl /home/alberto/nea/aspis/cl /home/alberto/nea/aspis/cl /home/alberto/nea/aspis/cl/CMakeFiles/libpoly.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/libpoly.dir/depend

