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
include CMakeFiles/libendf.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/libendf.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/libendf.dir/flags.make

CMakeFiles/libendf.dir/System/endf/ENDFmaterial.cxx.o: CMakeFiles/libendf.dir/flags.make
CMakeFiles/libendf.dir/System/endf/ENDFmaterial.cxx.o: System/endf/ENDFmaterial.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alberto/nea/aspis/cl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/libendf.dir/System/endf/ENDFmaterial.cxx.o"
	clang   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/libendf.dir/System/endf/ENDFmaterial.cxx.o -c /home/alberto/nea/aspis/cl/System/endf/ENDFmaterial.cxx

CMakeFiles/libendf.dir/System/endf/ENDFmaterial.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libendf.dir/System/endf/ENDFmaterial.cxx.i"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alberto/nea/aspis/cl/System/endf/ENDFmaterial.cxx > CMakeFiles/libendf.dir/System/endf/ENDFmaterial.cxx.i

CMakeFiles/libendf.dir/System/endf/ENDFmaterial.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libendf.dir/System/endf/ENDFmaterial.cxx.s"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alberto/nea/aspis/cl/System/endf/ENDFmaterial.cxx -o CMakeFiles/libendf.dir/System/endf/ENDFmaterial.cxx.s

CMakeFiles/libendf.dir/System/endf/ENDFmaterial.cxx.o.requires:

.PHONY : CMakeFiles/libendf.dir/System/endf/ENDFmaterial.cxx.o.requires

CMakeFiles/libendf.dir/System/endf/ENDFmaterial.cxx.o.provides: CMakeFiles/libendf.dir/System/endf/ENDFmaterial.cxx.o.requires
	$(MAKE) -f CMakeFiles/libendf.dir/build.make CMakeFiles/libendf.dir/System/endf/ENDFmaterial.cxx.o.provides.build
.PHONY : CMakeFiles/libendf.dir/System/endf/ENDFmaterial.cxx.o.provides

CMakeFiles/libendf.dir/System/endf/ENDFmaterial.cxx.o.provides.build: CMakeFiles/libendf.dir/System/endf/ENDFmaterial.cxx.o


CMakeFiles/libendf.dir/System/endf/ENDFreaction.cxx.o: CMakeFiles/libendf.dir/flags.make
CMakeFiles/libendf.dir/System/endf/ENDFreaction.cxx.o: System/endf/ENDFreaction.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alberto/nea/aspis/cl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/libendf.dir/System/endf/ENDFreaction.cxx.o"
	clang   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/libendf.dir/System/endf/ENDFreaction.cxx.o -c /home/alberto/nea/aspis/cl/System/endf/ENDFreaction.cxx

CMakeFiles/libendf.dir/System/endf/ENDFreaction.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libendf.dir/System/endf/ENDFreaction.cxx.i"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alberto/nea/aspis/cl/System/endf/ENDFreaction.cxx > CMakeFiles/libendf.dir/System/endf/ENDFreaction.cxx.i

CMakeFiles/libendf.dir/System/endf/ENDFreaction.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libendf.dir/System/endf/ENDFreaction.cxx.s"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alberto/nea/aspis/cl/System/endf/ENDFreaction.cxx -o CMakeFiles/libendf.dir/System/endf/ENDFreaction.cxx.s

CMakeFiles/libendf.dir/System/endf/ENDFreaction.cxx.o.requires:

.PHONY : CMakeFiles/libendf.dir/System/endf/ENDFreaction.cxx.o.requires

CMakeFiles/libendf.dir/System/endf/ENDFreaction.cxx.o.provides: CMakeFiles/libendf.dir/System/endf/ENDFreaction.cxx.o.requires
	$(MAKE) -f CMakeFiles/libendf.dir/build.make CMakeFiles/libendf.dir/System/endf/ENDFreaction.cxx.o.provides.build
.PHONY : CMakeFiles/libendf.dir/System/endf/ENDFreaction.cxx.o.provides

CMakeFiles/libendf.dir/System/endf/ENDFreaction.cxx.o.provides.build: CMakeFiles/libendf.dir/System/endf/ENDFreaction.cxx.o


