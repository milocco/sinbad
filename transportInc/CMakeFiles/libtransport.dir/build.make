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
include CMakeFiles/libtransport.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/libtransport.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/libtransport.dir/flags.make

CMakeFiles/libtransport.dir/transport/DetGroup.cxx.o: CMakeFiles/libtransport.dir/flags.make
CMakeFiles/libtransport.dir/transport/DetGroup.cxx.o: transport/DetGroup.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alberto/nea/aspis/cl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/libtransport.dir/transport/DetGroup.cxx.o"
	clang   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/libtransport.dir/transport/DetGroup.cxx.o -c /home/alberto/nea/aspis/cl/transport/DetGroup.cxx

CMakeFiles/libtransport.dir/transport/DetGroup.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libtransport.dir/transport/DetGroup.cxx.i"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alberto/nea/aspis/cl/transport/DetGroup.cxx > CMakeFiles/libtransport.dir/transport/DetGroup.cxx.i

CMakeFiles/libtransport.dir/transport/DetGroup.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libtransport.dir/transport/DetGroup.cxx.s"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alberto/nea/aspis/cl/transport/DetGroup.cxx -o CMakeFiles/libtransport.dir/transport/DetGroup.cxx.s

CMakeFiles/libtransport.dir/transport/DetGroup.cxx.o.requires:

.PHONY : CMakeFiles/libtransport.dir/transport/DetGroup.cxx.o.requires

CMakeFiles/libtransport.dir/transport/DetGroup.cxx.o.provides: CMakeFiles/libtransport.dir/transport/DetGroup.cxx.o.requires
	$(MAKE) -f CMakeFiles/libtransport.dir/build.make CMakeFiles/libtransport.dir/transport/DetGroup.cxx.o.provides.build
.PHONY : CMakeFiles/libtransport.dir/transport/DetGroup.cxx.o.provides

CMakeFiles/libtransport.dir/transport/DetGroup.cxx.o.provides.build: CMakeFiles/libtransport.dir/transport/DetGroup.cxx.o


CMakeFiles/libtransport.dir/transport/PointDetector.cxx.o: CMakeFiles/libtransport.dir/flags.make
CMakeFiles/libtransport.dir/transport/PointDetector.cxx.o: transport/PointDetector.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alberto/nea/aspis/cl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/libtransport.dir/transport/PointDetector.cxx.o"
	clang   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/libtransport.dir/transport/PointDetector.cxx.o -c /home/alberto/nea/aspis/cl/transport/PointDetector.cxx

CMakeFiles/libtransport.dir/transport/PointDetector.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libtransport.dir/transport/PointDetector.cxx.i"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alberto/nea/aspis/cl/transport/PointDetector.cxx > CMakeFiles/libtransport.dir/transport/PointDetector.cxx.i

CMakeFiles/libtransport.dir/transport/PointDetector.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libtransport.dir/transport/PointDetector.cxx.s"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alberto/nea/aspis/cl/transport/PointDetector.cxx -o CMakeFiles/libtransport.dir/transport/PointDetector.cxx.s

CMakeFiles/libtransport.dir/transport/PointDetector.cxx.o.requires:

.PHONY : CMakeFiles/libtransport.dir/transport/PointDetector.cxx.o.requires

CMakeFiles/libtransport.dir/transport/PointDetector.cxx.o.provides: CMakeFiles/libtransport.dir/transport/PointDetector.cxx.o.requires
	$(MAKE) -f CMakeFiles/libtransport.dir/build.make CMakeFiles/libtransport.dir/transport/PointDetector.cxx.o.provides.build
.PHONY : CMakeFiles/libtransport.dir/transport/PointDetector.cxx.o.provides

CMakeFiles/libtransport.dir/transport/PointDetector.cxx.o.provides.build: CMakeFiles/libtransport.dir/transport/PointDetector.cxx.o


CMakeFiles/libtransport.dir/transport/AreaBeam.cxx.o: CMakeFiles/libtransport.dir/flags.make
CMakeFiles/libtransport.dir/transport/AreaBeam.cxx.o: transport/AreaBeam.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alberto/nea/aspis/cl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/libtransport.dir/transport/AreaBeam.cxx.o"
	clang   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/libtransport.dir/transport/AreaBeam.cxx.o -c /home/alberto/nea/aspis/cl/transport/AreaBeam.cxx

