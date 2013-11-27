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

bool Product::operator==(const NodeData& n) const{
	//cout << n.dataString() << endl;
	if(getKey() != n.getKey()) return false;
	const Product& p = static_cast<const Product&>(n);

	const string* tempTypeNames = sortedByNames();
	const int tempTypeCount = sortedByCount();
    for(int i = 0; i < tempTypeCount; i++){
    	//cout << getData(tempTypeNames[i]) << ", " 
    	//	<< p.getData(tempTypeNames[i]) << endl;
    	if(getData(tempTypeNames[i]) != 
    		p.getData(tempTypeNames[i])) return false;
    }
	
    return true;
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
/*
//operator overrides

//------------------------- operator==,!= ------------------------------------
bool Movie::operator==(const Movie& otherMovie) const {
	if(genre() != otherMovie.genre()) return false;
	const string* tempTypeNames = sortedByNames();
	const int tempTypeCount = dataTypeCount();
    for(int i = 0; i < tempTypeCount; i++){
    	if(getData(tempTypeNames[i]) != 
    		otherMovie.getData(tempTypeNames[i])) return false;
    }
    return true;
}

bool Movie::operator!=(const Movie& otherMovie) const {
   return !(*this == otherMovie);
}

//------------------------ operator<,>,<=,>= ---------------------------------
bool Movie::operator<(const Movie& otherMovie) const {
	const string* tempSortedByNames = sortedByNames();
	int sortedByCount = sizeof(tempSortedByNames)/sizeof(*tempSortedByNames);
	for(int i = 0; i <= sortedByCount; i++){
		string nextSortBy = tempSortedByNames[i];
		if(getData(nextSortBy) < otherMovie.getData(nextSortBy)) return true;
		if(getData(nextSortBy) > otherMovie.getData(nextSortBy)) return false;
	}
    return false;
}

bool Movie::operator>(const Movie& otherMovie) const {
   const string* tempSortedByNames = sortedByNames();
	int sortedByCount = sizeof(tempSortedByNames)/sizeof(*tempSortedByNames);
	for(int i = 0; i < sortedByCount; i++){
		string nextSortBy = tempSortedByNames[i];
		if(getData(nextSortBy) > otherMovie.getData(nextSortBy)) return true;
		if(getData(nextSortBy) < otherMovie.getData(nextSortBy)) return false;
	}
    return false;
}

bool Movie::operator<=(const Movie& otherMovie) const {
   return (*this < otherMovie) || (*this == otherMovie);
}

bool Movie::operator>=(const Movie& otherMovie) const {
   return (*this > otherMovie) || (*this == otherMovie);
}
*/

bool Product::addData(std::string key,std::string value){
	productData.insert(pair<string,string>(key,value));
	return true;
	//TODO: make it possible for this to return false if they key is invalid.
}