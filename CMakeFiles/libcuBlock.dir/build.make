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
include CMakeFiles/libcuBlock.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/libcuBlock.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/libcuBlock.dir/flags.make

CMakeFiles/libcuBlock.dir/Model/cuBlock/makeCu.cxx.o: CMakeFiles/libcuBlock.dir/flags.make
CMakeFiles/libcuBlock.dir/Model/cuBlock/makeCu.cxx.o: Model/cuBlock/makeCu.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alberto/nea/aspis/cl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/libcuBlock.dir/Model/cuBlock/makeCu.cxx.o"
	clang   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/libcuBlock.dir/Model/cuBlock/makeCu.cxx.o -c /home/alberto/nea/aspis/cl/Model/cuBlock/makeCu.cxx

CMakeFiles/libcuBlock.dir/Model/cuBlock/makeCu.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libcuBlock.dir/Model/cuBlock/makeCu.cxx.i"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alberto/nea/aspis/cl/Model/cuBlock/makeCu.cxx > CMakeFiles/libcuBlock.dir/Model/cuBlock/makeCu.cxx.i

CMakeFiles/libcuBlock.dir/Model/cuBlock/makeCu.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libcuBlock.dir/Model/cuBlock/makeCu.cxx.s"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alberto/nea/aspis/cl/Model/cuBlock/makeCu.cxx -o CMakeFiles/libcuBlock.dir/Model/cuBlock/makeCu.cxx.s

CMakeFiles/libcuBlock.dir/Model/cuBlock/makeCu.cxx.o.requires:

.PHONY : CMakeFiles/libcuBlock.dir/Model/cuBlock/makeCu.cxx.o.requires

CMakeFiles/libcuBlock.dir/Model/cuBlock/makeCu.cxx.o.provides: CMakeFiles/libcuBlock.dir/Model/cuBlock/makeCu.cxx.o.requires
	$(MAKE) -f CMakeFiles/libcuBlock.dir/build.make CMakeFiles/libcuBlock.dir/Model/cuBlock/makeCu.cxx.o.provides.build
.PHONY : CMakeFiles/libcuBlock.dir/Model/cuBlock/makeCu.cxx.o.provides

CMakeFiles/libcuBlock.dir/Model/cuBlock/makeCu.cxx.o.provides.build: CMakeFiles/libcuBlock.dir/Model/cuBlock/makeCu.cxx.o


CMakeFiles/libcuBlock.dir/Model/cuBlock/CuCollet.cxx.o: CMakeFiles/libcuBlock.dir/flags.make
CMakeFiles/libcuBlock.dir/Model/cuBlock/CuCollet.cxx.o: Model/cuBlock/CuCollet.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alberto/nea/aspis/cl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/libcuBlock.dir/Model/cuBlock/CuCollet.cxx.o"
	clang   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/libcuBlock.dir/Model/cuBlock/CuCollet.cxx.o -c /home/alberto/nea/aspis/cl/Model/cuBlock/CuCollet.cxx

CMakeFiles/libcuBlock.dir/Model/cuBlock/CuCollet.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libcuBlock.dir/Model/cuBlock/CuCollet.cxx.i"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alberto/nea/aspis/cl/Model/cuBlock/CuCollet.cxx > CMakeFiles/libcuBlock.dir/Model/cuBlock/CuCollet.cxx.i

CMakeFiles/libcuBlock.dir/Model/cuBlock/CuCollet.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libcuBlock.dir/Model/cuBlock/CuCollet.cxx.s"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alberto/nea/aspis/cl/Model/cuBlock/CuCollet.cxx -o CMakeFiles/libcuBlock.dir/Model/cuBlock/CuCollet.cxx.s

CMakeFiles/libcuBlock.dir/Model/cuBlock/CuCollet.cxx.o.requires:

.PHONY : CMakeFiles/libcuBlock.dir/Model/cuBlock/CuCollet.cxx.o.requires

