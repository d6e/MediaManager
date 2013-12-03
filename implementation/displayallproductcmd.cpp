#include "displayallproductcmd.h"

DisplayAllProductCMD::DisplayAllProductCMD(ProductCollection* products){  // default constructor
	mColl = products;
}
 
DisplayAllProductCMD::~DisplayAllProductCMD(){}           // default destructor

Command* DisplayAllProductCMD::create(ProductCollection* products, 
	CustomerIndex* customers){
	return new DisplayAllProductCMD(products);
}

// Returns false if data invalid, for factory use only.
bool DisplayAllProductCMD::setData(Event* e){
	return true;
} 

Error DisplayAllProductCMD::execute(){	//execute command from the IO 
	Error empty;
	std::cout << "Current inventory of all movies:" << std::endl;
	mColl -> displayAll();
	return empty;
}  