#include "customer.h"
#include <iostream>   


Customer::Customer(std::string id, std::string first, std::string last){
    customerID = id;
    firstName = first;
    lastName = last;
    std::cout << "Customer Created" << std::endl;
}

Customer::~Customer(){
    std::cout << "Customer destroyed" << std::endl;
}

void Customer::displayHistory() const{
    customerHistory.displayAll();
}

void Customer::addEvent(Event* eventPtr){
    customerHistory.addEvent(eventPtr);
}

std::string Customer::getID() const{
    return customerID;
}

void Customer::setID(std::string id){
    customerID = id;
}

std::string Customer::getFirstName() const{
    return firstName;
}

void Customer::setFirstName(std::string first){
    firstName = first;
}

std::string Customer::getLastName() const{
    return lastName;
}

void Customer::setLastName(std::string last){
    lastName = last;
}
