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
include CMakeFiles/libinput.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/libinput.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/libinput.dir/flags.make

CMakeFiles/libinput.dir/System/input/inputParam.cxx.o: CMakeFiles/libinput.dir/flags.make
CMakeFiles/libinput.dir/System/input/inputParam.cxx.o: System/input/inputParam.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alberto/nea/aspis/cl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/libinput.dir/System/input/inputParam.cxx.o"
	clang   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/libinput.dir/System/input/inputParam.cxx.o -c /home/alberto/nea/aspis/cl/System/input/inputParam.cxx

CMakeFiles/libinput.dir/System/input/inputParam.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libinput.dir/System/input/inputParam.cxx.i"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alberto/nea/aspis/cl/System/input/inputParam.cxx > CMakeFiles/libinput.dir/System/input/inputParam.cxx.i

CMakeFiles/libinput.dir/System/input/inputParam.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libinput.dir/System/input/inputParam.cxx.s"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alberto/nea/aspis/cl/System/input/inputParam.cxx -o CMakeFiles/libinput.dir/System/input/inputParam.cxx.s

CMakeFiles/libinput.dir/System/input/inputParam.cxx.o.requires:

.PHONY : CMakeFiles/libinput.dir/System/input/inputParam.cxx.o.requires

CMakeFiles/libinput.dir/System/input/inputParam.cxx.o.provides: CMakeFiles/libinput.dir/System/input/inputParam.cxx.o.requires
	$(MAKE) -f CMakeFiles/libinput.dir/build.make CMakeFiles/libinput.dir/System/input/inputParam.cxx.o.provides.build
.PHONY : CMakeFiles/libinput.dir/System/input/inputParam.cxx.o.provides

CMakeFiles/libinput.dir/System/input/inputParam.cxx.o.provides.build: CMakeFiles/libinput.dir/System/input/inputParam.cxx.o


CMakeFiles/libinput.dir/System/input/IItemBase.cxx.o: CMakeFiles/libinput.dir/flags.make
CMakeFiles/libinput.dir/System/input/IItemBase.cxx.o: System/input/IItemBase.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alberto/nea/aspis/cl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/libinput.dir/System/input/IItemBase.cxx.o"
	clang   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/libinput.dir/System/input/IItemBase.cxx.o -c /home/alberto/nea/aspis/cl/System/input/IItemBase.cxx

CMakeFiles/libinput.dir/System/input/IItemBase.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libinput.dir/System/input/IItemBase.cxx.i"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alberto/nea/aspis/cl/System/input/IItemBase.cxx > CMakeFiles/libinput.dir/System/input/IItemBase.cxx.i

CMakeFiles/libinput.dir/System/input/IItemBase.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libinput.dir/System/input/IItemBase.cxx.s"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alberto/nea/aspis/cl/System/input/IItemBase.cxx -o CMakeFiles/libinput.dir/System/input/IItemBase.cxx.s

CMakeFiles/libinput.dir/System/input/IItemBase.cxx.o.requires:

.PHONY : CMakeFiles/libinput.dir/System/input/IItemBase.cxx.o.requires

CMakeFiles/libinput.dir/System/input/IItemBase.cxx.o.provides: CMakeFiles/libinput.dir/System/input/IItemBase.cxx.o.requires
	$(MAKE) -f CMakeFiles/libinput.dir/build.make CMakeFiles/libinput.dir/System/input/IItemBase.cxx.o.provides.build
.PHONY : CMakeFiles/libinput.dir/System/input/IItemBase.cxx.o.provides

CMakeFiles/libinput.dir/System/input/IItemBase.cxx.o.provides.build: CMakeFiles/libinput.dir/System/input/IItemBase.cxx.o


# Object files for target libinput
libinput_OBJECTS = \
"CMakeFiles/libinput.dir/System/input/inputParam.cxx.o" \
"CMakeFiles/libinput.dir/System/input/IItemBase.cxx.o"

# External object files for target libinput
libinput_EXTERNAL_OBJECTS =

lib/liblibinput.so: CMakeFiles/libinput.dir/System/input/inputParam.cxx.o
lib/liblibinput.so: CMakeFiles/libinput.dir/System/input/IItemBase.cxx.o
lib/liblibinput.so: CMakeFiles/libinput.dir/build.make
lib/liblibinput.so: CMakeFiles/libinput.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alberto/nea/aspis/cl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX shared library lib/liblibinput.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/libinput.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/libinput.dir/build: lib/liblibinput.so

.PHONY : CMakeFiles/libinput.dir/build

CMakeFiles/libinput.dir/requires: CMakeFiles/libinput.dir/System/input/inputParam.cxx.o.requires
CMakeFiles/libinput.dir/requires: CMakeFiles/libinput.dir/System/input/IItemBase.cxx.o.requires

.PHONY : CMakeFiles/libinput.dir/requires

CMakeFiles/libinput.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/libinput.dir/cmake_clean.cmake
.PHONY : CMakeFiles/libinput.dir/clean

CMakeFiles/libinput.dir/depend:
	cd /home/alberto/nea/aspis/cl && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alberto/nea/aspis/cl /home/alberto/nea/aspis/cl /home/alberto/nea/aspis/cl /home/alberto/nea/aspis/cl /home/alberto/nea/aspis/cl/CMakeFiles/libinput.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/libinput.dir/depend

