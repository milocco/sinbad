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
include CMakeFiles/libCMakeFiles.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/libCMakeFiles.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/libCMakeFiles.dir/flags.make

CMakeFiles/libCMakeFiles.dir/CMakeFiles/feature_tests.cxx.o: CMakeFiles/libCMakeFiles.dir/flags.make
CMakeFiles/libCMakeFiles.dir/CMakeFiles/feature_tests.cxx.o: CMakeFiles/feature_tests.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alberto/nea/aspis/cl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/libCMakeFiles.dir/CMakeFiles/feature_tests.cxx.o"
	clang   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/libCMakeFiles.dir/CMakeFiles/feature_tests.cxx.o -c /home/alberto/nea/aspis/cl/CMakeFiles/feature_tests.cxx

CMakeFiles/libCMakeFiles.dir/CMakeFiles/feature_tests.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libCMakeFiles.dir/CMakeFiles/feature_tests.cxx.i"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alberto/nea/aspis/cl/CMakeFiles/feature_tests.cxx > CMakeFiles/libCMakeFiles.dir/CMakeFiles/feature_tests.cxx.i

CMakeFiles/libCMakeFiles.dir/CMakeFiles/feature_tests.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libCMakeFiles.dir/CMakeFiles/feature_tests.cxx.s"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alberto/nea/aspis/cl/CMakeFiles/feature_tests.cxx -o CMakeFiles/libCMakeFiles.dir/CMakeFiles/feature_tests.cxx.s

CMakeFiles/libCMakeFiles.dir/CMakeFiles/feature_tests.cxx.o.requires:

.PHONY : CMakeFiles/libCMakeFiles.dir/CMakeFiles/feature_tests.cxx.o.requires

CMakeFiles/libCMakeFiles.dir/CMakeFiles/feature_tests.cxx.o.provides: CMakeFiles/libCMakeFiles.dir/CMakeFiles/feature_tests.cxx.o.requires
	$(MAKE) -f CMakeFiles/libCMakeFiles.dir/build.make CMakeFiles/libCMakeFiles.dir/CMakeFiles/feature_tests.cxx.o.provides.build
.PHONY : CMakeFiles/libCMakeFiles.dir/CMakeFiles/feature_tests.cxx.o.provides

CMakeFiles/libCMakeFiles.dir/CMakeFiles/feature_tests.cxx.o.provides.build: CMakeFiles/libCMakeFiles.dir/CMakeFiles/feature_tests.cxx.o


# Object files for target libCMakeFiles
libCMakeFiles_OBJECTS = \
"CMakeFiles/libCMakeFiles.dir/CMakeFiles/feature_tests.cxx.o"

# External object files for target libCMakeFiles
libCMakeFiles_EXTERNAL_OBJECTS =

lib/liblibCMakeFiles.so: CMakeFiles/libCMakeFiles.dir/CMakeFiles/feature_tests.cxx.o
lib/liblibCMakeFiles.so: CMakeFiles/libCMakeFiles.dir/build.make
lib/liblibCMakeFiles.so: CMakeFiles/libCMakeFiles.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alberto/nea/aspis/cl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library lib/liblibCMakeFiles.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/libCMakeFiles.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/libCMakeFiles.dir/build: lib/liblibCMakeFiles.so

.PHONY : CMakeFiles/libCMakeFiles.dir/build

CMakeFiles/libCMakeFiles.dir/requires: CMakeFiles/libCMakeFiles.dir/CMakeFiles/feature_tests.cxx.o.requires

.PHONY : CMakeFiles/libCMakeFiles.dir/requires

CMakeFiles/libCMakeFiles.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/libCMakeFiles.dir/cmake_clean.cmake
.PHONY : CMakeFiles/libCMakeFiles.dir/clean

CMakeFiles/libCMakeFiles.dir/depend:
	cd /home/alberto/nea/aspis/cl && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alberto/nea/aspis/cl /home/alberto/nea/aspis/cl /home/alberto/nea/aspis/cl /home/alberto/nea/aspis/cl /home/alberto/nea/aspis/cl/CMakeFiles/libCMakeFiles.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/libCMakeFiles.dir/depend

