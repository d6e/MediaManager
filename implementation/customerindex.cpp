#include "customerindex.h"

CustomerIndex::CustomerIndex(){	 //constructor
	//TODO
}    

CustomerIndex::~CustomerIndex(){    //destructor
	//TODO
}

Error CustomerIndex::addTransaction(Event* e){ // calls customer's addTransaction
	Error empty;
	//TODO
	return empty;
}

// checks whether customer obj exists from an customer id
bool CustomerIndex::customerExists(std::string custId){
	//TODO
	return false;
}

//displays a customer's history from customer ID
Error CustomerIndex::displayHistory(std::string custId) const{
	Error empty;
	//TODO
	return empty;
} 

void CustomerIndex::insertCustomer(Customer*){ // adds customer ptr to hashtable
	//TODO
}