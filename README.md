# Breakout
Breakout created in C++ with Box2D and SFML


# To Run
## Prerequisites
1. Download [cmake](https://cmake.org/download/)
2. Get GCC v7.3.0 ([windows](https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win64/Personal%20Builds/mingw-builds/7.3.0/threads-posix/seh/x86_64-7.3.0-release-posix-seh-rt_v5-rev0.7z/download))

## Generate Makefiles with CMake
1. `cd build`
2. Windows: `cmake -D CMAKE_C_COMPILER=c:/mingw64/bin/gcc.exe CMAKE_CXX_COMPILER=c:/mingw64/bin/g++.exe ..`  
   Linux: `cmake -D CMAKE_C_COMPILER=/usr/bin/gcc CMAKE_CXX_COMPILER=/usr/bin/g++ ..`

## Build and run program
1. `cd src`
2. `make`
3. Windows: `./breakout.exe` with Git bash or `breakout.exe` with command prompt.
4. Linux: `./breakokut`

## Build and run tests
1. `cd test`
2. `make`
3. Windows: `./runUnitTests.exe` with Git bash or `runUnitTests.exe` with command prompt.
4. Linux: `./runUnitTests`
