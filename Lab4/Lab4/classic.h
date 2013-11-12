#ifndef CLASSIC_H
#define CLASSIC_H
#include "media.h"
class Classic : public Media {
public:
	Classic(String director, String title, String famousActor, String date);
	~Classic(void);
	virtual const string* dataTypeNames() const;
	virtual const string* sortedByNames() const;
	virtual string genre() const;	//overridden, always returns "classic"
	
	//comparison operators compare media by their sorting criteria
	virtual bool operator==(const Media &) const;
    virtual bool operator!=(const Media &) const;
    virtual bool operator<(const Media &) const;
    virtual bool operator>(const Media &) const;
    virtual bool operator<=(const Media &) const;
    virtual bool operator>=(const Media &) const;
	
private:
	const string CLASSIC_DATA_TYPES [] = {"director","title","famous actor","date"};
	const string CLASSIC_SORTED_BY [] = {"date","famous actor"};
	void addData(string, string);
	void setFormat(string);
};

#endif
