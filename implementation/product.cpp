#include "product.h"

Product::Product(){}

Product::~Product(){}

std::string Product::getKey() const{
	return type(); //not sure this is correct yet
}

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

void Product::normalizeLength(std::string& data) const{
	if(data.length() > MAX_DATA_LENGTH*1) truncate(data);	//the *1 is necessary to avoid a waring from the compiler
	else data.resize(MAX_DATA_LENGTH, ' ');
}

void Product::truncate(std::string& longString) const{
	longString.resize(MAX_DATA_LENGTH - 3);
	longString.resize(MAX_DATA_LENGTH, '.');
}

void Product::duplicate(NodeData*){}  //TODO

bool Product::operator==(const NodeData& n) const{
	return true; //TODO
}

bool Product::operator!=(const NodeData& n) const{
	return true; //TODO
}
bool Product::operator<(const NodeData& n) const{
	return true; //TODO
}

bool Product::operator>(const NodeData& n) const{
	return true; //TODO
}

bool Product::operator<=(const NodeData& n) const{
	return true; //TODO
}

bool Product::operator>=(const NodeData& n) const{
	return true; //TODO
}

bool Product::addData(std::string key,std::string value){
	productData.insert(pair<string,string>(key,value));
	return true;
	//TODO: make it possible for this to return false if they key is invalid.
}