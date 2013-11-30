#!/bin/bash

files="*.cpp"
exefile="./main"
case "$1" in
"-v")
    # clang++ -g $files && valgrind --leak-check=full $exefile
    make -j4 && valgrind --leak-check=full $exefile
    ;;
"-g")
    echo "test"
    # clang++ -g -Wall $files && gdb $exefile
    make -j4 && gdb $exefile
    ;;
"-Wall")
    clang++ -g -Wall $files && $exefile
    ;;  
*)
    # clang++ -g $files && $exefile
    make -j4 && $exefile
    ;;
esac
