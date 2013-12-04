#include "history.h"

History::History(){
	for(std::list<Event*>::iterator  it = eventList.begin(); 
		it != eventList.end(); ++it){
    		*it = NULL;
    }	
}

History::~History(){	 // deletes each node in the list. 
	for(std::list<Event*>::iterator  it = eventList.begin(); 
		it != eventList.end(); ++it){
		if(*it != NULL){
        	delete *it;
    		*it = NULL;
    	}
    }
}              

void History::displayAll() const{	// Iterates through displays all event objects
	if(eventList.empty()){
		std::cout << "No history to display." << std::endl;
		return;
	}
	for (std::list<Event*>::const_iterator 
	it = eventList.begin(); 
	it != eventList.end(); ++it){
		Event* nextEvent = *it;
		nextEvent -> display();
	}
	std::cout << std::endl;
} 

void History::addEvent(Event* e){ // Adds event to eventList
	eventList.push_back(e);
}
