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
include CMakeFiles/libscatMat.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/libscatMat.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/libscatMat.dir/flags.make

CMakeFiles/libscatMat.dir/scatMat/DBNeutMaterial.cxx.o: CMakeFiles/libscatMat.dir/flags.make
CMakeFiles/libscatMat.dir/scatMat/DBNeutMaterial.cxx.o: scatMat/DBNeutMaterial.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alberto/nea/aspis/cl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/libscatMat.dir/scatMat/DBNeutMaterial.cxx.o"
	clang   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/libscatMat.dir/scatMat/DBNeutMaterial.cxx.o -c /home/alberto/nea/aspis/cl/scatMat/DBNeutMaterial.cxx

CMakeFiles/libscatMat.dir/scatMat/DBNeutMaterial.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libscatMat.dir/scatMat/DBNeutMaterial.cxx.i"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alberto/nea/aspis/cl/scatMat/DBNeutMaterial.cxx > CMakeFiles/libscatMat.dir/scatMat/DBNeutMaterial.cxx.i

CMakeFiles/libscatMat.dir/scatMat/DBNeutMaterial.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libscatMat.dir/scatMat/DBNeutMaterial.cxx.s"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alberto/nea/aspis/cl/scatMat/DBNeutMaterial.cxx -o CMakeFiles/libscatMat.dir/scatMat/DBNeutMaterial.cxx.s

CMakeFiles/libscatMat.dir/scatMat/DBNeutMaterial.cxx.o.requires:

.PHONY : CMakeFiles/libscatMat.dir/scatMat/DBNeutMaterial.cxx.o.requires

CMakeFiles/libscatMat.dir/scatMat/DBNeutMaterial.cxx.o.provides: CMakeFiles/libscatMat.dir/scatMat/DBNeutMaterial.cxx.o.requires
	$(MAKE) -f CMakeFiles/libscatMat.dir/build.make CMakeFiles/libscatMat.dir/scatMat/DBNeutMaterial.cxx.o.provides.build
.PHONY : CMakeFiles/libscatMat.dir/scatMat/DBNeutMaterial.cxx.o.provides

CMakeFiles/libscatMat.dir/scatMat/DBNeutMaterial.cxx.o.provides.build: CMakeFiles/libscatMat.dir/scatMat/DBNeutMaterial.cxx.o


CMakeFiles/libscatMat.dir/scatMat/SQWmaterial.cxx.o: CMakeFiles/libscatMat.dir/flags.make
CMakeFiles/libscatMat.dir/scatMat/SQWmaterial.cxx.o: scatMat/SQWmaterial.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alberto/nea/aspis/cl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/libscatMat.dir/scatMat/SQWmaterial.cxx.o"
	clang   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/libscatMat.dir/scatMat/SQWmaterial.cxx.o -c /home/alberto/nea/aspis/cl/scatMat/SQWmaterial.cxx

CMakeFiles/libscatMat.dir/scatMat/SQWmaterial.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libscatMat.dir/scatMat/SQWmaterial.cxx.i"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alberto/nea/aspis/cl/scatMat/SQWmaterial.cxx > CMakeFiles/libscatMat.dir/scatMat/SQWmaterial.cxx.i

CMakeFiles/libscatMat.dir/scatMat/SQWmaterial.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libscatMat.dir/scatMat/SQWmaterial.cxx.s"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alberto/nea/aspis/cl/scatMat/SQWmaterial.cxx -o CMakeFiles/libscatMat.dir/scatMat/SQWmaterial.cxx.s

CMakeFiles/libscatMat.dir/scatMat/SQWmaterial.cxx.o.requires:

.PHONY : CMakeFiles/libscatMat.dir/scatMat/SQWmaterial.cxx.o.requires

CMakeFiles/libscatMat.dir/scatMat/SQWmaterial.cxx.o.provides: CMakeFiles/libscatMat.dir/scatMat/SQWmaterial.cxx.o.requires
	$(MAKE) -f CMakeFiles/libscatMat.dir/build.make CMakeFiles/libscatMat.dir/scatMat/SQWmaterial.cxx.o.provides.build
.PHONY : CMakeFiles/libscatMat.dir/scatMat/SQWmaterial.cxx.o.provides

CMakeFiles/libscatMat.dir/scatMat/SQWmaterial.cxx.o.provides.build: CMakeFiles/libscatMat.dir/scatMat/SQWmaterial.cxx.o


