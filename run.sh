#!/bin/bash
#Generate Makefile
cmake -S . -B ./build
#compile code
make -C ./build
#execute code
./build/run
