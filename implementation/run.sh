#!/bin/bash
g++ -g -Wall *.cpp && ./a.out

if [ "$1" = "v" ] || [ "$1" = "-v" ] || [ "$1" = "valgrind" ]; then
    g++ -g -Wall *.cpp && valgrind ./a.out
elif [ "$1" = "g" ] || [ "$1" = "-g" ] || [ "$1" = "gdb" ]; then
    g++ -g -Wall *.cpp && gdb ./a.out
fi