CMakeFiles/libscatMat.dir/scatMat/neutMaterial.cxx.o: CMakeFiles/libscatMat.dir/flags.make
CMakeFiles/libscatMat.dir/scatMat/neutMaterial.cxx.o: scatMat/neutMaterial.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alberto/nea/aspis/cl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/libscatMat.dir/scatMat/neutMaterial.cxx.o"
	clang   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/libscatMat.dir/scatMat/neutMaterial.cxx.o -c /home/alberto/nea/aspis/cl/scatMat/neutMaterial.cxx

CMakeFiles/libscatMat.dir/scatMat/neutMaterial.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libscatMat.dir/scatMat/neutMaterial.cxx.i"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alberto/nea/aspis/cl/scatMat/neutMaterial.cxx > CMakeFiles/libscatMat.dir/scatMat/neutMaterial.cxx.i

CMakeFiles/libscatMat.dir/scatMat/neutMaterial.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libscatMat.dir/scatMat/neutMaterial.cxx.s"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alberto/nea/aspis/cl/scatMat/neutMaterial.cxx -o CMakeFiles/libscatMat.dir/scatMat/neutMaterial.cxx.s

CMakeFiles/libscatMat.dir/scatMat/neutMaterial.cxx.o.requires:

.PHONY : CMakeFiles/libscatMat.dir/scatMat/neutMaterial.cxx.o.requires

CMakeFiles/libscatMat.dir/scatMat/neutMaterial.cxx.o.provides: CMakeFiles/libscatMat.dir/scatMat/neutMaterial.cxx.o.requires
	$(MAKE) -f CMakeFiles/libscatMat.dir/build.make CMakeFiles/libscatMat.dir/scatMat/neutMaterial.cxx.o.provides.build
.PHONY : CMakeFiles/libscatMat.dir/scatMat/neutMaterial.cxx.o.provides

CMakeFiles/libscatMat.dir/scatMat/neutMaterial.cxx.o.provides.build: CMakeFiles/libscatMat.dir/scatMat/neutMaterial.cxx.o


CMakeFiles/libscatMat.dir/scatMat/CryMat.cxx.o: CMakeFiles/libscatMat.dir/flags.make
CMakeFiles/libscatMat.dir/scatMat/CryMat.cxx.o: scatMat/CryMat.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alberto/nea/aspis/cl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/libscatMat.dir/scatMat/CryMat.cxx.o"
	clang   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/libscatMat.dir/scatMat/CryMat.cxx.o -c /home/alberto/nea/aspis/cl/scatMat/CryMat.cxx

CMakeFiles/libscatMat.dir/scatMat/CryMat.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libscatMat.dir/scatMat/CryMat.cxx.i"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alberto/nea/aspis/cl/scatMat/CryMat.cxx > CMakeFiles/libscatMat.dir/scatMat/CryMat.cxx.i

CMakeFiles/libscatMat.dir/scatMat/CryMat.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libscatMat.dir/scatMat/CryMat.cxx.s"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alberto/nea/aspis/cl/scatMat/CryMat.cxx -o CMakeFiles/libscatMat.dir/scatMat/CryMat.cxx.s

CMakeFiles/libscatMat.dir/scatMat/CryMat.cxx.o.requires:

.PHONY : CMakeFiles/libscatMat.dir/scatMat/CryMat.cxx.o.requires

CMakeFiles/libscatMat.dir/scatMat/CryMat.cxx.o.provides: CMakeFiles/libscatMat.dir/scatMat/CryMat.cxx.o.requires
	$(MAKE) -f CMakeFiles/libscatMat.dir/build.make CMakeFiles/libscatMat.dir/scatMat/CryMat.cxx.o.provides.build
.PHONY : CMakeFiles/libscatMat.dir/scatMat/CryMat.cxx.o.provides

CMakeFiles/libscatMat.dir/scatMat/CryMat.cxx.o.provides.build: CMakeFiles/libscatMat.dir/scatMat/CryMat.cxx.o


CMakeFiles/libscatMat.dir/scatMat/GlassMaterial.cxx.o: CMakeFiles/libscatMat.dir/flags.make
CMakeFiles/libscatMat.dir/scatMat/GlassMaterial.cxx.o: scatMat/GlassMaterial.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alberto/nea/aspis/cl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/libscatMat.dir/scatMat/GlassMaterial.cxx.o"
	clang   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/libscatMat.dir/scatMat/GlassMaterial.cxx.o -c /home/alberto/nea/aspis/cl/scatMat/GlassMaterial.cxx

