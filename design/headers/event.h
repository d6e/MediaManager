#ifndef EVENT_H
#define EVENT_H
#include "error.h"
#include <string>
#include <list>

/*
An event object holds the data for a command.

In parsing the intial string, it divides up the string into parts deliminated
by whitespace and inputs them into the list . Commas are always seperated out
into its own node as a special marker.

The display method iterates through the list displaying the data.

The set method parses the string and inserts it into the list. It returns an
error object with an error message if it fails, a blank string if it succeeds.
*/

class Event {
private:
    std::list<std::string> arguments;
public:
    void display() const;  // Display the data from one event object
    Event();
    virtual ~Event();
    Error set(std::string); // Parses input a string into the list.
};


#endif