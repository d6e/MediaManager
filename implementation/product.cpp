#include "product.h"

Product::Product(){}

Product::~Product(){}

std::string Product::getKey() const{
	return type(); //not sure this is correct yet
}

std::string Product::dataString() const{
	std::string dataString = "";
	const std::string* tempTypeNames = dataTypeNames();
	const int tempTypeCount = dataTypeCount();
	for(int i = 0; i < tempTypeCount; i++){
   	 	std::string nextData = getData(tempTypeNames[i]);
   	 	normalizeLength(nextData);
   	 	dataString += nextData;
	}
	return dataString;
}

std::string Product::getData(const std::string key) const{	
	map<string,string>::const_iterator index = productData.find(key);
   	const std::string data = index -> second;
	return data;
}
/*
void Product::display() const{
	const string* tempTypeNames = dataTypeNames();
	const int tempTypeCount = dataTypeCount();
	for(int i = 0; i < tempTypeCount; i++){
		string dataType = tempTypeNames[i];
		map<string,string>::const_iterator index = productData.find(dataType);
   	 	string nextData = index -> second;	
   	 	normalizeLength(nextData);
   	 	cout << nextData;
	}
	cout << endl;
}
*/
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
	return !(*this == n); //TODO
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