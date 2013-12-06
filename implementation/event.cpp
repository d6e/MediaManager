#include "event.h"
#include <sstream>
#include <iostream>

Event::Event(std::string msg) : eventDetails(msg){
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
    eventDetails = msg;
    std::string token;
    std::stringstream ss;
    ss << msg;
    while (ss >> token)
    {
        argList.push_back(token);
    }
}

//accessor for an element of argLists
std::string Event::get(unsigned int index) const{
    if (argList.size() > index){
        return argList.at(index);
    }
    return "";
}

//returns the original string that was passed into the Event obj
std::string Event::getEventDetails() const{
    return eventDetails;
}

// The display method iterates through the list displaying the data.
void Event::display() const{    
    for(int i = 0; i < argList.size(); ++i){
        std::cout << argList.at(i) << " ";
    }
    std::cout << std::endl;
}
