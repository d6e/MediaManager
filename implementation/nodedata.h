#ifndef NODEDATA_H
#define NODEDATA_H
#include <string>
#include <iostream>
#include <fstream>

const int MAX_DATA_LENGTH = 20;

using namespace std;
//TODO: may need pure virtual display() method for product to use (will be useful in bintrees)
class NodeData {
friend std::ostream& operator<<(std::ostream&, const NodeData&);
public:
    NodeData(); // default constructor,
    virtual ~NodeData();   // destructor
    NodeData(const NodeData &);    // copy constructor
    NodeData& operator=(const NodeData &);     
    // Gives NodeData the duplicate to handle it.
    virtual void duplicate(NodeData*) = 0;
    virtual void display(std::ostream&) const = 0;
    virtual const std::string getKey() const = 0; // returns unique identifier

    virtual std::string dataString() const = 0;

    // comparison operators
    virtual bool operator==(const NodeData &) const = 0;
    virtual bool operator!=(const NodeData &) const = 0;
    virtual bool operator<(const NodeData &) const = 0;
    virtual bool operator>(const NodeData &) const = 0;
    virtual bool operator<=(const NodeData &) const = 0;
    virtual bool operator>=(const NodeData &) const = 0;

    virtual const std::string* dataTypeNames() const = 0;      
    virtual const int dataTypeCount() const = 0;    

private:
    //virtual std::string getData(const std::string) const = 0;      
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


