#include "productformatcollection.h"
/*
void ProductFormatCollection::FormatAmount::addQuantity(int quantity){
	size += quantity;
	count += quantity;	
}
*/
int ProductFormatCollection::getFormatAmount(const ProductFormat& pf) const{
	std::string searchName = pf.getName();
	for (std::list<FormatAmount>::const_iterator 
		it=formatDataList.begin(); 
		it != formatDataList.end(); ++it){
		if(it -> format -> getName() == searchName){
			return it -> count;
		}
	}
	return 0;
}
	
int ProductFormatCollection::getFormatMaxAmount(const ProductFormat& pf) const{
	std::string searchName = pf.getName();
	for (std::list<FormatAmount>::const_iterator 
		it=formatDataList.begin(); 
		it != formatDataList.end(); ++it){
		if(it -> format -> getName() == searchName){
			return it -> size;
		}
	}
	return 0;
}

bool ProductFormatCollection::addProductFormat(ProductFormat* pf){
	std::string searchName = pf -> getName();
	std::list<FormatAmount>::iterator it=formatDataList.begin();
	int currentQuantity = 0;
	while(it != formatDataList.end()){
		if(it -> format -> getName() == searchName){
			currentQuantity = it -> size;
			formatDataList.erase(it);
			break;
		}
		++it;
	} 

	FormatAmount inserted;
	inserted.size = inserted.count = currentQuantity + DEFAULT_PRODUCT_QUANTITY;
	inserted.format = pf;
	formatDataList.insert(it, inserted);
	return true;
}

const void ProductFormatCollection::display(std::ostream& output) const{	//display the amount of each format. NOTE: might be wrong way to do this

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