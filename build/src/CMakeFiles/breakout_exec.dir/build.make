# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = "C:/Program Files/CMake/bin/cmake.exe"

# The command to remove a file.
RM = "C:/Program Files/CMake/bin/cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:/Users/ericz/Documents/c++/Breakout

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:/Users/ericz/Documents/c++/Breakout/build

# Include any dependencies generated for this target.
include src/CMakeFiles/breakout_exec.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/breakout_exec.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/breakout_exec.dir/flags.make

src/CMakeFiles/breakout_exec.dir/main.cpp.obj: src/CMakeFiles/breakout_exec.dir/flags.make
src/CMakeFiles/breakout_exec.dir/main.cpp.obj: src/CMakeFiles/breakout_exec.dir/includes_CXX.rsp
src/CMakeFiles/breakout_exec.dir/main.cpp.obj: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:/Users/ericz/Documents/c++/Breakout/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/breakout_exec.dir/main.cpp.obj"
	cd C:/Users/ericz/Documents/c++/Breakout/build/src && C:/mingw64/bin/g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/breakout_exec.dir/main.cpp.obj -c C:/Users/ericz/Documents/c++/Breakout/src/main.cpp

src/CMakeFiles/breakout_exec.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/breakout_exec.dir/main.cpp.i"
	cd C:/Users/ericz/Documents/c++/Breakout/build/src && C:/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:/Users/ericz/Documents/c++/Breakout/src/main.cpp > CMakeFiles/breakout_exec.dir/main.cpp.i

src/CMakeFiles/breakout_exec.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/breakout_exec.dir/main.cpp.s"
	cd C:/Users/ericz/Documents/c++/Breakout/build/src && C:/mingw64/bin/g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:/Users/ericz/Documents/c++/Breakout/src/main.cpp -o CMakeFiles/breakout_exec.dir/main.cpp.s

# Object files for target breakout_exec
breakout_exec_OBJECTS = \
"CMakeFiles/breakout_exec.dir/main.cpp.obj"

# External object files for target breakout_exec
breakout_exec_EXTERNAL_OBJECTS =

src/breakout_exec.exe: src/CMakeFiles/breakout_exec.dir/main.cpp.obj
src/breakout_exec.exe: src/CMakeFiles/breakout_exec.dir/build.make
src/breakout_exec.exe: ../libs/SFML-2.5.1/lib/libsfml-graphics-s-d.a
src/breakout_exec.exe: ../libs/SFML-2.5.1/lib/libsfml-audio-s-d.a
src/breakout_exec.exe: src/libbreakout_lib.a
src/breakout_exec.exe: ../libs/Box2D/lib/libBox2D.a
src/breakout_exec.exe: ../libs/SFML-2.5.1/lib/libsfml-graphics-s-d.a
src/breakout_exec.exe: ../libs/SFML-2.5.1/lib/libsfml-window-s-d.a
src/breakout_exec.exe: ../libs/SFML-2.5.1/lib/libfreetype.a
src/breakout_exec.exe: ../libs/SFML-2.5.1/lib/libsfml-audio-s-d.a
src/breakout_exec.exe: ../libs/SFML-2.5.1/lib/libopenal32.a
src/breakout_exec.exe: ../libs/SFML-2.5.1/lib/libsfml-system-s-d.a
src/breakout_exec.exe: ../libs/SFML-2.5.1/lib/libvorbisfile.a
src/breakout_exec.exe: ../libs/SFML-2.5.1/lib/libvorbisenc.a
src/breakout_exec.exe: ../libs/SFML-2.5.1/lib/libvorbis.a
src/breakout_exec.exe: ../libs/SFML-2.5.1/lib/libogg.a
src/breakout_exec.exe: ../libs/SFML-2.5.1/lib/libFLAC.a
src/breakout_exec.exe: src/CMakeFiles/breakout_exec.dir/linklibs.rsp
src/breakout_exec.exe: src/CMakeFiles/breakout_exec.dir/objects1.rsp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:/Users/ericz/Documents/c++/Breakout/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable breakout_exec.exe"
	cd C:/Users/ericz/Documents/c++/Breakout/build/src && "C:/Program Files/CMake/bin/cmake.exe" -E remove -f CMakeFiles/breakout_exec.dir/objects.a
	cd C:/Users/ericz/Documents/c++/Breakout/build/src && C:/mingw64/bin/ar.exe cr CMakeFiles/breakout_exec.dir/objects.a @CMakeFiles/breakout_exec.dir/objects1.rsp
	cd C:/Users/ericz/Documents/c++/Breakout/build/src && C:/mingw64/bin/g++.exe  -Wall -g   -Wl,--whole-archive CMakeFiles/breakout_exec.dir/objects.a -Wl,--no-whole-archive  -o breakout_exec.exe -Wl,--out-implib,libbreakout_exec.dll.a -Wl,--major-image-version,0,--minor-image-version,0 @CMakeFiles/breakout_exec.dir/linklibs.rsp

# Rule to build all files generated by this target.
src/CMakeFiles/breakout_exec.dir/build: src/breakout_exec.exe

.PHONY : src/CMakeFiles/breakout_exec.dir/build

src/CMakeFiles/breakout_exec.dir/clean:
	cd C:/Users/ericz/Documents/c++/Breakout/build/src && $(CMAKE_COMMAND) -P CMakeFiles/breakout_exec.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/breakout_exec.dir/clean

src/CMakeFiles/breakout_exec.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" C:/Users/ericz/Documents/c++/Breakout C:/Users/ericz/Documents/c++/Breakout/src C:/Users/ericz/Documents/c++/Breakout/build C:/Users/ericz/Documents/c++/Breakout/build/src C:/Users/ericz/Documents/c++/Breakout/build/src/CMakeFiles/breakout_exec.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/breakout_exec.dir/depend

