#include "product.h"

Product::Product(){}

Product::~Product(){}

void Product::initValidFormats(){	
	int formatCount = validFormatCount(); 
	const std::string* formatNames = validFormatNames();
	for(int i = 0; i < formatCount; i++){	
		std::string format = formatNames[i];
		ProductFormat p(format);
		addValidFormat(p);
	}
	if(formatCount > 0){ //the default format is the first one.
		const std::string defaultFormat = formatNames[0];
		ProductFormat* pf = new ProductFormat(defaultFormat);
		addFormat(pf);
	}
}

void Product::display(std::ostream& output) const{
	//std::string dataString = "";
	const std::string* tempTypeNames = dataTypeNames();
	const int tempTypeCount = dataTypeCount();
	for(int i = 0; i < tempTypeCount; i++){
   	 	std::string nextData = getData(tempTypeNames[i]);
   	 	normalizeLength(nextData);
   	 	output << nextData;
	}
	output << "\n"; 
	inventory.display(output);
	//return output;
}

const std::string Product::getKey() const{
	return type(); //not sure this is correct yet
}

std::string Product::dataString() const{
	std::string dataString = "";
	/*
	const std::string* tempTypeNames = dataTypeNames();
	const int tempTypeCount = dataTypeCount();
	for(int i = 0; i < tempTypeCount; i++){
   	 	std::string nextData = getData(tempTypeNames[i]);
   	 	normalizeLength(nextData);
   	 	dataString += nextData;
	}
	dataString += "\n" + inventory.formatString();
	*/
	return dataString;
}

std::string Product::getData(const std::string key) const{

	map<string,string>::const_iterator index = productData.find(key);
   	const std::string data = index -> second;
	return data;
}

void Product::normalizeLength(std::string& data) const{
	if(data.length() > MAX_DATA_LENGTH*1) truncate(data);	//the *1 is necessary to avoid a waring from the compiler
	else data.resize(MAX_DATA_LENGTH, ' ');
}

void Product::truncate(std::string& longString) const{
	longString.resize(MAX_DATA_LENGTH - 3);
	longString.resize(MAX_DATA_LENGTH, '.');
}

void Product::duplicate(NodeData*){}  //TODO

//operator overrides

//------------------------- operator==,!= ------------------------------------

bool Product::operator==(const NodeData& n) const{
	if(getKey() != n.getKey()) return false;
	const Product& p = static_cast<const Product&>(n);
	const string* tempSortedByNames = sortedByNames();
	const int sortedByCount = p.sortedByCount();//sizeof(tempSortedByNames)/sizeof(*tempSortedByNames);
    for(int i = 0; i < sortedByCount; i++){
    	if(getData(tempSortedByNames[i]) != 
    		p.getData(tempSortedByNames[i])) return false;
    }
    return true;
}

bool Product::operator!=(const NodeData& n) const{
	return !(*this == n);
}

//------------------------ operator<,>,<=,>= ---------------------------------

bool Product::operator<(const NodeData& n) const{
	if(getKey() != n.getKey()) return false;	//NOTE: should this always return false? should keys be compared for sorting, too?
	const Product& p = static_cast<const Product&>(n);
	const string* tempSortedByNames = sortedByNames();
	const int sortedByCount = p.sortedByCount();
	for(int i = 0; i <= sortedByCount; i++){
		string nextSortBy = tempSortedByNames[i];
		if(getData(nextSortBy) < p.getData(nextSortBy)) return true;
		if(getData(nextSortBy) > p.getData(nextSortBy)) return false;
	}
    return false;
}

bool Product::operator>(const NodeData& n) const{
	if(getKey() != n.getKey()) return false;
	const Product& p = static_cast<const Product&>(n);
	const string* tempSortedByNames = sortedByNames();
	const int sortedByCount = p.sortedByCount();
	for(int i = 0; i <= sortedByCount; i++){
		string nextSortBy = tempSortedByNames[i];
		if(getData(nextSortBy) > p.getData(nextSortBy)) return true;
		if(getData(nextSortBy) < p.getData(nextSortBy)) return false;
	}
    return false;
}

bool Product::operator<=(const NodeData& n) const{
	return (*this < n) || (*this == n);
}

bool Product::operator>=(const NodeData& n) const{
	return (*this > n) || (*this == n);
}


bool Product::addData(std::string key,std::string value){
	productData.insert(pair<string,string>(key,value));
	return true;
	//TODO: make it possible for this to return false if they key is invalid.
}

bool Product::addFormat(ProductFormat* pf){
	//add 10 of this format to formatCollection. TODO: check if valid first
	inventory.addProductFormat(pf);
	return true;
}

bool Product::addValidFormat(ProductFormat pf){
	validFormats.insert(pair<string,ProductFormat>(pf.getName(),pf));
	return true; //TODO: make it possible to return false
}