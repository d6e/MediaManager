#pragma once
#ifndef DRAMA_H
#define DRAMA_H
#include "product.h"
#include "movie.h"
#include <string>
#include <vector>

/*
The drama class is a child of movie and represents a movie genre. Because
different attributes matter between movies, drama movies hold different
attributes than drama. 
*/

class Drama : public Movie{
public:
	Drama();
	virtual ~Drama(void);
	bool setData(Event*); // Returns false if input invalid.
    virtual Product* create(); // Creates a new, empty Drama object
	
	virtual std::vector<std::string> getDataTypes() const;
	virtual std::vector<std::string> getSortedBy() const;
    virtual int getDataTypeSize() const; // returns size of DataTypes
    virtual int getSortedBySize() const; // returns size of SortedBy
    
    //returns the type ("drama") of product. Used as a key.
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
	std::vector<std::string> DRAMA_DATA_TYPES; //order datatypes are displayed
	std::vector<std::string> dataTypeReadOrder;//order datatypes are read in
	std::vector<std::string> DRAMA_SORTED_BY;  //order datatypes are sorted
};

#endif