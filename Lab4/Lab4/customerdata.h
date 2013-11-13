#ifndef CUSTOMERDATA_H
#define CUSTOMERDATA_H
#include "customer.h"
#include "nodedata.h"
#include <string>

/*
The CustomerData class is a child of the NodeData class. It uses polymorphism
to override various functions.

CustomerData has a private Customer pointer.

The comparison operators are used to compare one CustomerData object with 
another by sorting criteria. To do so, they simply call the same operators 
on the CustomerData's respective data objects.

The duplictate() method is used to notify a NodeData object that a duplicate
data instance has been detected. It should call incrementQuantity() on data.

getKey() returns a unique identifier for the *class* (not the specific data) of
data. It does this by calling Customer's dataType(). (for example, a comedy 
Movie would return "moviecomedy" upon this call.) 

The getCustomer method returns the customer object pointer.
*/

class CustomerData : public NodeData {
private:
   Customer* data;                  // points to customer object
public:
   virtual CustomerData();          // constructor
   virtual ~CustomerData();         // destructor
    // CustomerData doesn't need to handle duplicates.
   virtual void duplicate(NodeData*);       
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