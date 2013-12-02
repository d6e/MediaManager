#pragma once
#ifndef EVENT_H
#define EVENT_H
#include "error.h"
#include <string>
#include <vector>

/*
An event object holds the data for a command.

In parsing the intial string, it divides up the string into parts deliminated
by whitespace and inputs them into the list . Commas are always seperated out
into its own node as a special marker.

The display method iterates through the list displaying the data.

The set method parses the string and inserts it into the list.
*/

class Event {
private:
    std::vector<std::string> argList; //like eventDetails but space deliminated
    std::string eventDetails;  //like argList but a string
public:
    Event();
    Event(std::string);
    virtual ~Event();
    void set(std::string); // Parses input a string into the list.
    std::string get(unsigned int) const;
    std::string getEventDetails() const;
    void display() const;  // Display the data from one event object
};

#endif