CMakeFiles/libcuBlock.dir/Model/cuBlock/CuCollet.cxx.o.provides: CMakeFiles/libcuBlock.dir/Model/cuBlock/CuCollet.cxx.o.requires
	$(MAKE) -f CMakeFiles/libcuBlock.dir/build.make CMakeFiles/libcuBlock.dir/Model/cuBlock/CuCollet.cxx.o.provides.build
.PHONY : CMakeFiles/libcuBlock.dir/Model/cuBlock/CuCollet.cxx.o.provides

CMakeFiles/libcuBlock.dir/Model/cuBlock/CuCollet.cxx.o.provides.build: CMakeFiles/libcuBlock.dir/Model/cuBlock/CuCollet.cxx.o


CMakeFiles/libcuBlock.dir/Model/cuBlock/test.cxx.o: CMakeFiles/libcuBlock.dir/flags.make
CMakeFiles/libcuBlock.dir/Model/cuBlock/test.cxx.o: Model/cuBlock/test.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alberto/nea/aspis/cl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/libcuBlock.dir/Model/cuBlock/test.cxx.o"
	clang   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/libcuBlock.dir/Model/cuBlock/test.cxx.o -c /home/alberto/nea/aspis/cl/Model/cuBlock/test.cxx

CMakeFiles/libcuBlock.dir/Model/cuBlock/test.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libcuBlock.dir/Model/cuBlock/test.cxx.i"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alberto/nea/aspis/cl/Model/cuBlock/test.cxx > CMakeFiles/libcuBlock.dir/Model/cuBlock/test.cxx.i

CMakeFiles/libcuBlock.dir/Model/cuBlock/test.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libcuBlock.dir/Model/cuBlock/test.cxx.s"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alberto/nea/aspis/cl/Model/cuBlock/test.cxx -o CMakeFiles/libcuBlock.dir/Model/cuBlock/test.cxx.s

CMakeFiles/libcuBlock.dir/Model/cuBlock/test.cxx.o.requires:

.PHONY : CMakeFiles/libcuBlock.dir/Model/cuBlock/test.cxx.o.requires

CMakeFiles/libcuBlock.dir/Model/cuBlock/test.cxx.o.provides: CMakeFiles/libcuBlock.dir/Model/cuBlock/test.cxx.o.requires
	$(MAKE) -f CMakeFiles/libcuBlock.dir/build.make CMakeFiles/libcuBlock.dir/Model/cuBlock/test.cxx.o.provides.build
.PHONY : CMakeFiles/libcuBlock.dir/Model/cuBlock/test.cxx.o.provides

CMakeFiles/libcuBlock.dir/Model/cuBlock/test.cxx.o.provides.build: CMakeFiles/libcuBlock.dir/Model/cuBlock/test.cxx.o


CMakeFiles/libcuBlock.dir/Model/cuBlock/cuVariables.cxx.o: CMakeFiles/libcuBlock.dir/flags.make
CMakeFiles/libcuBlock.dir/Model/cuBlock/cuVariables.cxx.o: Model/cuBlock/cuVariables.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alberto/nea/aspis/cl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/libcuBlock.dir/Model/cuBlock/cuVariables.cxx.o"
	clang   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/libcuBlock.dir/Model/cuBlock/cuVariables.cxx.o -c /home/alberto/nea/aspis/cl/Model/cuBlock/cuVariables.cxx

CMakeFiles/libcuBlock.dir/Model/cuBlock/cuVariables.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libcuBlock.dir/Model/cuBlock/cuVariables.cxx.i"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alberto/nea/aspis/cl/Model/cuBlock/cuVariables.cxx > CMakeFiles/libcuBlock.dir/Model/cuBlock/cuVariables.cxx.i