CMakeFiles/libtransport.dir/transport/AreaBeam.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libtransport.dir/transport/AreaBeam.cxx.i"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alberto/nea/aspis/cl/transport/AreaBeam.cxx > CMakeFiles/libtransport.dir/transport/AreaBeam.cxx.i

CMakeFiles/libtransport.dir/transport/AreaBeam.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libtransport.dir/transport/AreaBeam.cxx.s"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alberto/nea/aspis/cl/transport/AreaBeam.cxx -o CMakeFiles/libtransport.dir/transport/AreaBeam.cxx.s

CMakeFiles/libtransport.dir/transport/AreaBeam.cxx.o.requires:

.PHONY : CMakeFiles/libtransport.dir/transport/AreaBeam.cxx.o.requires

CMakeFiles/libtransport.dir/transport/AreaBeam.cxx.o.provides: CMakeFiles/libtransport.dir/transport/AreaBeam.cxx.o.requires
	$(MAKE) -f CMakeFiles/libtransport.dir/build.make CMakeFiles/libtransport.dir/transport/AreaBeam.cxx.o.provides.build
.PHONY : CMakeFiles/libtransport.dir/transport/AreaBeam.cxx.o.provides

CMakeFiles/libtransport.dir/transport/AreaBeam.cxx.o.provides.build: CMakeFiles/libtransport.dir/transport/AreaBeam.cxx.o


CMakeFiles/libtransport.dir/transport/ObjComponent.cxx.o: CMakeFiles/libtransport.dir/flags.make
CMakeFiles/libtransport.dir/transport/ObjComponent.cxx.o: transport/ObjComponent.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alberto/nea/aspis/cl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/libtransport.dir/transport/ObjComponent.cxx.o"
	clang   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/libtransport.dir/transport/ObjComponent.cxx.o -c /home/alberto/nea/aspis/cl/transport/ObjComponent.cxx

CMakeFiles/libtransport.dir/transport/ObjComponent.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libtransport.dir/transport/ObjComponent.cxx.i"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alberto/nea/aspis/cl/transport/ObjComponent.cxx > CMakeFiles/libtransport.dir/transport/ObjComponent.cxx.i

CMakeFiles/libtransport.dir/transport/ObjComponent.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libtransport.dir/transport/ObjComponent.cxx.s"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alberto/nea/aspis/cl/transport/ObjComponent.cxx -o CMakeFiles/libtransport.dir/transport/ObjComponent.cxx.s

CMakeFiles/libtransport.dir/transport/ObjComponent.cxx.o.requires:

.PHONY : CMakeFiles/libtransport.dir/transport/ObjComponent.cxx.o.requires

CMakeFiles/libtransport.dir/transport/ObjComponent.cxx.o.provides: CMakeFiles/libtransport.dir/transport/ObjComponent.cxx.o.requires
	$(MAKE) -f CMakeFiles/libtransport.dir/build.make CMakeFiles/libtransport.dir/transport/ObjComponent.cxx.o.provides.build
.PHONY : CMakeFiles/libtransport.dir/transport/ObjComponent.cxx.o.provides

CMakeFiles/libtransport.dir/transport/ObjComponent.cxx.o.provides.build: CMakeFiles/libtransport.dir/transport/ObjComponent.cxx.o


CMakeFiles/libtransport.dir/transport/VolumeBeam.cxx.o: CMakeFiles/libtransport.dir/flags.make
CMakeFiles/libtransport.dir/transport/VolumeBeam.cxx.o: transport/VolumeBeam.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alberto/nea/aspis/cl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/libtransport.dir/transport/VolumeBeam.cxx.o"
	clang   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/libtransport.dir/transport/VolumeBeam.cxx.o -c /home/alberto/nea/aspis/cl/transport/VolumeBeam.cxx

