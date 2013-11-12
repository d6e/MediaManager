#ifndef CUSTOMERINDEX_H
#define CUSTOMERINDEX_H
#include "customer.h"
#include "error.h"
#include "hashtable.h"
#include <string>

/*
The customerindex class is used to hold customer objects which corresponds
to each customer that uses the system.   

The addTransaction method looks up the customer object in the hashtable 
using custID as a key, it then calls the customer object's addTransaction
method using the passed in string as a parameter. If the customer object
does not exist it creates an error object with an error message string as a 
parameter, if it does exist, the error object has an empty string.

The customerExists method determines whether the customer object corresponding
to the custID exists. It attempts to look up the customer object in the 
hash table using custID as a key, if it exists it returns true, otherwise
false.

The displayHistory method displays the customer's history by calling the
customer object's displayHistory method. It looks up the customer object
in the customer hash table and if it does not exist
*/
class CustomerIndex {
private:
    HashTable custHT;
public:
    CustomerIndex();
    Error addTransaction(custID, String);  // looks up custID in hashtable, calls the costomer
    bool customerExists(custID);
    Error displayHistory(custID) const;
};

#endif