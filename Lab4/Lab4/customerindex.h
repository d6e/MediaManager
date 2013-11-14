#ifndef CUSTOMERINDEX_H
#define CUSTOMERINDEX_H
#include "customer.h"
#include "error.h"
#include "hashtable.h"
#include <string>

/*
The customerindex class that constains all customer objects for each customer 
who uses the system.   

The class has a private datamember called custHT. It's a hashtable used to
hold pointers to the customer objects. The key for it is the customerID.

The addTransaction method looks up the customer object in the hashtable 
using custID as a key, it then calls the customer object's addTransaction
method using the passed in string as a parameter. If the customer object
does not exist it creates an error object with an error message string as a 
parameter, if it does exist, the error object has an empty string.

The customerExists method determines whether the customer object corresponding
to the custID exists. It attempts to look up the customer object in the 
hash table using custID as a key, if it exists it returns true, otherwise
it returns false.

The displayHistory method displays the customer's history by calling the
customer object's displayHistory method. It looks up the customer object
in the customer hash table using the custID parameter and if it does not exist
it returns an Error object with an error message string describing the error,
otherwise, if the object does exist it returns an Error object with an empty
string. 

The insertCustomer method inserts a pointer to a customer object into the 
private member hashtable. It takes in a string used for the customerID which is
the key in the hashtable customer pointer and inserts it into
the custHT. 
*/

class CustomerIndex {
private:
    HashTable custHT; // A hashtable used to hold the customer objects
public:
    CustomerIndex();     //constructor
    virtual ~CustomerIndex();    //destructor
    Error addTransaction(Event*); // calls customer's addTransaction
     // checks whether customer obj exists from an customer id
    bool customerExists(std::string);  
    //displays a customer's history from customer ID
    Error displayHistory(std::string) const; 
    void insertCustomer(Customer*); // adds customer ptr to hashtable
};

#endif