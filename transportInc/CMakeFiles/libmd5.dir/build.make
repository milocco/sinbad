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
include CMakeFiles/libmd5.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/libmd5.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/libmd5.dir/flags.make

CMakeFiles/libmd5.dir/System/md5/MD5hash.cxx.o: CMakeFiles/libmd5.dir/flags.make
CMakeFiles/libmd5.dir/System/md5/MD5hash.cxx.o: System/md5/MD5hash.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alberto/nea/aspis/cl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/libmd5.dir/System/md5/MD5hash.cxx.o"
	clang   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/libmd5.dir/System/md5/MD5hash.cxx.o -c /home/alberto/nea/aspis/cl/System/md5/MD5hash.cxx

CMakeFiles/libmd5.dir/System/md5/MD5hash.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libmd5.dir/System/md5/MD5hash.cxx.i"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alberto/nea/aspis/cl/System/md5/MD5hash.cxx > CMakeFiles/libmd5.dir/System/md5/MD5hash.cxx.i

CMakeFiles/libmd5.dir/System/md5/MD5hash.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libmd5.dir/System/md5/MD5hash.cxx.s"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alberto/nea/aspis/cl/System/md5/MD5hash.cxx -o CMakeFiles/libmd5.dir/System/md5/MD5hash.cxx.s

CMakeFiles/libmd5.dir/System/md5/MD5hash.cxx.o.requires:

.PHONY : CMakeFiles/libmd5.dir/System/md5/MD5hash.cxx.o.requires

CMakeFiles/libmd5.dir/System/md5/MD5hash.cxx.o.provides: CMakeFiles/libmd5.dir/System/md5/MD5hash.cxx.o.requires
	$(MAKE) -f CMakeFiles/libmd5.dir/build.make CMakeFiles/libmd5.dir/System/md5/MD5hash.cxx.o.provides.build
.PHONY : CMakeFiles/libmd5.dir/System/md5/MD5hash.cxx.o.provides

CMakeFiles/libmd5.dir/System/md5/MD5hash.cxx.o.provides.build: CMakeFiles/libmd5.dir/System/md5/MD5hash.cxx.o


# Object files for target libmd5
libmd5_OBJECTS = \
"CMakeFiles/libmd5.dir/System/md5/MD5hash.cxx.o"

# External object files for target libmd5
libmd5_EXTERNAL_OBJECTS =

lib/liblibmd5.so: CMakeFiles/libmd5.dir/System/md5/MD5hash.cxx.o
lib/liblibmd5.so: CMakeFiles/libmd5.dir/build.make
lib/liblibmd5.so: CMakeFiles/libmd5.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alberto/nea/aspis/cl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library lib/liblibmd5.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/libmd5.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/libmd5.dir/build: lib/liblibmd5.so

.PHONY : CMakeFiles/libmd5.dir/build

CMakeFiles/libmd5.dir/requires: CMakeFiles/libmd5.dir/System/md5/MD5hash.cxx.o.requires

.PHONY : CMakeFiles/libmd5.dir/requires

CMakeFiles/libmd5.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/libmd5.dir/cmake_clean.cmake
.PHONY : CMakeFiles/libmd5.dir/clean

CMakeFiles/libmd5.dir/depend:
	cd /home/alberto/nea/aspis/cl && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alberto/nea/aspis/cl /home/alberto/nea/aspis/cl /home/alberto/nea/aspis/cl /home/alberto/nea/aspis/cl /home/alberto/nea/aspis/cl/CMakeFiles/libmd5.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/libmd5.dir/depend

