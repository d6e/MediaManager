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
//void Comedy::display(){} // Displays contents via cout. (not sure if necessary)

const std::string* Comedy::dataTypeNames() const{return COMEDY_DATA_TYPES;}
const int Comedy::dataTypeCount() const{return sizeof(COMEDY_DATA_TYPES)/sizeof(*COMEDY_DATA_TYPES);}
const std::string* Comedy::sortedByNames() const{return COMEDY_SORTED_BY;}
const int Comedy::sortedByCount() const{return sizeof(COMEDY_SORTED_BY)/sizeof(*COMEDY_SORTED_BY);}