CMakeFiles/libtransport.dir/transport/VolumeBeam.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libtransport.dir/transport/VolumeBeam.cxx.i"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alberto/nea/aspis/cl/transport/VolumeBeam.cxx > CMakeFiles/libtransport.dir/transport/VolumeBeam.cxx.i

CMakeFiles/libtransport.dir/transport/VolumeBeam.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libtransport.dir/transport/VolumeBeam.cxx.s"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alberto/nea/aspis/cl/transport/VolumeBeam.cxx -o CMakeFiles/libtransport.dir/transport/VolumeBeam.cxx.s

CMakeFiles/libtransport.dir/transport/VolumeBeam.cxx.o.requires:

.PHONY : CMakeFiles/libtransport.dir/transport/VolumeBeam.cxx.o.requires

CMakeFiles/libtransport.dir/transport/VolumeBeam.cxx.o.provides: CMakeFiles/libtransport.dir/transport/VolumeBeam.cxx.o.requires
	$(MAKE) -f CMakeFiles/libtransport.dir/build.make CMakeFiles/libtransport.dir/transport/VolumeBeam.cxx.o.provides.build
.PHONY : CMakeFiles/libtransport.dir/transport/VolumeBeam.cxx.o.provides

CMakeFiles/libtransport.dir/transport/VolumeBeam.cxx.o.provides.build: CMakeFiles/libtransport.dir/transport/VolumeBeam.cxx.o


CMakeFiles/libtransport.dir/transport/Detector.cxx.o: CMakeFiles/libtransport.dir/flags.make
CMakeFiles/libtransport.dir/transport/Detector.cxx.o: transport/Detector.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alberto/nea/aspis/cl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/libtransport.dir/transport/Detector.cxx.o"
	clang   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/libtransport.dir/transport/Detector.cxx.o -c /home/alberto/nea/aspis/cl/transport/Detector.cxx

CMakeFiles/libtransport.dir/transport/Detector.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libtransport.dir/transport/Detector.cxx.i"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alberto/nea/aspis/cl/transport/Detector.cxx > CMakeFiles/libtransport.dir/transport/Detector.cxx.i

CMakeFiles/libtransport.dir/transport/Detector.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libtransport.dir/transport/Detector.cxx.s"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alberto/nea/aspis/cl/transport/Detector.cxx -o CMakeFiles/libtransport.dir/transport/Detector.cxx.s

CMakeFiles/libtransport.dir/transport/Detector.cxx.o.requires:

.PHONY : CMakeFiles/libtransport.dir/transport/Detector.cxx.o.requires

CMakeFiles/libtransport.dir/transport/Detector.cxx.o.provides: CMakeFiles/libtransport.dir/transport/Detector.cxx.o.requires
	$(MAKE) -f CMakeFiles/libtransport.dir/build.make CMakeFiles/libtransport.dir/transport/Detector.cxx.o.provides.build
.PHONY : CMakeFiles/libtransport.dir/transport/Detector.cxx.o.provides

CMakeFiles/libtransport.dir/transport/Detector.cxx.o.provides.build: CMakeFiles/libtransport.dir/transport/Detector.cxx.o


CMakeFiles/libtransport.dir/transport/BandDetector.cxx.o: CMakeFiles/libtransport.dir/flags.make
CMakeFiles/libtransport.dir/transport/BandDetector.cxx.o: transport/BandDetector.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alberto/nea/aspis/cl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/libtransport.dir/transport/BandDetector.cxx.o"
	clang   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/libtransport.dir/transport/BandDetector.cxx.o -c /home/alberto/nea/aspis/cl/transport/BandDetector.cxx

CMakeFiles/libtransport.dir/transport/BandDetector.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libtransport.dir/transport/BandDetector.cxx.i"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alberto/nea/aspis/cl/transport/BandDetector.cxx > CMakeFiles/libtransport.dir/transport/BandDetector.cxx.i

CMakeFiles/libtransport.dir/transport/BandDetector.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libtransport.dir/transport/BandDetector.cxx.s"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alberto/nea/aspis/cl/transport/BandDetector.cxx -o CMakeFiles/libtransport.dir/transport/BandDetector.cxx.s

CMakeFiles/libtransport.dir/transport/BandDetector.cxx.o.requires:

