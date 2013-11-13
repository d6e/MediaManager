#ifndef CLASSIC_H
#define CLASSIC_H
#include "product.h"
class Classic : public Movie{
public:
	Classic(String director, String title, String famousActor, String date);
	~Classic(void);
	
	bool setData(Event*); // Returns false if input invalid.
    virtual Product* create(); // Creates a new, empty Drama object
    virtual string type() const;	//returns the type ("comedy") of product. Used as a key.
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
	const string CLASSIC_DATA_TYPES [] = {"director","title","famous actor","date"};
	const string CLASSIC_SORTED_BY [] = {"date","famous actor"};
};

#endif
