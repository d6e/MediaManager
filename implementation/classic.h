#ifndef CLASSIC_H
#define CLASSIC_H
#include "movie.h"
#include <string>

const std::string CLASSIC_DATA_TYPES [] = {"director","title","famous actor","date"};
const std::string CLASSIC_SORTED_BY [] = {"date","famous actor"};


class Classic : public Movie {
public:
    virtual ~Classic(); // cleans up any productdata objects it created
    bool setData(Event*); // Returns false if input invalid.
    virtual Product* create(); // Creates a new, empty genre movie object
    virtual std::string type() const; //returns type ("comedy"). Used as key
    virtual void display(); // Displays contents via cout

    virtual const std::string* dataTypeNames() const;
    virtual const int dataTypeCount() const;
    virtual const std::string* sortedByNames() const;
    virtual const int sortedByCount() const;  
};

#endif