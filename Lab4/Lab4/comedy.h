#ifndef COMEDY_H
#define COMEDY_H
#include "product.h"
class Comedy : public Product {
public:
	Comedy(String director, String title);
	~Comedy(void);

	virtual const string* dataTypeNames() const;
	virtual const string* sortedByNames() const;
	virtual string genre() const;	//overridden, always returns "comedy"
	
	//comparison operators compare product by their sorting criteria
	virtual bool operator==(const Product &) const;
    virtual bool operator!=(const Product &) const;
    virtual bool operator<(const Product &) const;
    virtual bool operator>(const Product &) const;
    virtual bool operator<=(const Product &) const;
    virtual bool operator>=(const Product &) const;
	
private:
	const string COMEDY_DATA_TYPES [] = {"director","title","date"};
	const string COMEDY_SORTED_BY [] = {"title","date"};
	void addData(string, string);
	void setFormat(string);
};

#endif
