#ifndef CUSTOMERINDEX_H
#define CUSTOMERINDEX_H
#include "customer.h"

/*
The customerindex class is used to hold customer objects.   
*/
class CustomerIndex {
private:
    HashTable custHT;
public:
    CustomerIndex();
    Error addTransaction(custID, String);
    bool customerExists(iD);
    Error displayHistory(iD)const;
};

#endif