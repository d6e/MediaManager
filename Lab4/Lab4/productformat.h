#ifndef PRODUCTFORMAT_H
#define PRODUCTFORMAT_H
#include <string>

/*

*/

class ProductFormat {
public:
	ProductFormat(std::string);
	std::string getFormat();
private:
	std::string formatName;
};

#endif
