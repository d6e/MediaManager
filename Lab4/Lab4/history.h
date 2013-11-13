#ifndef HISTORY_H
#define HISTORY_H
#include "event.h"
#include <list>
#include <string>

/*
History objects hold a list of event objects. It is used to keep track of
customer transaction history.

On destruction, delete each node in the list. 

The displayAll method iterates through the eventList calling each object's
display method.

The addTransaction method takes in a string, creates an empty event object,
and calls that event object's set method passing in the string that was 
passed into it. Finally, it appends that event object onto the end of the
eventlist.
*/

class History {
private:
    std::list<Event> eventList;  //list of event objects

public:
    History();
    ~History();               // deletes each node in the list. 
    void displayAll() const;  // Iterates through displays all event objects
    void addTransaction(std::string);// Creates a new event and adds it to eventList

};
#endif