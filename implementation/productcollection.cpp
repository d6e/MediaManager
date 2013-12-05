#include "productcollection.h"
#include "productfactory.h"

ProductCollection::ProductCollection(){} 

ProductCollection::~ProductCollection(){} 

Error ProductCollection::insert(Product* p, std::string genre){
	Error empty;
	int genreIndex = (int) genre[0] - A_INDEX;
	if(collectTree[genreIndex].insert(p)) return empty;
	Error notFound("ERROR: failed to insert the product.");	//TODO: this might not actually be what "false" means in this context.
	return notFound;
}

Error ProductCollection::retrieve(Product* p, std::string genre){
	Error empty;
	int genreIndex = (int) genre[0] - A_INDEX;
	if(collectTree[genreIndex].retrieve(p)) return empty;
	Error notFound("ERROR: product was not found.");	//TODO: this might not actually be what "false" means in this context.
	return notFound;
}

Error ProductCollection::displayAll() const{
	Error empty;
	int collectionSize = sizeof(collectTree)/sizeof(*collectTree);

	for(int i = 0; i < collectionSize; i++){
		if(!collectTree[i].isEmpty()){
			std::cout << collectTree[i].getKey() << " movies:" << std::endl;
			std::cout << std::endl <<  "*IN* *OUT*" << std::endl
				 << "DVD  DVD ";
			empty = displayDataTypes(collectTree[i]); //should this be an error?
			std::cout << std::endl;
			if(empty.getErrorMessage() != "") return empty;
			std::cout << collectTree[i] << std::endl;
		} 
	}
	return empty;	
}



Error ProductCollection::displayDataTypes(const BinTree& dataTree) const{
	Error empty;
	const std::string* dataTypes = dataTree.dataTypeNames();
	int dataTypeCount = dataTree.dataTypeCount();
	for(int i = 0; i < dataTypeCount; i++){
		std::string nextType = dataTypes[i];
		if(nextType == DATE){
			nextType = "year mo";
		}
		nextType.resize(MAX_DATA_LENGTH,' ');
		std::cout << nextType;
	}
	return empty;
}

Error ProductCollection::makeTransaction(Event* event){
	if(event -> getToken(2) != "D"){	//if there were other format types besides DVD, this would be done differently
    	return Error("Cannot find movie: invalid format type.");
    }
    return productSearch(event);
}

Error ProductCollection::productSearch(Event* event){
	std::string data = event -> productData();
	istringstream ss(data);
	ProductFactory* mFactory = new ProductFactory();
	std::string genre;
	ss >> genre;
	Product* p = mFactory -> create(genre);
	if(p == NULL){
    	return Error("Cannot find movie: no movies of that genre.");
    }
    const std::string* sortedByNames = p -> sortedByNames();
    //IDEA: use sorted by count instead of  this method
    ss.get();
	std::string dataToken;
	int dataIndex = 0;
	while(std::getline(ss, dataToken, ',')) {
		ss.get();
		if(*dataToken.rbegin() == ' '){
			dataToken = dataToken.substr(0, dataToken.size()-1);
		}
		p -> addData(sortedByNames[dataIndex],dataToken);
		dataIndex++;
	}

   	Error e = retrieve(p,genre); 
   	if(e.getErrorMessage() == ""){
   		int genreIndex = (int) genre[0] - A_INDEX;
   		std::string transactionType = event -> getToken(0);
   		NodeData* n = collectTree[genreIndex].pullData(p,transactionType);
   		Product* product = static_cast<Product*>(n);
   		event -> setProduct(product);
	}
	return e;
}

bool ProductCollection::validGenre(std::string genre) const{
	int genreIndex = (int) genre[0] - A_INDEX;
	return !collectTree[genreIndex].isEmpty();
}