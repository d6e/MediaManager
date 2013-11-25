#include "drama.h"
/*
Drama::Drama(){
	//TODO: Inits productData keys.
}
*/

Drama::~Drama(){
	//TODO: check if this is necessary
}

Product* Drama::create(){
	return new Drama();
}

std::string Drama::type() const{return "drama";} //returns type ("comedy"). Used as key
void Drama::display(){} // Displays contents via cout

const std::string* Drama::dataTypeNames() const{return DRAMA_DATA_TYPES;}
const int Drama::dataTypeCount() const{return sizeof(DRAMA_DATA_TYPES)/sizeof(*DRAMA_DATA_TYPES);}
const std::string* Drama::sortedByNames() const{return DRAMA_SORTED_BY;}