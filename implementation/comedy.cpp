#include "comedy.h"
/*
Comedy::Comedy(){
	//TODO: Inits productData keys.
}
*/

Comedy::~Comedy(){
	//TODO: check if this is necessary
}

Product* Comedy::create(){
	return new Comedy();
}

std::string Comedy::type() const{return "comedy";} //returns type ("comedy"). Used as key
void Comedy::display(){} // Displays contents via cout

const std::string* Comedy::dataTypeNames() const{return COMEDY_DATA_TYPES;}
const std::string* Comedy::sortedByNames() const{return COMEDY_SORTED_BY;}