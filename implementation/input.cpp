#include "input.h"
#include <iostream>
#include <fstream>

void Input::read(const char* dataFile){
    std::ifstream infile(dataFile, std::ifstream::in);
    if (infile.is_open()){
        while (infile.good()){
            std::string line;
            getline(infile,line);
            sList.push_back(line);  
        }
        infile.close();
    }
    else{
        std::cout << "Unable to open file" << std::endl << std::endl;
    }
}

// accessor for the vector containing the read-in data
std::vector<std::string> Input::get(){
    return sList;
}