#ifndef MEDIADATA_H
#define MEDIADATA_H
#include "nodedata.h"
#include "product.h"
#include <string>

/*
The ProductData class is a child of the NodeData class. It uses polymorphism
to override various functions and is stored in a bintree.

ProductData has a private Product pointer.

dataString() is an inherited method from NodeData, and calls the Product data's
<< operator.

The comparison operators are used to compare one ProductData object with another
by sorting criteria. To do so, they simply call the same operators on the
ProductData's respective data objects.

The duplictate() method is used to notify a NodeData object that a duplicate
data instance has been detected. It should call incrementQuantity() on data.

getKey() returns a unique identifier for the *class* (not the specific data) of
data. It does this by calling Product's dataType(). (for example, a comedy Movie
would return "moviecomedy" upon this call.) 
*/

class ProductData : public NodeData {
private:
   Product* data;
   virtual string dataString();   //calls its data's << operator          
public:
   ProductData();      // constructor
   ~ProductData();     // destructor
   ProductData(const Product *); // constructor for inserting Product 
   virtual ProductData* create(){return new ProductData();}
   void duplicate();  // signals product that quantity should be added.
   virtual string getKey(); // returns unique identifier 
   Product* getProduct();

   // comparison operators
   virtual bool operator==(const ProductData &) const;
   virtual bool operator!=(const ProductData &) const;
   virtual bool operator<(const ProductData &) const;
   virtual bool operator>(const ProductData &) const;
   virtual bool operator<=(const ProductData &) const;
   virtual bool operator>=(const ProductData &) const;
};

#endif