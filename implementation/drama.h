#pragma once
#ifndef DRAMA_H
#define DRAMA_H
#include "product.h"
#include "movie.h"
#include <string>
#include <vector>

/*
The drama class is a child of movie and represents a movie genre. Because
different attributes matter between movies, drama movies hold different
attributes than drama. 

It's data members consist of two arrays, one array being the data types like
"director", "title", and "date" and another being the data types it's sorted
by, which in this case are "director" and "title".

The constructor creates a bunch of ProductData objects and initializes their
keys.

The destructor deletes any productdata objects it initiated.

The setData method takes in a pointer to an event object and the data it 
contains to the event object's data. If the event object input is invalid,
it returns false, otherwise true.

create() is merely an instatiation method called by the ProductFactory that 
creates a product object.

The type method returns the type of the genre product object. For this one,
it will return the string "drama". This is used as a key for the hashtable.

The display method displays the private data members using cout.

The getDataTypes() and getSortedBy() are helper methods which quickly 
retrieve the corresponding _DATA_TYPES and _SORTED_BY arrays. 

Finally, the comparison operators are used to compare one product object
with another.
*/

class Drama : public Movie{
public:
	Drama();
	virtual ~Drama(void);
	bool setData(Event*); // Returns false if input invalid.
    virtual Product* create(); // Creates a new, empty Drama object
    //returns the type ("drama") of product. Used as a key.
    virtual std::string type() const;	
	
	virtual const std::vector<std::string> getDataTypes() const;
	virtual const std::vector<std::string> getSortedBy() const;
    virtual int getDataTypeSize() const; // returns size of DataTypes
    virtual int getSortedBySize() const; // returns size of SortedBy
	virtual std::string getKey() const;
    std::string getData(std::string key) const;
	
	
	//comparison operators compare product by their sorting criteria
	virtual bool operator==(const NodeData&) const;
    virtual bool operator!=(const NodeData&) const;
    virtual bool operator<(const NodeData&) const;
    virtual bool operator>(const NodeData&) const;
    virtual bool operator<=(const NodeData&) const;
    virtual bool operator>=(const NodeData&) const;
	
private:
	std::vector<std::string> DRAMA_DATA_TYPES;
	std::vector<std::string> DRAMA_SORTED_BY;
};

#endif