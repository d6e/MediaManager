#ifndef NODEDATA_H
#define NODEDATA_H
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

/*
NodeData is an abstract class which can be a CustomerData object or a ProductData
object.

duplicate() lets the NodeData know that the system has received duplicate data. 
and gives it the duplicate so that it can handle it.
It is not defined in this class, but in the child classes.

getKey() returns some unique identifier providing information about the class
of object stored by NodeData.
*/

class NodeData {
public:
   NodeData(); // default constructor,
   ~NodeData();   // destructor
   NodeData(const NodeData &);    // copy constructor
   NodeData& operator=(const NodeData &);     
   virtual void duplicate(NodeData*) = 0; // Gives NodeData the duplicate to handle it.
   virtual string getKey() = 0; // returns unique identifier

   // comparison operators
   virtual bool operator==(const NodeData &) const = 0;
   virtual bool operator!=(const NodeData &) const = 0;
   virtual bool operator<(const NodeData &) const = 0;
   virtual bool operator>(const NodeData &) const = 0;
   virtual bool operator<=(const NodeData &) const = 0;
   virtual bool operator>=(const NodeData &) const = 0;                
};

#endif

