#pragma once
#ifndef INPUT_H
#define INPUT_H
#include <string>


class Input {
public:
    Input();
    void read(const char*);        // Reads the textfile
    std::string get();  // returns the string read from the file

private:
    std::string movieCode;
    std::string director;
    std::string title;
    std::string actorFirst;
    std::string actorLast;
    std::string month;
    std::string year;
};


#endif