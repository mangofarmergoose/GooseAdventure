#!/bin/bash

IncludeRaylib="-l raylib"
IncludeCurrDir="-I ./"
FLAGS="-std=c++11"

clang++ control.cpp control.hpp $FLAGS -c $IncludeRaylib $IncludeCurrDir
clang++ board.cpp board.hpp control.hpp $FLAGS -c $IncludeRaylib $IncludeCurrDir
clang++ card.cpp card.hpp control.hpp $FLAGS -c $IncludeRaylib $IncludeCurrDir
clang++ main.cpp board.hpp card.hpp  $FLAGS -c $IncludeRaylib $IncludeCurrDir

mkdir src
mv *.o *.gch src

clang++ ./src/*.o $FLAGS -o prog $FLAGS $IncludeRaylib $IncludeCurrDir

