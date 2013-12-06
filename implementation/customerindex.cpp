#include "customerindex.h"
#include <iostream>

CustomerIndex::CustomerIndex(){}

CustomerIndex::~CustomerIndex(){
    for(it = customers.begin(); it != customers.end(); ++it) {
        delete it->second;
    }
}

//Adds a transaction to the customer history
Error CustomerIndex::addTransaction(std::string custID, Event* event){
    if(customerExists(custID)){
        customers[custID]->addEvent(event);
        return Error("");
    }
    else{
        unknownCustHist.addEvent(event);
        return Error("Cannot find customer");
    }
}

//displays a customer's history from customer ID
Error CustomerIndex::displayHistory(std::string custID){
    if (customers[custID]){
        Customer* cust = customers[custID];
        cust->displayHistory();
        return Error(""); //success
    }
    return Error("Cannot find customer ID");   //fail
}

// adds customer ptr to hashtable
Error CustomerIndex::insertCustomer(Customer* cust){
    if(cust->getID() == ""){
        return Error("Error: That ID does not exist.");
    }
    customers[cust->getID()] = cust;
    return Error("");
}


// checks whether customer obj exists from an customer id
bool CustomerIndex::customerExists(std::string custID){
    if (customers[custID]){
        return true;
    }
    else{
        return false;
    }
}