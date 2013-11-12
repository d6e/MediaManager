#ifndef DRAMA_H
#define DRAMA_H
#include "media.h"
class Drama : public Media {
public:
	Drama(String director, String title, String date);
	~Drama(void);
	
	virtual const string* dataTypeNames() const;
	virtual const string* sortedByNames() const;
	virtual string genre() const;	//overridden, always returns "drama"
	
	//comparison operators compare media by their sorting criteria
	virtual bool operator==(const Media &) const;
    virtual bool operator!=(const Media &) const;
    virtual bool operator<(const Media &) const;
    virtual bool operator>(const Media &) const;
    virtual bool operator<=(const Media &) const;
    virtual bool operator>=(const Media &) const;
	
private:
	const string DRAMA_DATA_TYPES [] = {"director","title","date"};
	const string DRAMA_SORTED_BY [] = {"director","title"};
	void addData(string, string);
	void setFormat(string);

};

#endif