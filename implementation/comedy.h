#pragma once
#ifndef COMEDY_H
#define COMEDY_H
#include "product.h"
#include "movie.h"
#include <string>
#include <vector>

/*
The comedy class is a child of movie and represents a movie genre. Because
different attributes matter between movies, comedy movies hold different
attributes than drama. 
*/

class Comedy : public Movie {
public:
	Comedy(); //Inits productData keys.
	virtual ~Comedy(); // cleans up any productdata objects it created
	bool setData(Event*); // Returns false if input invalid.
    virtual Product* create(); // Creates a new, empty genre movie object

	virtual std::vector<std::string> getDataTypes() const;
	virtual std::vector<std::string> getSortedBy() const;	
    virtual int getDataTypeSize() const; // returns size of DataTypes
    virtual int getSortedBySize() const; // returns size of SortedBy
    
    //returns type ("comedy"). Used as key
    virtual std::string getName() const; // returns unique identifier
    virtual char getKey() const; // returns unique identifier
    std::string getData(std::string key) const;

	//comparison operators compare product by their sorting criteria
	virtual bool operator==(const NodeData&) const;
    virtual bool operator!=(const NodeData&) const;
    virtual bool operator<(const NodeData&) const;
    virtual bool operator>(const NodeData&) const;
    virtual bool operator<=(const NodeData&) const;
    virtual bool operator>=(const NodeData&) const;
	
private:
    std::vector<std::string> COMEDY_DATA_TYPES; //order datatypes are printed
    std::vector<std::string> dataTypeReadOrder; //order datatypes are read in
    std::vector<std::string> COMEDY_SORTED_BY;  //order datatypes are sorted
};

#endif