CMakeFiles/libendf.dir/System/endf/SEtable.cxx.o: CMakeFiles/libendf.dir/flags.make
CMakeFiles/libendf.dir/System/endf/SEtable.cxx.o: System/endf/SEtable.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alberto/nea/aspis/cl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/libendf.dir/System/endf/SEtable.cxx.o"
	clang   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/libendf.dir/System/endf/SEtable.cxx.o -c /home/alberto/nea/aspis/cl/System/endf/SEtable.cxx

CMakeFiles/libendf.dir/System/endf/SEtable.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libendf.dir/System/endf/SEtable.cxx.i"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alberto/nea/aspis/cl/System/endf/SEtable.cxx > CMakeFiles/libendf.dir/System/endf/SEtable.cxx.i

CMakeFiles/libendf.dir/System/endf/SEtable.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libendf.dir/System/endf/SEtable.cxx.s"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alberto/nea/aspis/cl/System/endf/SEtable.cxx -o CMakeFiles/libendf.dir/System/endf/SEtable.cxx.s

CMakeFiles/libendf.dir/System/endf/SEtable.cxx.o.requires:

.PHONY : CMakeFiles/libendf.dir/System/endf/SEtable.cxx.o.requires

CMakeFiles/libendf.dir/System/endf/SEtable.cxx.o.provides: CMakeFiles/libendf.dir/System/endf/SEtable.cxx.o.requires
	$(MAKE) -f CMakeFiles/libendf.dir/build.make CMakeFiles/libendf.dir/System/endf/SEtable.cxx.o.provides.build
.PHONY : CMakeFiles/libendf.dir/System/endf/SEtable.cxx.o.provides

CMakeFiles/libendf.dir/System/endf/SEtable.cxx.o.provides.build: CMakeFiles/libendf.dir/System/endf/SEtable.cxx.o


CMakeFiles/libendf.dir/System/endf/SQWtable.cxx.o: CMakeFiles/libendf.dir/flags.make
CMakeFiles/libendf.dir/System/endf/SQWtable.cxx.o: System/endf/SQWtable.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alberto/nea/aspis/cl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/libendf.dir/System/endf/SQWtable.cxx.o"
	clang   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/libendf.dir/System/endf/SQWtable.cxx.o -c /home/alberto/nea/aspis/cl/System/endf/SQWtable.cxx

CMakeFiles/libendf.dir/System/endf/SQWtable.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libendf.dir/System/endf/SQWtable.cxx.i"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alberto/nea/aspis/cl/System/endf/SQWtable.cxx > CMakeFiles/libendf.dir/System/endf/SQWtable.cxx.i

CMakeFiles/libendf.dir/System/endf/SQWtable.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libendf.dir/System/endf/SQWtable.cxx.s"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alberto/nea/aspis/cl/System/endf/SQWtable.cxx -o CMakeFiles/libendf.dir/System/endf/SQWtable.cxx.s

CMakeFiles/libendf.dir/System/endf/SQWtable.cxx.o.requires:

.PHONY : CMakeFiles/libendf.dir/System/endf/SQWtable.cxx.o.requires

CMakeFiles/libendf.dir/System/endf/SQWtable.cxx.o.provides: CMakeFiles/libendf.dir/System/endf/SQWtable.cxx.o.requires
	$(MAKE) -f CMakeFiles/libendf.dir/build.make CMakeFiles/libendf.dir/System/endf/SQWtable.cxx.o.provides.build
.PHONY : CMakeFiles/libendf.dir/System/endf/SQWtable.cxx.o.provides

CMakeFiles/libendf.dir/System/endf/SQWtable.cxx.o.provides.build: CMakeFiles/libendf.dir/System/endf/SQWtable.cxx.o


CMakeFiles/libendf.dir/System/endf/ENDF.cxx.o: CMakeFiles/libendf.dir/flags.make
CMakeFiles/libendf.dir/System/endf/ENDF.cxx.o: System/endf/ENDF.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alberto/nea/aspis/cl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/libendf.dir/System/endf/ENDF.cxx.o"
	clang   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/libendf.dir/System/endf/ENDF.cxx.o -c /home/alberto/nea/aspis/cl/System/endf/ENDF.cxx

