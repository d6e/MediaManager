#ifndef CLASSIC_H
#define CLASSIC_H
#include "product.h"
#include "movie.h"
#include <string>

/*
The classic class is a child of movie and represents a movie genre. Because
different attributes matter between movies, classic movies hold different
attributes than drama. 

It's data members consist of two arrays, one array being the data types like
"director", "title", "famous actor", and "date" and another being the data types it's sorted
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
	Classic(std::string director, std::string title, std::string famousActor, std::string date);
	~Classic(void);
	
	bool setData(Event*); // Returns false if input invalid.
    virtual Product* create(); // Creates a new, empty Classic object
    virtual std::string type() const;	//returns the type ("classic") of product. Used as a key.
	virtual void display(); // Displays contents via cout
	
	virtual const std::string* dataTypeNames() const;
	virtual const std::string* sortedByNames() const;
	
	//comparison operators compare product by their sorting criteria
	virtual bool operator==(const Product &) const;
    virtual bool operator!=(const Product &) const;
    virtual bool operator<(const Product &) const;
    virtual bool operator>(const Product &) const;
    virtual bool operator<=(const Product &) const;
    virtual bool operator>=(const Product &) const;
	
private:
	const std::string CLASSIC_DATA_TYPES [] = {"director","title","famous actor","date"};
	const std::string CLASSIC_SORTED_BY [] = {"date","famous actor"};
};

#endif
