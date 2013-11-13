#ifndef PRODUCTFORMATCOLLECTION_H
#define PRODUCTFORMATCOLLECTION_H
#define DEFAULT_PRODUCT_QUANTITY 10;
#include <string>
#include <list>

/*
Contains quantites and max quantites of various ProductFormats in a collection.
*/
class ProductFormatCollection{
public:
	ProductFormatCollection();
	int getFormatAmount(const ProductFormat*) const; //Returns the amount of items that particular ProductFormat has.
	int getFormatMaxAmount(const ProductFormat*) const;
	
	bool addProductFormat(ProductFormat);
private:
	struct FormatAmount
	{
		ProductFormat* format;
		int count = DEFAULT_PRODUCT_QUANTITY;
	    int size = DEFAULT_PRODUCT_QUANTITY;
	}
		
	std::list<FormatAmount> formatDataList;
};

#endif
