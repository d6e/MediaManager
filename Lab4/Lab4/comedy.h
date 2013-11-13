#ifndef COMEDY_H
#define COMEDY_H
#include "product.h"
class Comedy : public Media {
public:
	Comedy(String director, String title);
	~Comedy(void);

	virtual const string* dataTypeNames() const;
	virtual const string* sortedByNames() const;
	virtual string genre() const;	//overridden, always returns "comedy"
	
	//comparison operators compare media by their sorting criteria
	virtual bool operator==(const Media &) const;
    virtual bool operator!=(const Media &) const;
    virtual bool operator<(const Media &) const;
    virtual bool operator>(const Media &) const;
    virtual bool operator<=(const Media &) const;
    virtual bool operator>=(const Media &) const;
	
private:
	const string COMEDY_DATA_TYPES [] = {"director","title","date"};
	const string COMEDY_SORTED_BY [] = {"title","date"};
	void addData(string, string);
	void setFormat(string);
};

#endif
