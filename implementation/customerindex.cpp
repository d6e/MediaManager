#include "customerindex.h"
#include <iostream>

CustomerIndex::CustomerIndex(){}

CustomerIndex::~CustomerIndex(){}

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
        return Error("");
    }
    return Error("Cannot find customer ID");   
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