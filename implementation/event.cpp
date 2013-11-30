#include "event.h"
#include <sstream>
#include <iostream>

Event::Event(std::string msg){
    std::string token;
    std::stringstream ss;
    ss << msg;
    while (ss >> token)
    {
        argList.push_back(token);
    }
}

Event::~Event(){
    argList.clear();
}

// The set method parses the string and inserts it into the list.
void Event::set(std::string msg){
    std::string token;
    std::stringstream ss;
    ss << msg;
    while (ss >> token)
    {
        argList.push_back(token);
    }
}

std::string Event::get(unsigned int index){
    if (argList.size() > index){
        return argList.at(index);
    }
    return "";
}

// The display method iterates through the list displaying the data.
void Event::display() const{
    std::cout << "reached event" << std::endl;
    
    for(int i = 0; i < argList.size(); ++i){
        std::cout << argList.at(i) << std::endl;
    }
}
