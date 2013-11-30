#!/bin/bash

files="*.cpp"

if [ $# > 1 ]; then
    case "$1" in
    "-c") 
        clang++ $files && ./a.out
        ;;
    "-v")
        clang++ -g $files && valgrind ./a.out
        ;;
    "-g")
        clang++ -g -Wall $files && gdb ./a.out
        ;;
    "-Wall")
        clang++ -g -Wall $files && ./a.out
        ;;  
    esac
else
    clang++ -g $files && ./a.out
fi