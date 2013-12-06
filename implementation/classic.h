#pragma once
#ifndef CLASSIC_H
#define CLASSIC_H
#include "product.h"
#include "movie.h"
#include <string>
#include <vector>

/*
The classic class is a child of movie and represents a movie genre. Because
different attributes matter between movies, classic movies hold different
attributes than drama. 
*/

class Classic : public Movie{
public:
	Classic();
	virtual ~Classic();
	
	bool setData(Event*); // Returns false if input invalid.
    virtual Product* create(); // Creates a new, empty Classic object
	
	virtual std::vector<std::string> getDataTypes() const;
	virtual std::vector<std::string> getSortedBy() const;
    virtual int getDataTypeSize() const; // returns size of DataTypes
    virtual int getSortedBySize() const; // returns size of SortedBy

    //returns the type ("classic") of product. Used as a key.
	virtual std::string getName() const;
    std::string getData(std::string key) const;
    virtual char getKey() const; // returns unique identifier

	
	//comparison operators compare product by their sorting criteria
	virtual bool operator==(const NodeData&) const;
    virtual bool operator!=(const NodeData&) const;
    virtual bool operator<(const NodeData&) const;
    virtual bool operator>(const NodeData&) const;
    virtual bool operator<=(const NodeData&) const;
    virtual bool operator>=(const NodeData&) const;
	
private:
	std::vector<std::string> CLASSIC_DATA_TYPES; //order of output datatypes
	std::vector<std::string> dataTypeReadOrder; //order datatypes are read in
	std::vector<std::string> CLASSIC_SORTED_BY; //how data types are sorted
};

#endif
