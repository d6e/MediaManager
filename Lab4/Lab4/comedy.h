#ifndef COMEDY_H
#define COMEDY_H
#include "product.h"
#include <string>

/*

*/

class Comedy : public Movie{
public:
	Comedy(); //Inits productData keys.
	~Comedy(void);
	bool setData(Event*); // Returns false if input invalid.
    virtual Product* create(); // Creates a new, empty Drama object
    virtual string type() const;	//returns the type ("comedy") of product. Used as a key.
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
	const std::string COMEDY_DATA_TYPES [] = {"director","title","date"};
	const std::string COMEDY_SORTED_BY [] = {"title","date"};
};

#endif