.PHONY : CMakeFiles/libtransport.dir/transport/BandDetector.cxx.o.requires

CMakeFiles/libtransport.dir/transport/BandDetector.cxx.o.provides: CMakeFiles/libtransport.dir/transport/BandDetector.cxx.o.requires
	$(MAKE) -f CMakeFiles/libtransport.dir/build.make CMakeFiles/libtransport.dir/transport/BandDetector.cxx.o.provides.build
.PHONY : CMakeFiles/libtransport.dir/transport/BandDetector.cxx.o.provides

CMakeFiles/libtransport.dir/transport/BandDetector.cxx.o.provides.build: CMakeFiles/libtransport.dir/transport/BandDetector.cxx.o


# Object files for target libtransport
libtransport_OBJECTS = \
"CMakeFiles/libtransport.dir/transport/DetGroup.cxx.o" \
"CMakeFiles/libtransport.dir/transport/PointDetector.cxx.o" \
"CMakeFiles/libtransport.dir/transport/AreaBeam.cxx.o" \
"CMakeFiles/libtransport.dir/transport/ObjComponent.cxx.o" \
"CMakeFiles/libtransport.dir/transport/VolumeBeam.cxx.o" \
"CMakeFiles/libtransport.dir/transport/Detector.cxx.o" \
"CMakeFiles/libtransport.dir/transport/BandDetector.cxx.o"

# External object files for target libtransport
libtransport_EXTERNAL_OBJECTS =

lib/liblibtransport.so: CMakeFiles/libtransport.dir/transport/DetGroup.cxx.o
lib/liblibtransport.so: CMakeFiles/libtransport.dir/transport/PointDetector.cxx.o
lib/liblibtransport.so: CMakeFiles/libtransport.dir/transport/AreaBeam.cxx.o
lib/liblibtransport.so: CMakeFiles/libtransport.dir/transport/ObjComponent.cxx.o
lib/liblibtransport.so: CMakeFiles/libtransport.dir/transport/VolumeBeam.cxx.o
lib/liblibtransport.so: CMakeFiles/libtransport.dir/transport/Detector.cxx.o
lib/liblibtransport.so: CMakeFiles/libtransport.dir/transport/BandDetector.cxx.o
lib/liblibtransport.so: CMakeFiles/libtransport.dir/build.make
lib/liblibtransport.so: CMakeFiles/libtransport.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alberto/nea/aspis/cl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX shared library lib/liblibtransport.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/libtransport.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/libtransport.dir/build: lib/liblibtransport.so

.PHONY : CMakeFiles/libtransport.dir/build

CMakeFiles/libtransport.dir/requires: CMakeFiles/libtransport.dir/transport/DetGroup.cxx.o.requires
CMakeFiles/libtransport.dir/requires: CMakeFiles/libtransport.dir/transport/PointDetector.cxx.o.requires
CMakeFiles/libtransport.dir/requires: CMakeFiles/libtransport.dir/transport/AreaBeam.cxx.o.requires
CMakeFiles/libtransport.dir/requires: CMakeFiles/libtransport.dir/transport/ObjComponent.cxx.o.requires
CMakeFiles/libtransport.dir/requires: CMakeFiles/libtransport.dir/transport/VolumeBeam.cxx.o.requires
CMakeFiles/libtransport.dir/requires: CMakeFiles/libtransport.dir/transport/Detector.cxx.o.requires
CMakeFiles/libtransport.dir/requires: CMakeFiles/libtransport.dir/transport/BandDetector.cxx.o.requires

.PHONY : CMakeFiles/libtransport.dir/requires

CMakeFiles/libtransport.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/libtransport.dir/cmake_clean.cmake
.PHONY : CMakeFiles/libtransport.dir/clean

CMakeFiles/libtransport.dir/depend:
	cd /home/alberto/nea/aspis/cl && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alberto/nea/aspis/cl /home/alberto/nea/aspis/cl /home/alberto/nea/aspis/cl /home/alberto/nea/aspis/cl /home/alberto/nea/aspis/cl/CMakeFiles/libtransport.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/libtransport.dir/depend

