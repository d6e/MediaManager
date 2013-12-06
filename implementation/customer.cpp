#include "customer.h"
#include <iostream>


Customer::Customer(std::string id, std::string first, std::string last){
    customerID = id;
    firstName = first;
    lastName = last;
}

Customer::~Customer(){}

//Displays the customer's history
void Customer::displayHistory() const{
    std::cout << "  *** Customer ID = " << customerID;
    std::cout << "  " << firstName << " " << lastName << std::endl;
    customerHistory.displayAll();
}

//Adds an event to the customer's history object
void Customer::addEvent(Event* eventPtr){
    customerHistory.addEvent(eventPtr);
}

//Accessor for customerID data member
std::string Customer::getID() const{
    return customerID;
}

//Mutator for customerID data member
void Customer::setID(std::string id){
    customerID = id;
}

//Accessor for the customer's first name
std::string Customer::getFirstName() const{
    return firstName;
}

//Mutator for the customer's first name
void Customer::setFirstName(std::string first){
    firstName = first;
}

//Accessor for the customer's last name
std::string Customer::getLastName() const{
    return lastName;
}

//Mutator for the customer's last name
void Customer::setLastName(std::string last){
    lastName = last;
}
