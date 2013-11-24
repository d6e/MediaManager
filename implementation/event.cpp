#include "event.h"
#include <iostream>

Event::Event(){
}

Event::~Event(){
    argList.clear();
}

// The set method parses the string and inserts it into the list.
void Event::set(std::string msg){
    //TODO: get parsing set up
    argList.push_back(msg);
}

// The display method iterates through the list displaying the data.
void Event::display() const{
    for(int i = 0; i < argList.size(); ++i){
        std::cout << argList.at(i) << std::endl;
    }
}
