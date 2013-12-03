#include "history.h"

History::History(){}

History::~History(){}               // deletes each node in the list. 

void History::displayAll() const{	// Iterates through displays all event objects
	//TODO
} 

void History::addEvent(Event* e){ // Adds event to eventList
	eventList.push_back(e);
}