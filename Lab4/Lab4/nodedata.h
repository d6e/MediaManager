#ifndef NODEDATA_H
#define NODEDATA_H
#include <string>
#include <iostream>
#include <fstream>
using namespace std;

// simple class containing one string to use for testing
// not necessary to comment further



class NodeData {
   friend ostream & operator<<(ostream &, const NodeData &) = 0;

public:
   virtual NodeData() = 0; // default constructor, data is set to an empty string
   virtual ~NodeData() = 0;          
         // data is set equal to parameter
   NodeData(const NodeData &);    // copy constructor
   NodeData& operator=(const NodeData &);     
   virtual void duplicate() =0; // signals overridden functions to handle dupiclate items
   virtual string getKey() =0; // returns unique key that tells you type of object

   // comparison operators
   virtual bool operator==(const NodeData &) const = 0;
   virtual bool operator!=(const NodeData &) const = 0;
   virtual bool operator<(const NodeData &) const = 0;
   virtual bool operator>(const NodeData &) const = 0;
   virtual bool operator<=(const NodeData &) const = 0;
   virtual bool operator>=(const NodeData &) const = 0;                
private:
   virtual string dataString() = 0;
};

#endif

