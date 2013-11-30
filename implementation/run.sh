#!/bin/bash

files="*.cpp"

case "$1" in
"-c") 
    clang++ $files && ./a.out
    ;;
"-v")
    clang++ -g $files && valgrind ./a.out
    ;;
"-g")
    echo "test"
    clang++ -g -Wall $files && gdb ./a.out
    ;;
"-Wall")
    clang++ -g -Wall $files && ./a.out
    ;;  
*)
    clang++ -g $files && ./a.out
    ;;
esac
