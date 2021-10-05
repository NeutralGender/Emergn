#!/bin/bash

### Create directory for build informaton
if [ -d build ]; 
then
    rm -r build
fi

mkdir build
cd build

### Generate make files and build project
cmake ..
make

### Leave build directory
cd ..
