#ifndef CUSTOMERDATA_H
#define CUSTOMERDATA_H
#include "customer.h"
#include "nodedata.h"
#include <string>

/*
The CustomerData class is a child of the NodeData class. It uses polymorphism
to override various functions.

CustomerData has a private customer pointer.

There is a whole set of comparison operators which are used to compare one
CustomerData object with another. 
*/

class CustomerData : public NodeData {
private:
   Customer* data;                  // points to customer object
public:
   virtual CustomerData();          // constructor
   virtual ~CustomerData();         // destructor
   virtual void duplicate(NodeData*);        // CustomerData doesn't need to handle duplicates.
   virtual bool getKey();          // returns the customer's ID key
   Customer* getCustomer(); //returns the Customer CustomerData is pointing to.

   // comparison operators
   virtual bool operator==(const CustomerData &) const;
   virtual bool operator!=(const CustomerData &) const;
   virtual bool operator<(const CustomerData &) const;
   virtual bool operator>(const CustomerData &) const;
   virtual bool operator<=(const CustomerData &) const;
   virtual bool operator>=(const CustomerData &) const;
};

#endif