#include "classic.h"

Classic::~Classic(){
	//TODO: check if this is necessary
}

Product* Classic::create(){
	return new Classic();
}

std::string Classic::type() const{return "classic";} //returns type ("classic"). Used as key
void Classic::display(){} // Displays contents via cout

const std::string* Classic::dataTypeNames() const{return CLASSIC_DATA_TYPES;}
const int Classic::dataTypeCount() const{return sizeof(CLASSIC_DATA_TYPES)/sizeof(*CLASSIC_DATA_TYPES);}
const std::string* Classic::sortedByNames() const{return CLASSIC_SORTED_BY;}
const int Classic::sortedByCount() const{return sizeof(CLASSIC_SORTED_BY)/sizeof(*CLASSIC_SORTED_BY);}