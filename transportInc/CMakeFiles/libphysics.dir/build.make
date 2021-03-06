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
include CMakeFiles/libphysics.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/libphysics.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/libphysics.dir/flags.make

CMakeFiles/libphysics.dir/System/physics/EUnit.cxx.o: CMakeFiles/libphysics.dir/flags.make
CMakeFiles/libphysics.dir/System/physics/EUnit.cxx.o: System/physics/EUnit.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alberto/nea/aspis/cl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/libphysics.dir/System/physics/EUnit.cxx.o"
	clang   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/libphysics.dir/System/physics/EUnit.cxx.o -c /home/alberto/nea/aspis/cl/System/physics/EUnit.cxx

CMakeFiles/libphysics.dir/System/physics/EUnit.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libphysics.dir/System/physics/EUnit.cxx.i"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alberto/nea/aspis/cl/System/physics/EUnit.cxx > CMakeFiles/libphysics.dir/System/physics/EUnit.cxx.i

CMakeFiles/libphysics.dir/System/physics/EUnit.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libphysics.dir/System/physics/EUnit.cxx.s"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alberto/nea/aspis/cl/System/physics/EUnit.cxx -o CMakeFiles/libphysics.dir/System/physics/EUnit.cxx.s

CMakeFiles/libphysics.dir/System/physics/EUnit.cxx.o.requires:

.PHONY : CMakeFiles/libphysics.dir/System/physics/EUnit.cxx.o.requires

CMakeFiles/libphysics.dir/System/physics/EUnit.cxx.o.provides: CMakeFiles/libphysics.dir/System/physics/EUnit.cxx.o.requires
	$(MAKE) -f CMakeFiles/libphysics.dir/build.make CMakeFiles/libphysics.dir/System/physics/EUnit.cxx.o.provides.build
.PHONY : CMakeFiles/libphysics.dir/System/physics/EUnit.cxx.o.provides

CMakeFiles/libphysics.dir/System/physics/EUnit.cxx.o.provides.build: CMakeFiles/libphysics.dir/System/physics/EUnit.cxx.o


CMakeFiles/libphysics.dir/System/physics/PStandard.cxx.o: CMakeFiles/libphysics.dir/flags.make
CMakeFiles/libphysics.dir/System/physics/PStandard.cxx.o: System/physics/PStandard.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alberto/nea/aspis/cl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/libphysics.dir/System/physics/PStandard.cxx.o"
	clang   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/libphysics.dir/System/physics/PStandard.cxx.o -c /home/alberto/nea/aspis/cl/System/physics/PStandard.cxx

CMakeFiles/libphysics.dir/System/physics/PStandard.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libphysics.dir/System/physics/PStandard.cxx.i"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alberto/nea/aspis/cl/System/physics/PStandard.cxx > CMakeFiles/libphysics.dir/System/physics/PStandard.cxx.i

CMakeFiles/libphysics.dir/System/physics/PStandard.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libphysics.dir/System/physics/PStandard.cxx.s"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alberto/nea/aspis/cl/System/physics/PStandard.cxx -o CMakeFiles/libphysics.dir/System/physics/PStandard.cxx.s

CMakeFiles/libphysics.dir/System/physics/PStandard.cxx.o.requires:

.PHONY : CMakeFiles/libphysics.dir/System/physics/PStandard.cxx.o.requires

CMakeFiles/libphysics.dir/System/physics/PStandard.cxx.o.provides: CMakeFiles/libphysics.dir/System/physics/PStandard.cxx.o.requires
	$(MAKE) -f CMakeFiles/libphysics.dir/build.make CMakeFiles/libphysics.dir/System/physics/PStandard.cxx.o.provides.build
.PHONY : CMakeFiles/libphysics.dir/System/physics/PStandard.cxx.o.provides

CMakeFiles/libphysics.dir/System/physics/PStandard.cxx.o.provides.build: CMakeFiles/libphysics.dir/System/physics/PStandard.cxx.o


CMakeFiles/libphysics.dir/System/physics/LSwitchCard.cxx.o: CMakeFiles/libphysics.dir/flags.make
CMakeFiles/libphysics.dir/System/physics/LSwitchCard.cxx.o: System/physics/LSwitchCard.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alberto/nea/aspis/cl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/libphysics.dir/System/physics/LSwitchCard.cxx.o"
	clang   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/libphysics.dir/System/physics/LSwitchCard.cxx.o -c /home/alberto/nea/aspis/cl/System/physics/LSwitchCard.cxx

