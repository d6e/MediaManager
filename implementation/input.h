#pragma once
#ifndef INPUT_H
#define INPUT_H
#include <string>
#include <vector>

/*
Used for reading in input
*/
class Input {
public:
    void read(const char*);        // Reads the textfile
    std::vector<std::string> get();

private:
    std::vector<std::string> sList;
};


#endif