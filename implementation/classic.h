#pragma once
#ifndef CLASSIC_H
#define CLASSIC_H
#include "product.h"
#include "movie.h"
#include <string>
#include <vector>

/*
The classic class is a child of movie and represents a movie genre. Because
different attributes matter between movies, classic movies hold different
attributes than drama. 

It's data members consist of two arrays, one array being the data types like
"director", "title", "famous actor", and "date" and another being the data 
types it's sorted
by, which in this case are "date" and "famous actor".

The constructor creates a bunch of ProductData objects and initializes their
keys.

The destructor deletes any productdata objects it initiated.

The setData method takes in a pointer to an event object and the data it 
contains to the event object's data. If the event object input is invalid,
it returns false, otherwise true.

create() is merely an instatiation method called by the ProductFactory that 
creates a product object.

The type method returns the type of the genre product object. For this one,
it will return the string "classic". This is used as a key for the hashtable.

The display method displays the private data members using cout.

The dataTypeNames() and sortedByNames() are helper methods which quickly 
retrieve the corresponding _DATA_TYPES and _SORTED_BY arrays. 

Finally, the comparison operators are used to compare one product object
with another.
*/

class Classic : public Movie{
public:
	Classic();
	virtual ~Classic();
	
	bool setData(Event*); // Returns false if input invalid.
    virtual Product* create(); // Creates a new, empty Classic object
    //returns the type ("classic") of product. Used as a key.
    virtual std::string type() const;	
	
	virtual const std::string dataTypeNames() const;
	virtual const std::string sortedByNames() const;
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
	std::vector<std::string> CLASSIC_DATA_TYPES;
	std::vector<std::string> CLASSIC_SORTED_BY;
};

#endif