CMakeFiles/libphysics.dir/System/physics/LSwitchCard.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libphysics.dir/System/physics/LSwitchCard.cxx.i"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alberto/nea/aspis/cl/System/physics/LSwitchCard.cxx > CMakeFiles/libphysics.dir/System/physics/LSwitchCard.cxx.i

CMakeFiles/libphysics.dir/System/physics/LSwitchCard.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libphysics.dir/System/physics/LSwitchCard.cxx.s"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alberto/nea/aspis/cl/System/physics/LSwitchCard.cxx -o CMakeFiles/libphysics.dir/System/physics/LSwitchCard.cxx.s

CMakeFiles/libphysics.dir/System/physics/LSwitchCard.cxx.o.requires:

.PHONY : CMakeFiles/libphysics.dir/System/physics/LSwitchCard.cxx.o.requires

CMakeFiles/libphysics.dir/System/physics/LSwitchCard.cxx.o.provides: CMakeFiles/libphysics.dir/System/physics/LSwitchCard.cxx.o.requires
	$(MAKE) -f CMakeFiles/libphysics.dir/build.make CMakeFiles/libphysics.dir/System/physics/LSwitchCard.cxx.o.provides.build
.PHONY : CMakeFiles/libphysics.dir/System/physics/LSwitchCard.cxx.o.provides

CMakeFiles/libphysics.dir/System/physics/LSwitchCard.cxx.o.provides.build: CMakeFiles/libphysics.dir/System/physics/LSwitchCard.cxx.o


CMakeFiles/libphysics.dir/System/physics/PWTControl.cxx.o: CMakeFiles/libphysics.dir/flags.make
CMakeFiles/libphysics.dir/System/physics/PWTControl.cxx.o: System/physics/PWTControl.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alberto/nea/aspis/cl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/libphysics.dir/System/physics/PWTControl.cxx.o"
	clang   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/libphysics.dir/System/physics/PWTControl.cxx.o -c /home/alberto/nea/aspis/cl/System/physics/PWTControl.cxx

CMakeFiles/libphysics.dir/System/physics/PWTControl.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libphysics.dir/System/physics/PWTControl.cxx.i"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alberto/nea/aspis/cl/System/physics/PWTControl.cxx > CMakeFiles/libphysics.dir/System/physics/PWTControl.cxx.i

CMakeFiles/libphysics.dir/System/physics/PWTControl.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libphysics.dir/System/physics/PWTControl.cxx.s"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alberto/nea/aspis/cl/System/physics/PWTControl.cxx -o CMakeFiles/libphysics.dir/System/physics/PWTControl.cxx.s

CMakeFiles/libphysics.dir/System/physics/PWTControl.cxx.o.requires:

.PHONY : CMakeFiles/libphysics.dir/System/physics/PWTControl.cxx.o.requires

CMakeFiles/libphysics.dir/System/physics/PWTControl.cxx.o.provides: CMakeFiles/libphysics.dir/System/physics/PWTControl.cxx.o.requires
	$(MAKE) -f CMakeFiles/libphysics.dir/build.make CMakeFiles/libphysics.dir/System/physics/PWTControl.cxx.o.provides.build
.PHONY : CMakeFiles/libphysics.dir/System/physics/PWTControl.cxx.o.provides

CMakeFiles/libphysics.dir/System/physics/PWTControl.cxx.o.provides.build: CMakeFiles/libphysics.dir/System/physics/PWTControl.cxx.o


CMakeFiles/libphysics.dir/System/physics/PWTConstructor.cxx.o: CMakeFiles/libphysics.dir/flags.make
CMakeFiles/libphysics.dir/System/physics/PWTConstructor.cxx.o: System/physics/PWTConstructor.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alberto/nea/aspis/cl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/libphysics.dir/System/physics/PWTConstructor.cxx.o"
	clang   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/libphysics.dir/System/physics/PWTConstructor.cxx.o -c /home/alberto/nea/aspis/cl/System/physics/PWTConstructor.cxx

CMakeFiles/libphysics.dir/System/physics/PWTConstructor.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libphysics.dir/System/physics/PWTConstructor.cxx.i"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alberto/nea/aspis/cl/System/physics/PWTConstructor.cxx > CMakeFiles/libphysics.dir/System/physics/PWTConstructor.cxx.i

