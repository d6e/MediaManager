#include "customer.h"

void Customer::displayHistory() const{
    customerHistory.displayAll();
}

void Customer::addEvent(Event* event){
    customerHistory.addTransaction(event);
}

std::string Customer::getID(){
    return customerID;
}
