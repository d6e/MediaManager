#ifndef PRODUCTFORMAT_H
#define PRODUCTFORMAT_H
#include <string>

/*
Specifies a product's format. For a movie, this could be a DVD or Blueray.

The constructor takes in a string and sets the private datamember to it.

The getName method returns the private formatname string.

The equals method checks if two productformats match. Returns true if they 
are, false if they're not.
*/

class ProductFormat {
public:
	ProductFormat(std::string); // constructor
	std::string getName(); // returns the private formatname string
    //Checks if two ProductFormats are equivilent
	bool equals(const ProductFormat); 
private:
	std::string formatName;
};

#endif
