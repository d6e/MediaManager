#!/bin/bash

case "$1" in
"-c") 
    clang++ $files && ./a.out
    ;;
"-v")
    clang++ -g -Wall $files && valgrind ./a.out
    ;;
"-g")
    clang++ -g -Wall $files && gdb ./a.out
    ;;
*)
    files="product.cpp nodedata.cpp movie.cpp productformat.cpp comedy.cpp main.cpp"
    ;;  
esac

clang++ -g -Wall $files && ./a.out
