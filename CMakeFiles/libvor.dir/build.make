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
include CMakeFiles/libvor.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/libvor.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/libvor.dir/flags.make

CMakeFiles/libvor.dir/Model/ESSBeam/vor/DetectorTank.cxx.o: CMakeFiles/libvor.dir/flags.make
CMakeFiles/libvor.dir/Model/ESSBeam/vor/DetectorTank.cxx.o: Model/ESSBeam/vor/DetectorTank.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alberto/nea/aspis/cl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/libvor.dir/Model/ESSBeam/vor/DetectorTank.cxx.o"
	clang   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/libvor.dir/Model/ESSBeam/vor/DetectorTank.cxx.o -c /home/alberto/nea/aspis/cl/Model/ESSBeam/vor/DetectorTank.cxx

CMakeFiles/libvor.dir/Model/ESSBeam/vor/DetectorTank.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libvor.dir/Model/ESSBeam/vor/DetectorTank.cxx.i"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alberto/nea/aspis/cl/Model/ESSBeam/vor/DetectorTank.cxx > CMakeFiles/libvor.dir/Model/ESSBeam/vor/DetectorTank.cxx.i

CMakeFiles/libvor.dir/Model/ESSBeam/vor/DetectorTank.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libvor.dir/Model/ESSBeam/vor/DetectorTank.cxx.s"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alberto/nea/aspis/cl/Model/ESSBeam/vor/DetectorTank.cxx -o CMakeFiles/libvor.dir/Model/ESSBeam/vor/DetectorTank.cxx.s

CMakeFiles/libvor.dir/Model/ESSBeam/vor/DetectorTank.cxx.o.requires:

.PHONY : CMakeFiles/libvor.dir/Model/ESSBeam/vor/DetectorTank.cxx.o.requires

CMakeFiles/libvor.dir/Model/ESSBeam/vor/DetectorTank.cxx.o.provides: CMakeFiles/libvor.dir/Model/ESSBeam/vor/DetectorTank.cxx.o.requires
	$(MAKE) -f CMakeFiles/libvor.dir/build.make CMakeFiles/libvor.dir/Model/ESSBeam/vor/DetectorTank.cxx.o.provides.build
.PHONY : CMakeFiles/libvor.dir/Model/ESSBeam/vor/DetectorTank.cxx.o.provides

CMakeFiles/libvor.dir/Model/ESSBeam/vor/DetectorTank.cxx.o.provides.build: CMakeFiles/libvor.dir/Model/ESSBeam/vor/DetectorTank.cxx.o


CMakeFiles/libvor.dir/Model/ESSBeam/vor/VOR.cxx.o: CMakeFiles/libvor.dir/flags.make
CMakeFiles/libvor.dir/Model/ESSBeam/vor/VOR.cxx.o: Model/ESSBeam/vor/VOR.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alberto/nea/aspis/cl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/libvor.dir/Model/ESSBeam/vor/VOR.cxx.o"
	clang   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/libvor.dir/Model/ESSBeam/vor/VOR.cxx.o -c /home/alberto/nea/aspis/cl/Model/ESSBeam/vor/VOR.cxx

CMakeFiles/libvor.dir/Model/ESSBeam/vor/VOR.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libvor.dir/Model/ESSBeam/vor/VOR.cxx.i"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alberto/nea/aspis/cl/Model/ESSBeam/vor/VOR.cxx > CMakeFiles/libvor.dir/Model/ESSBeam/vor/VOR.cxx.i

CMakeFiles/libvor.dir/Model/ESSBeam/vor/VOR.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libvor.dir/Model/ESSBeam/vor/VOR.cxx.s"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alberto/nea/aspis/cl/Model/ESSBeam/vor/VOR.cxx -o CMakeFiles/libvor.dir/Model/ESSBeam/vor/VOR.cxx.s

CMakeFiles/libvor.dir/Model/ESSBeam/vor/VOR.cxx.o.requires:

