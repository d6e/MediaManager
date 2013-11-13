#ifndef DRAMA_H
#define DRAMA_H
#include "product.h"
class Drama : public Media{
public:
	Drama(String director, String title, String date);
	~Drama(void);
	
	virtual const string* dataTypeNames() const;
	virtual const string* sortedByNames() const;
	virtual string genre() const;	//overridden, always returns "drama"
	
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
	void addData(string, string);
	void setFormat(string);

};

#endif