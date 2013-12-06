#pragma once
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "history.h"
#include <string>

/*
The customer class is used to keep track of customer data. Each customer object 
corresponds to each customer. 
*/

class Customer {
private:
    History customerHistory; // customer's history
    std::string customerID;       // four digit int stored as a string
    std::string firstName;        // first name of customer
    std::string lastName;         // last name of customer

public:
    Customer(std::string, std::string, std::string);
    virtual ~Customer();
    void displayHistory() const; // Calls history's displayAll method
    void addEvent(Event*); // Calls history's addTransaction method
    std::string getID() const;          // accessor
    void setID(std::string);            // mutator
    std::string getFirstName() const;   // accessor
    void setFirstName(std::string);     // mutator
    std::string getLastName() const;    // accessor
    void setLastName(std::string);      // mutator
};

#endif