CMakeFiles/libcuBlock.dir/Model/cuBlock/cuVariables.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libcuBlock.dir/Model/cuBlock/cuVariables.cxx.s"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alberto/nea/aspis/cl/Model/cuBlock/cuVariables.cxx -o CMakeFiles/libcuBlock.dir/Model/cuBlock/cuVariables.cxx.s

CMakeFiles/libcuBlock.dir/Model/cuBlock/cuVariables.cxx.o.requires:

.PHONY : CMakeFiles/libcuBlock.dir/Model/cuBlock/cuVariables.cxx.o.requires

CMakeFiles/libcuBlock.dir/Model/cuBlock/cuVariables.cxx.o.provides: CMakeFiles/libcuBlock.dir/Model/cuBlock/cuVariables.cxx.o.requires
	$(MAKE) -f CMakeFiles/libcuBlock.dir/build.make CMakeFiles/libcuBlock.dir/Model/cuBlock/cuVariables.cxx.o.provides.build
.PHONY : CMakeFiles/libcuBlock.dir/Model/cuBlock/cuVariables.cxx.o.provides

CMakeFiles/libcuBlock.dir/Model/cuBlock/cuVariables.cxx.o.provides.build: CMakeFiles/libcuBlock.dir/Model/cuBlock/cuVariables.cxx.o


# Object files for target libcuBlock
libcuBlock_OBJECTS = \
"CMakeFiles/libcuBlock.dir/Model/cuBlock/makeCu.cxx.o" \
"CMakeFiles/libcuBlock.dir/Model/cuBlock/CuCollet.cxx.o" \
"CMakeFiles/libcuBlock.dir/Model/cuBlock/test.cxx.o" \
"CMakeFiles/libcuBlock.dir/Model/cuBlock/cuVariables.cxx.o"

# External object files for target libcuBlock
libcuBlock_EXTERNAL_OBJECTS =

lib/liblibcuBlock.so: CMakeFiles/libcuBlock.dir/Model/cuBlock/makeCu.cxx.o
lib/liblibcuBlock.so: CMakeFiles/libcuBlock.dir/Model/cuBlock/CuCollet.cxx.o
lib/liblibcuBlock.so: CMakeFiles/libcuBlock.dir/Model/cuBlock/test.cxx.o
lib/liblibcuBlock.so: CMakeFiles/libcuBlock.dir/Model/cuBlock/cuVariables.cxx.o
lib/liblibcuBlock.so: CMakeFiles/libcuBlock.dir/build.make
lib/liblibcuBlock.so: CMakeFiles/libcuBlock.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alberto/nea/aspis/cl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX shared library lib/liblibcuBlock.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/libcuBlock.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/libcuBlock.dir/build: lib/liblibcuBlock.so

.PHONY : CMakeFiles/libcuBlock.dir/build

CMakeFiles/libcuBlock.dir/requires: CMakeFiles/libcuBlock.dir/Model/cuBlock/makeCu.cxx.o.requires
CMakeFiles/libcuBlock.dir/requires: CMakeFiles/libcuBlock.dir/Model/cuBlock/CuCollet.cxx.o.requires
CMakeFiles/libcuBlock.dir/requires: CMakeFiles/libcuBlock.dir/Model/cuBlock/test.cxx.o.requires
CMakeFiles/libcuBlock.dir/requires: CMakeFiles/libcuBlock.dir/Model/cuBlock/cuVariables.cxx.o.requires

.PHONY : CMakeFiles/libcuBlock.dir/requires

CMakeFiles/libcuBlock.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/libcuBlock.dir/cmake_clean.cmake
.PHONY : CMakeFiles/libcuBlock.dir/clean

CMakeFiles/libcuBlock.dir/depend:
	cd /home/alberto/nea/aspis/cl && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alberto/nea/aspis/cl /home/alberto/nea/aspis/cl /home/alberto/nea/aspis/cl /home/alberto/nea/aspis/cl /home/alberto/nea/aspis/cl/CMakeFiles/libcuBlock.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/libcuBlock.dir/depend
