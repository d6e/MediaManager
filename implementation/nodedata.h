#ifndef NODEDATA_H
#define NODEDATA_H
#include <string>
#include <iostream>
#include <fstream>
//#include "movie.h"
using namespace std;

class NodeData {
public:
    NodeData(); // default constructor,
    virtual ~NodeData();   // destructor
    NodeData(const NodeData &);    // copy constructor
    NodeData& operator=(const NodeData &);     
    // Gives NodeData the duplicate to handle it.
    virtual void duplicate(NodeData*) = 0; 
    virtual std::string getKey() = 0; // returns unique identifier

    // comparison operators
    virtual bool operator==(const NodeData &) const = 0;
    virtual bool operator!=(const NodeData &) const = 0;
    virtual bool operator<(const NodeData &) const = 0;
    virtual bool operator>(const NodeData &) const = 0;
    virtual bool operator<=(const NodeData &) const = 0;
    virtual bool operator>=(const NodeData &) const = 0;                
};
#endif
// simple class containing one string to use for testing
// not necessary to comment further
/*
class NodeData {
   friend ostream & operator<<(ostream &, const NodeData &);

public:
   NodeData();          // default constructor, data is set to an empty string
   ~NodeData();          
   NodeData(const Movie *);      // data is set equal to parameter
   NodeData(const NodeData &);    // copy constructor
   NodeData& operator=(const NodeData &);

   // set class data from data file
   // returns true if the data is set, false when bad data, i.e., is eof
   bool setData(istream&);                

   bool operator==(const NodeData &) const;
   bool operator!=(const NodeData &) const;
   bool operator<(const NodeData &) const;
   bool operator>(const NodeData &) const;
   bool operator<=(const NodeData &) const;
   bool operator>=(const NodeData &) const;
   string genre();
   void incrementCount(int);
private:
   const Movie* data;          
   int count;
};
*/


