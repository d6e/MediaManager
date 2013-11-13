#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "history.h"
#include <string>

/*
The customer class is used to keep track of customer data. Each customer object 
corresponds to each customer. 

As private datamembers, it possesses a history
object which is used to log all customer transactions, a first name string,
a last name string, and a string for the customer ID. The customerID is a four
digit int, but storing it as a string will be more flexible for the future.
This shouldn't be a problem since strings of numbers are still comparable and
we won't need to perform any arithmatic on the customerIDs.

The displayHistory method displays the history by calling its history object's
displayAll method.

The addTransaction method takes in a string and calls the history object's 
addTransaction method with the string as a parameter.
*/
class Customer {
private:
    History customerHistory; // customer's history
    std::string firstName;        // first name of customer
    std::string lastName;         // last name of customer
    std::string customerID;       // four digit int stored as a string

public:
    void displayHistory() const; // Calls history's displayAll method
    void addEvent(Event*); // Calls history's addTransaction method
};

#endif