CMakeFiles/libphysics.dir/System/physics/PWTConstructor.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libphysics.dir/System/physics/PWTConstructor.cxx.s"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alberto/nea/aspis/cl/System/physics/PWTConstructor.cxx -o CMakeFiles/libphysics.dir/System/physics/PWTConstructor.cxx.s

CMakeFiles/libphysics.dir/System/physics/PWTConstructor.cxx.o.requires:

.PHONY : CMakeFiles/libphysics.dir/System/physics/PWTConstructor.cxx.o.requires

CMakeFiles/libphysics.dir/System/physics/PWTConstructor.cxx.o.provides: CMakeFiles/libphysics.dir/System/physics/PWTConstructor.cxx.o.requires
	$(MAKE) -f CMakeFiles/libphysics.dir/build.make CMakeFiles/libphysics.dir/System/physics/PWTConstructor.cxx.o.provides.build
.PHONY : CMakeFiles/libphysics.dir/System/physics/PWTConstructor.cxx.o.provides

CMakeFiles/libphysics.dir/System/physics/PWTConstructor.cxx.o.provides.build: CMakeFiles/libphysics.dir/System/physics/PWTConstructor.cxx.o


CMakeFiles/libphysics.dir/System/physics/dbcnCard.cxx.o: CMakeFiles/libphysics.dir/flags.make
CMakeFiles/libphysics.dir/System/physics/dbcnCard.cxx.o: System/physics/dbcnCard.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alberto/nea/aspis/cl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/libphysics.dir/System/physics/dbcnCard.cxx.o"
	clang   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/libphysics.dir/System/physics/dbcnCard.cxx.o -c /home/alberto/nea/aspis/cl/System/physics/dbcnCard.cxx

CMakeFiles/libphysics.dir/System/physics/dbcnCard.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libphysics.dir/System/physics/dbcnCard.cxx.i"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alberto/nea/aspis/cl/System/physics/dbcnCard.cxx > CMakeFiles/libphysics.dir/System/physics/dbcnCard.cxx.i

CMakeFiles/libphysics.dir/System/physics/dbcnCard.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libphysics.dir/System/physics/dbcnCard.cxx.s"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alberto/nea/aspis/cl/System/physics/dbcnCard.cxx -o CMakeFiles/libphysics.dir/System/physics/dbcnCard.cxx.s

CMakeFiles/libphysics.dir/System/physics/dbcnCard.cxx.o.requires:

.PHONY : CMakeFiles/libphysics.dir/System/physics/dbcnCard.cxx.o.requires

CMakeFiles/libphysics.dir/System/physics/dbcnCard.cxx.o.provides: CMakeFiles/libphysics.dir/System/physics/dbcnCard.cxx.o.requires
	$(MAKE) -f CMakeFiles/libphysics.dir/build.make CMakeFiles/libphysics.dir/System/physics/dbcnCard.cxx.o.provides.build
.PHONY : CMakeFiles/libphysics.dir/System/physics/dbcnCard.cxx.o.provides

CMakeFiles/libphysics.dir/System/physics/dbcnCard.cxx.o.provides.build: CMakeFiles/libphysics.dir/System/physics/dbcnCard.cxx.o


CMakeFiles/libphysics.dir/System/physics/PhysicsCards.cxx.o: CMakeFiles/libphysics.dir/flags.make
CMakeFiles/libphysics.dir/System/physics/PhysicsCards.cxx.o: System/physics/PhysicsCards.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alberto/nea/aspis/cl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/libphysics.dir/System/physics/PhysicsCards.cxx.o"
	clang   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/libphysics.dir/System/physics/PhysicsCards.cxx.o -c /home/alberto/nea/aspis/cl/System/physics/PhysicsCards.cxx

CMakeFiles/libphysics.dir/System/physics/PhysicsCards.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libphysics.dir/System/physics/PhysicsCards.cxx.i"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alberto/nea/aspis/cl/System/physics/PhysicsCards.cxx > CMakeFiles/libphysics.dir/System/physics/PhysicsCards.cxx.i

CMakeFiles/libphysics.dir/System/physics/PhysicsCards.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libphysics.dir/System/physics/PhysicsCards.cxx.s"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alberto/nea/aspis/cl/System/physics/PhysicsCards.cxx -o CMakeFiles/libphysics.dir/System/physics/PhysicsCards.cxx.s

CMakeFiles/libphysics.dir/System/physics/PhysicsCards.cxx.o.requires:

.PHONY : CMakeFiles/libphysics.dir/System/physics/PhysicsCards.cxx.o.requires

