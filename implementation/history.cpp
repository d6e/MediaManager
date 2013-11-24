#include "history.h"
#include <iostream>

History::History(){

}

// deletes each node in the list. 
History::~History(){
    eventList.clear();
}

// Iterates through displays all event objects
void History::displayAll() const{
    for (std::list<Event*>::const_iterator it = eventList.begin(); it != eventList.end(); ++it){
        (*it)->display();
    }
}

// Adds event to eventList
void History::addEvent(Event* event){
    eventList.push_back(event);
}

