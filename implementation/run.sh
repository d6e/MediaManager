#!/bin/bash

case "$1" in
"-c") 
    clang -x c++ $files main.cpp && ./a.out
    ;;
"-v")
    g++ -g -Wall $files && valgrind ./a.out
    ;;
"-g")
    g++ -g -Wall $files && gdb ./a.out
    ;;
*)
    files="main.cpp"
    ;;  
esac

g++ -g -Wall $files && ./a.out