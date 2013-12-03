#include "customerindex.h"

CustomerIndex::CustomerIndex(){	 //constructor
	//TODO
}    

CustomerIndex::~CustomerIndex(){    //destructor
	//TODO
}

Error CustomerIndex::addTransaction(Event* e){ // calls customer's addTransaction
	Error empty;
	//TODO: grab custId from event and perform the transaction (which is probably
		//a borrow or return command)
	return empty;
}

// checks whether customer obj exists from an customer id
bool CustomerIndex::customerExists(std::string custId){
	//TODO: plug in custId, should return NULL if customer isn't there
	return false;
}

//displays a customer's history from customer ID
Error CustomerIndex::displayHistory(std::string custId) const{
	Error empty;
	//TODO: plug in custId and display resultant customer's history
	return empty;
} 

void CustomerIndex::insertCustomer(Customer* c){ // adds customer ptr to hashtable
	//TODO
}