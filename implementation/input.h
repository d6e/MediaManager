#pragma once
#ifndef INPUT_H
#define INPUT_H
#include <string>
#include <vector>


class Input {
public:
    void read(const char*);        // Reads the textfile
    // std::string get();  // returns the string read from the file
    std::vector<std::string> get();

private:
    std::string movieCode;
    std::string director;
    std::string title;
    std::string actorFirst;
    std::string actorLast;
    std::string month;
    std::string year;


    std::vector<std::string> sList;
};


#endif