CMakeFiles/libphysics.dir/System/physics/PhysicsCards.cxx.o.provides: CMakeFiles/libphysics.dir/System/physics/PhysicsCards.cxx.o.requires
	$(MAKE) -f CMakeFiles/libphysics.dir/build.make CMakeFiles/libphysics.dir/System/physics/PhysicsCards.cxx.o.provides.build
.PHONY : CMakeFiles/libphysics.dir/System/physics/PhysicsCards.cxx.o.provides

CMakeFiles/libphysics.dir/System/physics/PhysicsCards.cxx.o.provides.build: CMakeFiles/libphysics.dir/System/physics/PhysicsCards.cxx.o


CMakeFiles/libphysics.dir/System/physics/PhysImp.cxx.o: CMakeFiles/libphysics.dir/flags.make
CMakeFiles/libphysics.dir/System/physics/PhysImp.cxx.o: System/physics/PhysImp.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alberto/nea/aspis/cl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/libphysics.dir/System/physics/PhysImp.cxx.o"
	clang   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/libphysics.dir/System/physics/PhysImp.cxx.o -c /home/alberto/nea/aspis/cl/System/physics/PhysImp.cxx

CMakeFiles/libphysics.dir/System/physics/PhysImp.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libphysics.dir/System/physics/PhysImp.cxx.i"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alberto/nea/aspis/cl/System/physics/PhysImp.cxx > CMakeFiles/libphysics.dir/System/physics/PhysImp.cxx.i

CMakeFiles/libphysics.dir/System/physics/PhysImp.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libphysics.dir/System/physics/PhysImp.cxx.s"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alberto/nea/aspis/cl/System/physics/PhysImp.cxx -o CMakeFiles/libphysics.dir/System/physics/PhysImp.cxx.s

CMakeFiles/libphysics.dir/System/physics/PhysImp.cxx.o.requires:

.PHONY : CMakeFiles/libphysics.dir/System/physics/PhysImp.cxx.o.requires

CMakeFiles/libphysics.dir/System/physics/PhysImp.cxx.o.provides: CMakeFiles/libphysics.dir/System/physics/PhysImp.cxx.o.requires
	$(MAKE) -f CMakeFiles/libphysics.dir/build.make CMakeFiles/libphysics.dir/System/physics/PhysImp.cxx.o.provides.build
.PHONY : CMakeFiles/libphysics.dir/System/physics/PhysImp.cxx.o.provides

CMakeFiles/libphysics.dir/System/physics/PhysImp.cxx.o.provides.build: CMakeFiles/libphysics.dir/System/physics/PhysImp.cxx.o


CMakeFiles/libphysics.dir/System/physics/ModeCard.cxx.o: CMakeFiles/libphysics.dir/flags.make
CMakeFiles/libphysics.dir/System/physics/ModeCard.cxx.o: System/physics/ModeCard.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alberto/nea/aspis/cl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/libphysics.dir/System/physics/ModeCard.cxx.o"
	clang   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/libphysics.dir/System/physics/ModeCard.cxx.o -c /home/alberto/nea/aspis/cl/System/physics/ModeCard.cxx

CMakeFiles/libphysics.dir/System/physics/ModeCard.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libphysics.dir/System/physics/ModeCard.cxx.i"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alberto/nea/aspis/cl/System/physics/ModeCard.cxx > CMakeFiles/libphysics.dir/System/physics/ModeCard.cxx.i

CMakeFiles/libphysics.dir/System/physics/ModeCard.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libphysics.dir/System/physics/ModeCard.cxx.s"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alberto/nea/aspis/cl/System/physics/ModeCard.cxx -o CMakeFiles/libphysics.dir/System/physics/ModeCard.cxx.s

CMakeFiles/libphysics.dir/System/physics/ModeCard.cxx.o.requires:

.PHONY : CMakeFiles/libphysics.dir/System/physics/ModeCard.cxx.o.requires

CMakeFiles/libphysics.dir/System/physics/ModeCard.cxx.o.provides: CMakeFiles/libphysics.dir/System/physics/ModeCard.cxx.o.requires
	$(MAKE) -f CMakeFiles/libphysics.dir/build.make CMakeFiles/libphysics.dir/System/physics/ModeCard.cxx.o.provides.build
.PHONY : CMakeFiles/libphysics.dir/System/physics/ModeCard.cxx.o.provides

CMakeFiles/libphysics.dir/System/physics/ModeCard.cxx.o.provides.build: CMakeFiles/libphysics.dir/System/physics/ModeCard.cxx.o


