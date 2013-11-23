#include "input.h"
#include <iostream>
#include <fstream>

Input::Input(){}

void Input::read(const char* dataFile){
   std::ifstream infile(dataFile, std::ifstream::in);

   infile >> movieCode;                 // reads the 'C' code

   infile.get();                       // get (and ignore) blank before director
   getline(infile, director, ',');     // input director
   
   infile.get();                       // get (and ignore) blank before title
   getline(infile, title, ',');        // input title
   
   infile.get();                       // get (and ignore) blank before actor
   infile >> actorFirst >> actorLast;  // input star's name
   infile >> month >> year;            // input month and year
}

std::string Input::get(){
    std::string ret;
    ret = movieCode + director + title + actorFirst + actorLast + month + year;
    return ret;
}