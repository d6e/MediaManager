#ifndef COMEDY_H
#define COMEDY_H
//#include "product.h"
#include "movie.h"
#include <string>

const std::string COMEDY_DATA_TYPES [] = {"director","title","date"};
const std::string COMEDY_SORTED_BY [] = {"title","date"};
/*
The comedy class is a child of movie and represents a movie genre. Because
different attributes matter between movies, comedy movies hold different
attributes than drama. 

It's data members consist of two arrays, one array being the data types like
"director", "title", and "date" and another being the data types it's sorted
by, which in this case are "title" and "date".

The constructor creates a bunch of ProductData objects and initializes their
keys.

The destructor deletes any productdata objects it initiated.

The setData method takes in a pointer to an event object and the data it 
contains to the event object's data. If the event object input is invalid,
it returns false, otherwise true.

create() is merely an instatiation method called by the ProductFactory that 
creates a product object.

The type method returns the type of the genre product object. For this one,
it will return the string "comedy". This is used as a key for the hashtable.

The display method displays the private data members using cout.

The dataTypeNames() and sortedByNames() are helper methods which quickly 
retrieve the corresponding _DATA_TYPES and _SORTED_BY arrays. 

Finally, the comparison operators are used to compare one product object
with another.
*/

class Comedy : public Movie {
public:
    //Comedy(); //Inits productData keys.
    virtual ~Comedy(); // cleans up any productdata objects it created
    bool setData(Event*); // Returns false if input invalid.
    virtual Product* create(); // Creates a new, empty genre movie object
    virtual std::string type() const; //returns type ("comedy"). Used as key

    virtual const std::string* dataTypeNames() const;
    virtual const int dataTypeCount() const;
    virtual const std::string* sortedByNames() const;
    virtual const int sortedByCount() const;
};

#endif