CMakeFiles/libphysics.dir/System/physics/ExtConstructor.cxx.o: CMakeFiles/libphysics.dir/flags.make
CMakeFiles/libphysics.dir/System/physics/ExtConstructor.cxx.o: System/physics/ExtConstructor.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alberto/nea/aspis/cl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/libphysics.dir/System/physics/ExtConstructor.cxx.o"
	clang   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/libphysics.dir/System/physics/ExtConstructor.cxx.o -c /home/alberto/nea/aspis/cl/System/physics/ExtConstructor.cxx

CMakeFiles/libphysics.dir/System/physics/ExtConstructor.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libphysics.dir/System/physics/ExtConstructor.cxx.i"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alberto/nea/aspis/cl/System/physics/ExtConstructor.cxx > CMakeFiles/libphysics.dir/System/physics/ExtConstructor.cxx.i

CMakeFiles/libphysics.dir/System/physics/ExtConstructor.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libphysics.dir/System/physics/ExtConstructor.cxx.s"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alberto/nea/aspis/cl/System/physics/ExtConstructor.cxx -o CMakeFiles/libphysics.dir/System/physics/ExtConstructor.cxx.s

CMakeFiles/libphysics.dir/System/physics/ExtConstructor.cxx.o.requires:

.PHONY : CMakeFiles/libphysics.dir/System/physics/ExtConstructor.cxx.o.requires

CMakeFiles/libphysics.dir/System/physics/ExtConstructor.cxx.o.provides: CMakeFiles/libphysics.dir/System/physics/ExtConstructor.cxx.o.requires
	$(MAKE) -f CMakeFiles/libphysics.dir/build.make CMakeFiles/libphysics.dir/System/physics/ExtConstructor.cxx.o.provides.build
.PHONY : CMakeFiles/libphysics.dir/System/physics/ExtConstructor.cxx.o.provides

CMakeFiles/libphysics.dir/System/physics/ExtConstructor.cxx.o.provides.build: CMakeFiles/libphysics.dir/System/physics/ExtConstructor.cxx.o


CMakeFiles/libphysics.dir/System/physics/ExtControl.cxx.o: CMakeFiles/libphysics.dir/flags.make
CMakeFiles/libphysics.dir/System/physics/ExtControl.cxx.o: System/physics/ExtControl.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alberto/nea/aspis/cl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/libphysics.dir/System/physics/ExtControl.cxx.o"
	clang   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/libphysics.dir/System/physics/ExtControl.cxx.o -c /home/alberto/nea/aspis/cl/System/physics/ExtControl.cxx

CMakeFiles/libphysics.dir/System/physics/ExtControl.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/libphysics.dir/System/physics/ExtControl.cxx.i"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/alberto/nea/aspis/cl/System/physics/ExtControl.cxx > CMakeFiles/libphysics.dir/System/physics/ExtControl.cxx.i

CMakeFiles/libphysics.dir/System/physics/ExtControl.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/libphysics.dir/System/physics/ExtControl.cxx.s"
	clang  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/alberto/nea/aspis/cl/System/physics/ExtControl.cxx -o CMakeFiles/libphysics.dir/System/physics/ExtControl.cxx.s

CMakeFiles/libphysics.dir/System/physics/ExtControl.cxx.o.requires:

.PHONY : CMakeFiles/libphysics.dir/System/physics/ExtControl.cxx.o.requires

CMakeFiles/libphysics.dir/System/physics/ExtControl.cxx.o.provides: CMakeFiles/libphysics.dir/System/physics/ExtControl.cxx.o.requires
	$(MAKE) -f CMakeFiles/libphysics.dir/build.make CMakeFiles/libphysics.dir/System/physics/ExtControl.cxx.o.provides.build
.PHONY : CMakeFiles/libphysics.dir/System/physics/ExtControl.cxx.o.provides

CMakeFiles/libphysics.dir/System/physics/ExtControl.cxx.o.provides.build: CMakeFiles/libphysics.dir/System/physics/ExtControl.cxx.o


