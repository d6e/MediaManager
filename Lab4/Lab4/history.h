#ifndef HISTORY_H
#define HISTORY_H
#include "event.h"
#include <list>

/*
History objects hold a list of event objects which can be displayed.
On construction, create an empty list and insert an event object if a 
event object is passed in. On destruction, delete each node in
the list. When any sort of customer transaction is made, add an event object
to the list and the list is expanded. 
*/
class History {
private:
    std::list<Event> eventList;  //list of event objects

public:
    History();
    History(Event&);
    ~History();
    void displayAll() const;  //Iterates through displays all event objects

};
#endif