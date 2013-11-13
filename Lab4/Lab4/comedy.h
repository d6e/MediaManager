#ifndef COMEDY_H
#define COMEDY_H
#include "product.h"
#include <string>

/*

*/

class Comedy : public Media{
public:
	Comedy(std::string director, std::string title);
	~Comedy(void);

	virtual const std::string* dataTypeNames() const;
	virtual const std::string* sortedByNames() const;
	virtual std::string genre() const;	//overridden, always returns "comedy"
	
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
	void addData(std::string, std::string);
	void setFormat(std::string);
};

#endif