CMakeFiles/libendf.dir/System/endf/ENDF.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libendf.dir/System/endf/ENDF.cxx.i"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alberto/nea/aspis/cl/System/endf/ENDF.cxx > CMakeFiles/libendf.dir/System/endf/ENDF.cxx.i

CMakeFiles/libendf.dir/System/endf/ENDF.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libendf.dir/System/endf/ENDF.cxx.s"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alberto/nea/aspis/cl/System/endf/ENDF.cxx -o CMakeFiles/libendf.dir/System/endf/ENDF.cxx.s

CMakeFiles/libendf.dir/System/endf/ENDF.cxx.o.requires:

.PHONY : CMakeFiles/libendf.dir/System/endf/ENDF.cxx.o.requires

CMakeFiles/libendf.dir/System/endf/ENDF.cxx.o.provides: CMakeFiles/libendf.dir/System/endf/ENDF.cxx.o.requires
	$(MAKE) -f CMakeFiles/libendf.dir/build.make CMakeFiles/libendf.dir/System/endf/ENDF.cxx.o.provides.build
.PHONY : CMakeFiles/libendf.dir/System/endf/ENDF.cxx.o.provides

CMakeFiles/libendf.dir/System/endf/ENDF.cxx.o.provides.build: CMakeFiles/libendf.dir/System/endf/ENDF.cxx.o


# Object files for target libendf
libendf_OBJECTS = \
"CMakeFiles/libendf.dir/System/endf/ENDFmaterial.cxx.o" \
"CMakeFiles/libendf.dir/System/endf/ENDFreaction.cxx.o" \
"CMakeFiles/libendf.dir/System/endf/SEtable.cxx.o" \
"CMakeFiles/libendf.dir/System/endf/SQWtable.cxx.o" \
"CMakeFiles/libendf.dir/System/endf/ENDF.cxx.o"

# External object files for target libendf
libendf_EXTERNAL_OBJECTS =

lib/liblibendf.so: CMakeFiles/libendf.dir/System/endf/ENDFmaterial.cxx.o
lib/liblibendf.so: CMakeFiles/libendf.dir/System/endf/ENDFreaction.cxx.o
lib/liblibendf.so: CMakeFiles/libendf.dir/System/endf/SEtable.cxx.o
lib/liblibendf.so: CMakeFiles/libendf.dir/System/endf/SQWtable.cxx.o
lib/liblibendf.so: CMakeFiles/libendf.dir/System/endf/ENDF.cxx.o
lib/liblibendf.so: CMakeFiles/libendf.dir/build.make
lib/liblibendf.so: CMakeFiles/libendf.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alberto/nea/aspis/cl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX shared library lib/liblibendf.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/libendf.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/libendf.dir/build: lib/liblibendf.so

.PHONY : CMakeFiles/libendf.dir/build

CMakeFiles/libendf.dir/requires: CMakeFiles/libendf.dir/System/endf/ENDFmaterial.cxx.o.requires
CMakeFiles/libendf.dir/requires: CMakeFiles/libendf.dir/System/endf/ENDFreaction.cxx.o.requires
CMakeFiles/libendf.dir/requires: CMakeFiles/libendf.dir/System/endf/SEtable.cxx.o.requires
CMakeFiles/libendf.dir/requires: CMakeFiles/libendf.dir/System/endf/SQWtable.cxx.o.requires
CMakeFiles/libendf.dir/requires: CMakeFiles/libendf.dir/System/endf/ENDF.cxx.o.requires

.PHONY : CMakeFiles/libendf.dir/requires

CMakeFiles/libendf.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/libendf.dir/cmake_clean.cmake
.PHONY : CMakeFiles/libendf.dir/clean

CMakeFiles/libendf.dir/depend:
	cd /home/alberto/nea/aspis/cl && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alberto/nea/aspis/cl /home/alberto/nea/aspis/cl /home/alberto/nea/aspis/cl /home/alberto/nea/aspis/cl /home/alberto/nea/aspis/cl/CMakeFiles/libendf.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/libendf.dir/depend
