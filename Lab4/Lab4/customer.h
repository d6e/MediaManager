#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "history.h"
#include <string>

/*
The customer class is used to keep track of customer data. Each customer object 
corresponds to each customer. It possesses a history object.  
*/
class Customer {
private:
    History customerHistory;
    String firstName;
    String lastName;
    String customerID;  // is a four digit int, but storing it as a string is more flexible

public:
    void displayHistory() const; // Calls history's displayAll method
    void addTransaction(String);  // TODO: what is passed into an addTransaction method???
};

#endif