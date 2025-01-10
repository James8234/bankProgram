#!/bin/bash


cd "$(dirname "$0")"

#Generate Makefile
cmake -S . -B .
#compile code
if make -C . ; then
	./run
fi
