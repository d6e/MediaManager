#ifndef EVENT_H
#define EVENT_H
#include "error.h"
#include <string>
#include <list>

/*
An event object holds the data for a command.

In parsing the intial string, it divides up the string into parts deliminated by whitespace
and inputs them into the list . Commas are always seperated out into its own node as
a special marker.
*/

class Event {
private:
    list<std::string> arguments;
public:
    void display() const;  // Display the data from one event object
    Event();
    ~Event();
    Error set(std::string); // Parses input a string into the list.
};


#endif