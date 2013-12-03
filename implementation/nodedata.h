#pragma once
#ifndef NODEDATA_H
#define NODEDATA_H
#include <string>
#include <vector>
#include <iostream>
#include <fstream>

/*
NodeData is an abstract class which can be a CustomerData object or a 
ProductData object.

duplicate() lets the NodeData know that the system has received duplicate data. 
and gives it the duplicate so that it can handle it.
It is not defined in this class, but in the child classes.

getKey() returns some unique identifier providing information about the class
of object stored by NodeData.
*/

const int MAX_DATA_LENGTH = 20; //TODO: find a way for this not to be global

class NodeData {
    friend std::ostream& operator<<(std::ostream&, const NodeData&);
public:
    NodeData(); // default constructor
    virtual ~NodeData();   // destructor
    NodeData(const NodeData &);    // copy constructor
    NodeData& operator=(const NodeData &);   //assignment operator
    virtual void display(std::ostream&) const = 0;
    // Gives NodeData the duplicate to handle it.
    virtual void duplicate(NodeData*) = 0;  
    virtual std::string getKey() const = 0; // returns unique identifier

    // comparison operators
    virtual bool operator==(const NodeData &) const = 0;
    virtual bool operator!=(const NodeData &) const = 0;
    virtual bool operator<(const NodeData &) const = 0;
    virtual bool operator>(const NodeData &) const = 0;
    virtual bool operator<=(const NodeData &) const = 0;
    virtual bool operator>=(const NodeData &) const = 0;                

    virtual const std::vector<std::string> dataTypeNames() const = 0;      
    virtual int getDataTypeSize() const = 0; // returns size of DataTypes
};

#endif

