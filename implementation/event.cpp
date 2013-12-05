#include "event.h"
#include <sstream>
#include <iostream>

Event::Event(std::string msg){
    set(msg);
}

Event::Event(std::string msg, Product* ptr) : pdtPtr(ptr){
    set(msg);
}

Event::~Event(){
    argList.clear();
}

// The set method parses the string and inserts it into the list.
void Event::set(std::string msg){
    eventDetails = msg;
    std::string token;
    std::stringstream ss;
    ss << msg;
    while (ss >> token)
    {
        argList.push_back(token);
    }
}

std::string Event::get(unsigned int index) const{
    if (argList.size() > index){
        return argList.at(index);
    }
    return "";
}


std::string Event::getEventDetails() const{
    return eventDetails;
}

// The display method iterates through the list displaying the data.
void Event::display() const{    
    // pdtPtr->display();
    std::cout << *pdtPtr << std::endl;
    // for(int i = 0; i < argList.size(); ++i){
        // std::cout << argList.at(i) << " ";
    // }
    std::cout << std::endl;
}
