#include "customerindex.h"

CustomerIndex::CustomerIndex(){	 //constructor
	for(int i = 0; i < MAX_CUSTOMER_COUNT; i++){
		customers[i] = NULL;
	}
}    

CustomerIndex::~CustomerIndex(){    //destructor
	for(int i = 0; i < MAX_CUSTOMER_COUNT; i++){
		if(customers[i] != NULL){
			delete customers[i];
			customers[i] = NULL;
		}
	}
}

Error CustomerIndex::addTransaction(Event* e){ // calls customer's addTransaction
	std::string id = e -> getToken(1); 
	if(customerExists(id)){
		int index = convertID(id);
		customers[index] -> addEvent(e);
		return Error("");
	}
	return Error("Cannot add transaction because customer was not found.");
}

// checks whether customer obj exists from an customer id
bool CustomerIndex::customerExists(std::string custID) const{
	int index = convertID(custID);
	return customers[index] != NULL;
}

//displays a customer's history from customer ID
Error CustomerIndex::displayHistory(std::string custID) const{
	if(customerExists(custID)){
		int index = convertID(custID);
		customers[index] -> displayHistory();
		return Error("");
	}
	return Error("Cannot display history because customer was not found.");
} 

void CustomerIndex::insertCustomer(Customer* c){ // adds customer ptr to hashtable
	std::string id = c -> getKey();
	if(!customerExists(id)){
		int index = convertID(id);
		customers[index] = c;
	}
	//TODO: case where customer is already in the hashtable
}

int CustomerIndex::convertID(std::string custID) const{
	return atoi(custID.c_str());
}