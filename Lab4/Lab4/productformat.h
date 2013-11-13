#ifndef PRODUCTFORMAT_H
#define PRODUCTFORMAT_H
#include <string>

/*
Specifies a product's format. For a movie, this could be a DVD or Blueray.
*/
class ProductFormat {
public:
	ProductFormat(std::string);
	std::string getName();
	bool equals(const ProductFormat); //Checks if two ProductFormats are equivilent
private:
	std::string formatName;
};

#endif
