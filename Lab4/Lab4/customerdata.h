#ifndef CUSTOMERDATA_H
#define CUSTOMERDATA_H
#include "customer.h"
#include "nodedata.h"
#include <string>

/*
The CustomerData class is a child of the NodeData class. It uses polymorphism
*/

class CustomerData : public NodeData {
private:
    Customer* custPtr;
public:
    CustomerData();
    ~CustomerData();
};

#endif