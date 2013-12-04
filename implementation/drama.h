#ifndef DRAMA_H
#define DRAMA_H
#include "movie.h"
#include <string>

const std::string DRAMA_DATA_TYPES [] = {"director","title","date"};
const std::string DRAMA_SORTED_BY [] = {"director","title"};


class Drama : public Movie {
public:
    //Comedy(); //Inits productData keys.
    virtual ~Drama(); // cleans up any productdata objects it created
    //bool setData(Event*); // Returns false if input invalid.
    virtual Product* create(); // Creates a new, empty genre movie object
    virtual std::string type() const; //returns type ("comedy"). Used as key
    virtual void display(); // Displays contents via cout

    virtual const std::string* dataTypeNames() const;
    virtual const int dataTypeCount() const;
    virtual const std::string* sortedByNames() const;
    virtual const int sortedByCount() const;  
};

#endif