# Object files for target libphysics
libphysics_OBJECTS = \
"CMakeFiles/libphysics.dir/System/physics/EUnit.cxx.o" \
"CMakeFiles/libphysics.dir/System/physics/PStandard.cxx.o" \
"CMakeFiles/libphysics.dir/System/physics/LSwitchCard.cxx.o" \
"CMakeFiles/libphysics.dir/System/physics/PWTControl.cxx.o" \
"CMakeFiles/libphysics.dir/System/physics/PWTConstructor.cxx.o" \
"CMakeFiles/libphysics.dir/System/physics/dbcnCard.cxx.o" \
"CMakeFiles/libphysics.dir/System/physics/PhysicsCards.cxx.o" \
"CMakeFiles/libphysics.dir/System/physics/PhysImp.cxx.o" \
"CMakeFiles/libphysics.dir/System/physics/ModeCard.cxx.o" \
"CMakeFiles/libphysics.dir/System/physics/ExtConstructor.cxx.o" \
"CMakeFiles/libphysics.dir/System/physics/ExtControl.cxx.o"

# External object files for target libphysics
libphysics_EXTERNAL_OBJECTS =

lib/liblibphysics.so: CMakeFiles/libphysics.dir/System/physics/EUnit.cxx.o
lib/liblibphysics.so: CMakeFiles/libphysics.dir/System/physics/PStandard.cxx.o
lib/liblibphysics.so: CMakeFiles/libphysics.dir/System/physics/LSwitchCard.cxx.o
lib/liblibphysics.so: CMakeFiles/libphysics.dir/System/physics/PWTControl.cxx.o
lib/liblibphysics.so: CMakeFiles/libphysics.dir/System/physics/PWTConstructor.cxx.o
lib/liblibphysics.so: CMakeFiles/libphysics.dir/System/physics/dbcnCard.cxx.o
lib/liblibphysics.so: CMakeFiles/libphysics.dir/System/physics/PhysicsCards.cxx.o
lib/liblibphysics.so: CMakeFiles/libphysics.dir/System/physics/PhysImp.cxx.o
lib/liblibphysics.so: CMakeFiles/libphysics.dir/System/physics/ModeCard.cxx.o
lib/liblibphysics.so: CMakeFiles/libphysics.dir/System/physics/ExtConstructor.cxx.o
lib/liblibphysics.so: CMakeFiles/libphysics.dir/System/physics/ExtControl.cxx.o
lib/liblibphysics.so: CMakeFiles/libphysics.dir/build.make
lib/liblibphysics.so: CMakeFiles/libphysics.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alberto/nea/aspis/cl/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking CXX shared library lib/liblibphysics.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/libphysics.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/libphysics.dir/build: lib/liblibphysics.so

.PHONY : CMakeFiles/libphysics.dir/build

CMakeFiles/libphysics.dir/requires: CMakeFiles/libphysics.dir/System/physics/EUnit.cxx.o.requires
CMakeFiles/libphysics.dir/requires: CMakeFiles/libphysics.dir/System/physics/PStandard.cxx.o.requires
CMakeFiles/libphysics.dir/requires: CMakeFiles/libphysics.dir/System/physics/LSwitchCard.cxx.o.requires
CMakeFiles/libphysics.dir/requires: CMakeFiles/libphysics.dir/System/physics/PWTControl.cxx.o.requires
CMakeFiles/libphysics.dir/requires: CMakeFiles/libphysics.dir/System/physics/PWTConstructor.cxx.o.requires
CMakeFiles/libphysics.dir/requires: CMakeFiles/libphysics.dir/System/physics/dbcnCard.cxx.o.requires
CMakeFiles/libphysics.dir/requires: CMakeFiles/libphysics.dir/System/physics/PhysicsCards.cxx.o.requires
CMakeFiles/libphysics.dir/requires: CMakeFiles/libphysics.dir/System/physics/PhysImp.cxx.o.requires
CMakeFiles/libphysics.dir/requires: CMakeFiles/libphysics.dir/System/physics/ModeCard.cxx.o.requires
CMakeFiles/libphysics.dir/requires: CMakeFiles/libphysics.dir/System/physics/ExtConstructor.cxx.o.requires
CMakeFiles/libphysics.dir/requires: CMakeFiles/libphysics.dir/System/physics/ExtControl.cxx.o.requires

.PHONY : CMakeFiles/libphysics.dir/requires

CMakeFiles/libphysics.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/libphysics.dir/cmake_clean.cmake
.PHONY : CMakeFiles/libphysics.dir/clean

CMakeFiles/libphysics.dir/depend:
	cd /home/alberto/nea/aspis/cl && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alberto/nea/aspis/cl /home/alberto/nea/aspis/cl /home/alberto/nea/aspis/cl /home/alberto/nea/aspis/cl /home/alberto/nea/aspis/cl/CMakeFiles/libphysics.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/libphysics.dir/depend