.PHONY : CMakeFiles/libvor.dir/Model/ESSBeam/vor/VOR.cxx.o.requires

CMakeFiles/libvor.dir/Model/ESSBeam/vor/VOR.cxx.o.provides: CMakeFiles/libvor.dir/Model/ESSBeam/vor/VOR.cxx.o.requires
	$(MAKE) -f CMakeFiles/libvor.dir/build.make CMakeFiles/libvor.dir/Model/ESSBeam/vor/VOR.cxx.o.provides.build
.PHONY : CMakeFiles/libvor.dir/Model/ESSBeam/vor/VOR.cxx.o.provides

CMakeFiles/libvor.dir/Model/ESSBeam/vor/VOR.cxx.o.provides.build: CMakeFiles/libvor.dir/Model/ESSBeam/vor/VOR.cxx.o


CMakeFiles/libvor.dir/Model/ESSBeam/vor/DHut.cxx.o: CMakeFiles/libvor.dir/flags.make
CMakeFiles/libvor.dir/Model/ESSBeam/vor/DHut.cxx.o: Model/ESSBeam/vor/DHut.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alberto/nea/aspis/cl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/libvor.dir/Model/ESSBeam/vor/DHut.cxx.o"
	clang   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/libvor.dir/Model/ESSBeam/vor/DHut.cxx.o -c /home/alberto/nea/aspis/cl/Model/ESSBeam/vor/DHut.cxx

CMakeFiles/libvor.dir/Model/ESSBeam/vor/DHut.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libvor.dir/Model/ESSBeam/vor/DHut.cxx.i"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alberto/nea/aspis/cl/Model/ESSBeam/vor/DHut.cxx > CMakeFiles/libvor.dir/Model/ESSBeam/vor/DHut.cxx.i

CMakeFiles/libvor.dir/Model/ESSBeam/vor/DHut.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libvor.dir/Model/ESSBeam/vor/DHut.cxx.s"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alberto/nea/aspis/cl/Model/ESSBeam/vor/DHut.cxx -o CMakeFiles/libvor.dir/Model/ESSBeam/vor/DHut.cxx.s

CMakeFiles/libvor.dir/Model/ESSBeam/vor/DHut.cxx.o.requires:

.PHONY : CMakeFiles/libvor.dir/Model/ESSBeam/vor/DHut.cxx.o.requires

CMakeFiles/libvor.dir/Model/ESSBeam/vor/DHut.cxx.o.provides: CMakeFiles/libvor.dir/Model/ESSBeam/vor/DHut.cxx.o.requires
	$(MAKE) -f CMakeFiles/libvor.dir/build.make CMakeFiles/libvor.dir/Model/ESSBeam/vor/DHut.cxx.o.provides.build
.PHONY : CMakeFiles/libvor.dir/Model/ESSBeam/vor/DHut.cxx.o.provides

CMakeFiles/libvor.dir/Model/ESSBeam/vor/DHut.cxx.o.provides.build: CMakeFiles/libvor.dir/Model/ESSBeam/vor/DHut.cxx.o


CMakeFiles/libvor.dir/Model/ESSBeam/vor/VORvariables.cxx.o: CMakeFiles/libvor.dir/flags.make
CMakeFiles/libvor.dir/Model/ESSBeam/vor/VORvariables.cxx.o: Model/ESSBeam/vor/VORvariables.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alberto/nea/aspis/cl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/libvor.dir/Model/ESSBeam/vor/VORvariables.cxx.o"
	clang   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/libvor.dir/Model/ESSBeam/vor/VORvariables.cxx.o -c /home/alberto/nea/aspis/cl/Model/ESSBeam/vor/VORvariables.cxx

CMakeFiles/libvor.dir/Model/ESSBeam/vor/VORvariables.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libvor.dir/Model/ESSBeam/vor/VORvariables.cxx.i"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alberto/nea/aspis/cl/Model/ESSBeam/vor/VORvariables.cxx > CMakeFiles/libvor.dir/Model/ESSBeam/vor/VORvariables.cxx.i

