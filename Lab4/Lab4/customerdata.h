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
   virtual string dataString();
public:
   virtual CustomerData();          // constructor
   virtual ~CustomerData();         // destructor
   CustomerData(const Customer*);   // Constructor for customer object
   virtual CustomerData* create(){return new CustomerData();}
   virtual string dataType() const; // returns unique identifier        
   virtual void duplicate();        // LEAVE THIS AN EMPTY METHOD
   virtual Error getKey();          // returns the customer's ID key

   // comparison operators
   virtual bool operator==(const CustomerData &) const;
   virtual bool operator!=(const CustomerData &) const;
   virtual bool operator<(const CustomerData &) const;
   virtual bool operator>(const CustomerData &) const;
   virtual bool operator<=(const CustomerData &) const;
   virtual bool operator>=(const CustomerData &) const;
};

#endif