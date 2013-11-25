#include "product.h"

Product::Product(){}

Product::~Product(){}

void Product::display(){
	//string dataString = "";
	const string* tempTypeNames = dataTypeNames();
	const int tempTypeCount = dataTypeCount();
	for(int i = 0; i < tempTypeCount; i++){
		string dataType = tempTypeNames[i];
		map<string,string>::const_iterator index = productData.find(dataType);
   	 	string nextData = index -> second;	
   	 	normalizeLength(nextData);
   	 	
   	 	cout << nextData; //<< setw(MAX_DATA_LENGTH+4);
	}
	cout << endl;
}

void Product::normalizeLength(std::string& data){
	if(data.length() > MAX_DATA_LENGTH*1) truncate(data);	//the *1 is necessary to avoid a waring from the compiler
	else data.resize(MAX_DATA_LENGTH, ' ');
}

void Product::truncate(std::string& longString){
	longString.resize(MAX_DATA_LENGTH - 3);
	longString.resize(MAX_DATA_LENGTH, '.');
}

bool Product::operator==(const Product &p) const{
	return true; //TODO
}

bool Product::operator!=(const Product &p) const{
	return true; //TODO
}
bool Product::operator<(const Product &p) const{
	return true; //TODO
}

bool Product::operator>(const Product &p) const{
	return true; //TODO
}

bool Product::operator<=(const Product &p) const{
	return true; //TODO
}

bool Product::operator>=(const Product &p) const{
	return true; //TODO
}

bool Product::addData(std::string key,std::string value){
	productData.insert(pair<string,string>(key,value));
	return true;
	//TODO: make it possible for this to return false if they key is invalid.
}