CMakeFiles/libvor.dir/Model/ESSBeam/vor/VORvariables.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libvor.dir/Model/ESSBeam/vor/VORvariables.cxx.s"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alberto/nea/aspis/cl/Model/ESSBeam/vor/VORvariables.cxx -o CMakeFiles/libvor.dir/Model/ESSBeam/vor/VORvariables.cxx.s

CMakeFiles/libvor.dir/Model/ESSBeam/vor/VORvariables.cxx.o.requires:

.PHONY : CMakeFiles/libvor.dir/Model/ESSBeam/vor/VORvariables.cxx.o.requires

CMakeFiles/libvor.dir/Model/ESSBeam/vor/VORvariables.cxx.o.provides: CMakeFiles/libvor.dir/Model/ESSBeam/vor/VORvariables.cxx.o.requires
	$(MAKE) -f CMakeFiles/libvor.dir/build.make CMakeFiles/libvor.dir/Model/ESSBeam/vor/VORvariables.cxx.o.provides.build
.PHONY : CMakeFiles/libvor.dir/Model/ESSBeam/vor/VORvariables.cxx.o.provides

CMakeFiles/libvor.dir/Model/ESSBeam/vor/VORvariables.cxx.o.provides.build: CMakeFiles/libvor.dir/Model/ESSBeam/vor/VORvariables.cxx.o


# Object files for target libvor
libvor_OBJECTS = \
"CMakeFiles/libvor.dir/Model/ESSBeam/vor/DetectorTank.cxx.o" \
"CMakeFiles/libvor.dir/Model/ESSBeam/vor/VOR.cxx.o" \
"CMakeFiles/libvor.dir/Model/ESSBeam/vor/DHut.cxx.o" \
"CMakeFiles/libvor.dir/Model/ESSBeam/vor/VORvariables.cxx.o"

# External object files for target libvor
libvor_EXTERNAL_OBJECTS =

lib/liblibvor.so: CMakeFiles/libvor.dir/Model/ESSBeam/vor/DetectorTank.cxx.o
lib/liblibvor.so: CMakeFiles/libvor.dir/Model/ESSBeam/vor/VOR.cxx.o
lib/liblibvor.so: CMakeFiles/libvor.dir/Model/ESSBeam/vor/DHut.cxx.o
lib/liblibvor.so: CMakeFiles/libvor.dir/Model/ESSBeam/vor/VORvariables.cxx.o
lib/liblibvor.so: CMakeFiles/libvor.dir/build.make
lib/liblibvor.so: CMakeFiles/libvor.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alberto/nea/aspis/cl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX shared library lib/liblibvor.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/libvor.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/libvor.dir/build: lib/liblibvor.so

.PHONY : CMakeFiles/libvor.dir/build

CMakeFiles/libvor.dir/requires: CMakeFiles/libvor.dir/Model/ESSBeam/vor/DetectorTank.cxx.o.requires
CMakeFiles/libvor.dir/requires: CMakeFiles/libvor.dir/Model/ESSBeam/vor/VOR.cxx.o.requires
CMakeFiles/libvor.dir/requires: CMakeFiles/libvor.dir/Model/ESSBeam/vor/DHut.cxx.o.requires
CMakeFiles/libvor.dir/requires: CMakeFiles/libvor.dir/Model/ESSBeam/vor/VORvariables.cxx.o.requires

.PHONY : CMakeFiles/libvor.dir/requires

CMakeFiles/libvor.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/libvor.dir/cmake_clean.cmake
.PHONY : CMakeFiles/libvor.dir/clean

CMakeFiles/libvor.dir/depend:
	cd /home/alberto/nea/aspis/cl && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alberto/nea/aspis/cl /home/alberto/nea/aspis/cl /home/alberto/nea/aspis/cl /home/alberto/nea/aspis/cl /home/alberto/nea/aspis/cl/CMakeFiles/libvor.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/libvor.dir/depend
