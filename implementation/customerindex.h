#pragma once
#ifndef CUSTOMERINDEX_H
#define CUSTOMERINDEX_H
#include "customer.h"
#include "error.h"
#include "hashtable.h"
#include <string>
#include <map>

/*
The customerindex class that constains all customer objects for each customer 
who uses the system.   
*/

class CustomerIndex {
private:
    std::map<std::string, Customer*> customers; // A hashmap for customers objs 
    std::map<std::string, Customer*>::iterator it; // customers iterator
    History unknownCustHist;  // Used to store events that have no customers
public:
    CustomerIndex();  //constructor
    virtual ~CustomerIndex();    //destructor
    Error addTransaction(std::string,Event*); //calls customer's addTransaction
     // checks whether customer obj exists from an customer id
    bool customerExists(std::string);  
    //displays a customer's history from customer ID
    Error displayHistory(std::string); 
    Error insertCustomer(Customer*); // adds customer ptr to hashtable
};

#endif