CMakeFiles/libscatMat.dir/scatMat/GlassMaterial.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libscatMat.dir/scatMat/GlassMaterial.cxx.i"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alberto/nea/aspis/cl/scatMat/GlassMaterial.cxx > CMakeFiles/libscatMat.dir/scatMat/GlassMaterial.cxx.i

CMakeFiles/libscatMat.dir/scatMat/GlassMaterial.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libscatMat.dir/scatMat/GlassMaterial.cxx.s"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alberto/nea/aspis/cl/scatMat/GlassMaterial.cxx -o CMakeFiles/libscatMat.dir/scatMat/GlassMaterial.cxx.s

CMakeFiles/libscatMat.dir/scatMat/GlassMaterial.cxx.o.requires:

.PHONY : CMakeFiles/libscatMat.dir/scatMat/GlassMaterial.cxx.o.requires

CMakeFiles/libscatMat.dir/scatMat/GlassMaterial.cxx.o.provides: CMakeFiles/libscatMat.dir/scatMat/GlassMaterial.cxx.o.requires
	$(MAKE) -f CMakeFiles/libscatMat.dir/build.make CMakeFiles/libscatMat.dir/scatMat/GlassMaterial.cxx.o.provides.build
.PHONY : CMakeFiles/libscatMat.dir/scatMat/GlassMaterial.cxx.o.provides

CMakeFiles/libscatMat.dir/scatMat/GlassMaterial.cxx.o.provides.build: CMakeFiles/libscatMat.dir/scatMat/GlassMaterial.cxx.o


# Object files for target libscatMat
libscatMat_OBJECTS = \
"CMakeFiles/libscatMat.dir/scatMat/DBNeutMaterial.cxx.o" \
"CMakeFiles/libscatMat.dir/scatMat/SQWmaterial.cxx.o" \
"CMakeFiles/libscatMat.dir/scatMat/neutMaterial.cxx.o" \
"CMakeFiles/libscatMat.dir/scatMat/CryMat.cxx.o" \
"CMakeFiles/libscatMat.dir/scatMat/GlassMaterial.cxx.o"

# External object files for target libscatMat
libscatMat_EXTERNAL_OBJECTS =

lib/liblibscatMat.so: CMakeFiles/libscatMat.dir/scatMat/DBNeutMaterial.cxx.o
lib/liblibscatMat.so: CMakeFiles/libscatMat.dir/scatMat/SQWmaterial.cxx.o
lib/liblibscatMat.so: CMakeFiles/libscatMat.dir/scatMat/neutMaterial.cxx.o
lib/liblibscatMat.so: CMakeFiles/libscatMat.dir/scatMat/CryMat.cxx.o
lib/liblibscatMat.so: CMakeFiles/libscatMat.dir/scatMat/GlassMaterial.cxx.o
lib/liblibscatMat.so: CMakeFiles/libscatMat.dir/build.make
lib/liblibscatMat.so: CMakeFiles/libscatMat.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alberto/nea/aspis/cl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX shared library lib/liblibscatMat.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/libscatMat.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/libscatMat.dir/build: lib/liblibscatMat.so

.PHONY : CMakeFiles/libscatMat.dir/build

CMakeFiles/libscatMat.dir/requires: CMakeFiles/libscatMat.dir/scatMat/DBNeutMaterial.cxx.o.requires
CMakeFiles/libscatMat.dir/requires: CMakeFiles/libscatMat.dir/scatMat/SQWmaterial.cxx.o.requires
CMakeFiles/libscatMat.dir/requires: CMakeFiles/libscatMat.dir/scatMat/neutMaterial.cxx.o.requires
CMakeFiles/libscatMat.dir/requires: CMakeFiles/libscatMat.dir/scatMat/CryMat.cxx.o.requires
CMakeFiles/libscatMat.dir/requires: CMakeFiles/libscatMat.dir/scatMat/GlassMaterial.cxx.o.requires

.PHONY : CMakeFiles/libscatMat.dir/requires

CMakeFiles/libscatMat.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/libscatMat.dir/cmake_clean.cmake
.PHONY : CMakeFiles/libscatMat.dir/clean

CMakeFiles/libscatMat.dir/depend:
	cd /home/alberto/nea/aspis/cl && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alberto/nea/aspis/cl /home/alberto/nea/aspis/cl /home/alberto/nea/aspis/cl /home/alberto/nea/aspis/cl /home/alberto/nea/aspis/cl/CMakeFiles/libscatMat.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/libscatMat.dir/depend
