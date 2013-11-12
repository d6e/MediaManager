#ifndef NODEDATA_H
#define NODEDATA_H
#include <string>
#include <iostream>
#include <fstream>
#include "media.h"
using namespace std;

// simple class containing one string to use for testing
// not necessary to comment further

class NodeData {
   friend ostream & operator<<(ostream &, const NodeData &);

public:
   virtual NodeData() = 0;          // default constructor, data is set to an empty string
   virtual ~NodeData() = 0;          
         // data is set equal to parameter
   NodeData(const NodeData &);    // copy constructor
   NodeData& operator=(const NodeData &);
   bool setData(istream&);     
   virtual bool operator==(const NodeData &) const = 0;
   virtual bool operator!=(const NodeData &) const = 0;
   virtual bool operator<(const NodeData &) const = 0;
   virtual bool operator>(const NodeData &) const = 0;
   virtual bool operator<=(const NodeData &) const = 0;
   virtual bool operator>=(const NodeData &) const = 0;                
};

#endif

