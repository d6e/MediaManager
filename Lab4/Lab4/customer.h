#ifndef CUSTOMER_H
#define CUSTOMER_H
#include history.h
#include <string>

/*
The customer class is used to keep track of customer data. Each customer object 
corresponds to each customer. It possesses a history object.  
*/
class Customer {
public:
    void displayHistory() const; // Calls history's displayAll method
    void addTransaction();  // TODO: what is passed into an addTransaction method???

private:
    History customerHistory;
    String firstName;
    String lastName;
    int customerID;   // is a four digit int
};

#endif