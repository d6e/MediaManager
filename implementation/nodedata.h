#ifndef NODEDATA_H
#define NODEDATA_H
#include <string>
#include <iostream>
#include <fstream>

const int MAX_DATA_LENGTH = 20;

using namespace std;

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

    // comparison operators
    virtual bool operator==(const NodeData &) const = 0;
    virtual bool operator!=(const NodeData &) const = 0;
    virtual bool operator<(const NodeData &) const = 0;
    virtual bool operator>(const NodeData &) const = 0;
    virtual bool operator<=(const NodeData &) const = 0;
    virtual bool operator>=(const NodeData &) const = 0;

    virtual const std::string* dataTypeNames() const = 0;      
    virtual const int dataTypeCount() const = 0;
    virtual bool available() const = 0;  
    virtual void adjustCount(bool) = 0; 

private:
    //virtual std::string getData(const std::string) const = 0;      
};
#endif