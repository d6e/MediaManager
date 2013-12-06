#include "history.h"
#include <iostream>

History::History(){}

// deletes each node in the list. 
History::~History(){
    std::list<Event*>::iterator it;  //iterator for list of event objects
	for(it = eventList.begin(); it != eventList.end(); ++it){
		delete *it;
	}
}

// Iterates through displays all event objects
void History::displayAll() const{
	std::list<Event*>::const_iterator it;
    for(it = eventList.begin(); it != eventList.end(); ++it){
        (*it)->display();
    }
}

// Adds event to eventList
void History::addEvent(Event* event){
    eventList.push_back(event);
}

