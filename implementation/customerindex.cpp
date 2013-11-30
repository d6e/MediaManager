#include "customerindex.h"
#include <iostream>

CustomerIndex::CustomerIndex(){}

CustomerIndex::~CustomerIndex(){
    for(it = customers.begin(); it != customers.end(); ++it) {
        delete it->second;
    }
}

Error CustomerIndex::addTransaction(std::string custID, Event* event){
    if(customerExists(custID)){
        customers[custID]->addEvent(event);
        return Error("");
    }
    else{
        return Error("Cannot find customer");
    }
}

//displays a customer's history from customer ID
Error CustomerIndex::displayHistory(std::string custID){
    std::cout << "customer: " << custID << std::endl;

    if (customers[custID]){
        std::cout << "customer index displayhistory" << std::endl;

        Customer* cust = customers[custID];
        cust->displayHistory();
        return Error(""); //success
    }
    std::cout << "customer: " << custID << std::endl;

    return Error("Cannot find customer ID");   //fail
}

// adds customer ptr to hashtable
void CustomerIndex::insertCustomer(Customer* cust){
    customers[cust->getID()] = cust;
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