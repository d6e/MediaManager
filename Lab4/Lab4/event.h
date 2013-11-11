#ifndef EVENT_H
#define EVENT_H
#include "error.h"
#include <string>

/*
An event object holds the data for a transaction. It has two private string
datamembers, one for the borrowed/returned status called borrowedOrReturned
and another for the rest of the string. The borrowed/returned status will 
likely be a single character (B or R respectively) for our usage, but we 
chose to use a string as that will allow for more flexibility in the future. 

The display method prints both the borrowedOrReturned string and the
otherinfo string as one line. 

The set method parses the string passed into it and assigns the first 
substring to the borrowedOrReturned string and the rest of the string to the
otherInfo String. If the setting fails it returns an Error object.  
*/

class Event {
private:
    String borrowedOrReturned;  // the first character or substring passed in
    String otherInfo;           // all the other string data
public:
    void display() const;  // Display the data from one event object
    Event();
    ~Event();
    Error set(String);   // Parses the borrowed/returned status from the rest of the string info.
};


#endif