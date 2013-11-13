#ifndef DRAMA_H
#define DRAMA_H
#include "product.h"
class Drama : public Movie{
public:
	Drama();
	~Drama(void);
	bool setData(Event*); // Returns false if input invalid.
    virtual Product* create(); // Creates a new, empty Drama object
    virtual string type() const;	//returns the type ("drama") of product. Used as a key.
	virtual void display(); // Displays contents via cout
	
	virtual const string* dataTypeNames() const;
	virtual const string* sortedByNames() const;
	
	//comparison operators compare product by their sorting criteria
	virtual bool operator==(const Product &) const;
    virtual bool operator!=(const Product &) const;
    virtual bool operator<(const Product &) const;
    virtual bool operator>(const Product &) const;
    virtual bool operator<=(const Product &) const;
    virtual bool operator>=(const Product &) const;
	
private:
	const string DRAMA_DATA_TYPES [] = {"director","title","date"};
	const string DRAMA_SORTED_BY [] = {"director","title"};
};

#endif