#include "customerindex.h"

CustomerIndex::CustomerIndex(){
    customers = new Customer[size]; // create array of customers
    for(int i = 0; i < size; i++){ // intialize array elements to NULL
        customers[i] = NULL;
    }
}

virtual CustomerIndex::~CustomerIndex(){
    delete[] customers;
    customers = NULL;
}

Error CustomerIndex::addTransaction(std::string custID, Event* event){
    for(int i = 0; i < size; i++){
        if(customers[i].getID() == custID){
            customers[i].addEvent(event);
            return Error("");
        }
    }
    return Error("Cannot find customer ID");
}

// checks whether customer obj exists from an customer id
bool CustomerIndex::customerExists(std::string custID){
    for(int i = 0; i < size; i++){
        if(customers[i].getID() == custID){
            return true;
        }
    }
    return false;
}

//displays a customer's history from customer ID
Error CustomerIndex::displayHistory(std::string custID) const{
    for(int i = 0; i < size; i++){
        if(customers[i].getID() == custID){
            customers[i].displayHistory();
            return Error("");
        }
    }
    return Error("Cannot find customer ID");
}

// adds customer ptr to hashtable
Error CustomerIndex::insertCustomer(Customer* cust){
    for(int i = 0; i < size; i++){
        if(customers[i] == NULL){
            customers[i] = cust;
            return Error("");
        }
    }
    return Error("Customer array is full. No room to insert");
}
