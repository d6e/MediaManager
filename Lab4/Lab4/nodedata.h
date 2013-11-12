#ifndef NODEDATA_H
#define NODEDATA_H
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

/*
NodeData is an abstract class which can be a CustomerData object or a MediaData
object.

duplicate() lets the NodeData know that the system has received duplicate data. 
It is not defined in this class, but in the child classes.

getKey() returns some unique identifier providing information about the class
of object stored by NodeData.
*/

class NodeData {
   friend ostream & operator<<(ostream &, const NodeData &) = 0;

public:
   NodeData(); // default constructor, data is set to an empty string
   ~NodeData();          
   NodeData(const NodeData &);    // copy constructor
   NodeData& operator=(const NodeData &);     
   virtual void duplicate() = 0; // signals overridden functions to handle dupiclate items
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

