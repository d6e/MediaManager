#ifndef CUSTOMERINDEX_H
#define CUSTOMERINDEX_H
#include "customer.h"
#include "error.h"
#include <string>

/*
The customerindex class is used to hold customer objects.   
*/
class CustomerIndex {
private:
    HashTable custHT;
public:
    CustomerIndex();
    Error addTransaction(custID, String);
    bool customerExists(custID);
    Error displayHistory(custID) const;
};

#endif