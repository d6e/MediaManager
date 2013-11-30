#include "productformatcollection.h"

ProductFormatCollection::FormatAmount::FormatAmount(){
	format = NULL;
	size = 0;
	count = 0;
}

ProductFormatCollection::ProductFormatCollection(){
	/*
	for (std::list<FormatAmount>::const_iterator 
	it=formatDataList.begin(); 
	it != formatDataList.end(); ++it){
		//formatDataList.insert(it, );
		//it = new FormatAmount();
	}	
	*/
}

int ProductFormatCollection::getFormatAmount(const ProductFormat* pf) const{
	//TODO: search list for this format, returing 0 if not found and format.count if it is.
	return 0;
}
	
int ProductFormatCollection::getFormatMaxAmount(const ProductFormat* pf) const{
	//TODO: search list for this format, returing 0 if not found and format.size if it is.
	return 0;
}

bool ProductFormatCollection::addProductFormat(ProductFormat* pf){
	//TODO: create and add a FormatAmount.	(how do we know whether it's valid? maybe should be void)
	FormatAmount inserted;
	inserted.size = inserted.count = DEFAULT_PRODUCT_QUANTITY;
	inserted.format = pf;
	formatDataList.push_back(inserted);
	return true;
}

const void ProductFormatCollection::display(std::ostream& output) const{	//display the amount of each format

	for (std::list<FormatAmount>::const_iterator 
		it=formatDataList.begin(); 
		it != formatDataList.end(); ++it){

		if(it -> size != 0){
			ProductFormat* nextFormat = (it -> format);
			output << nextFormat -> getName() << ": " << it -> count << " ";
		}
	}
	output << std::endl;
}