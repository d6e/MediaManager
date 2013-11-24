#include "movie.h"

void Movie::initValidFormats(){}
/*
#include <iostream>
using namespace std;

Movie::Movie(){}

Movie::~Movie(){}

string Movie::genre() const{
	return "none";
}

string Movie::movieDataString() const{
	string dataString = "";
	const string* tempTypeNames = dataTypeNames();
	const int tempTypeCount = dataTypeCount();
	for(int i = 0; i < tempTypeCount; i++){
		string dataType = tempTypeNames[i];
		dataString += dataType +": ";
		map<string,string>::const_iterator index = movieData.find(dataType);
   	 	string value = index -> second;	
   	 	dataString += value;
   	 	dataString += "\n";
	}
	return dataString;
}

void Movie::addData(string key, string value){	//TODO: value should not have its class defined yet. (maybe?)
	movieData.insert(pair<string,string>(key,value));
}

string Movie::getData(string dataType) const{	
	map<string,string>::const_iterator index = movieData.find(dataType);
	return index -> second;	
}

ostream& operator<<(ostream& output, const Movie& m) {
    output << m.movieDataString();
    return output;
}

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


//classic movie
string ClassicMovie::genre() const{
	return "classic";	//TODO: store this better
}

const string* ClassicMovie::dataTypeNames() const{return CLASSIC_MOVIE_DATA_TYPES;}
const string* ClassicMovie::sortedByNames() const{return CLASSIC_SORTED_BY;}
int ClassicMovie::dataTypeCount() const {return sizeof(CLASSIC_MOVIE_DATA_TYPES)/sizeof(*CLASSIC_MOVIE_DATA_TYPES);};	//TODO: make data type count one method for all movies, and call dataTypeNames()

//drama movie
string DramaMovie::genre() const {
	return "drama";	//TODO: store this better
}

const string* DramaMovie::dataTypeNames () const{return DRAMA_MOVIE_DATA_TYPES;}
const string* DramaMovie::sortedByNames() const{return DRAMA_SORTED_BY;}
int DramaMovie::dataTypeCount() const {return sizeof(DRAMA_MOVIE_DATA_TYPES)/sizeof(*DRAMA_MOVIE_DATA_TYPES);};

//comedy movie
string ComedyMovie::genre() const{
	return "comedy";	//TODO: store this better
}

const string* ComedyMovie::dataTypeNames() const {return COMEDY_MOVIE_DATA_TYPES;}
const string* ComedyMovie::sortedByNames() const{return COMEDY_SORTED_BY;}
int ComedyMovie::dataTypeCount() const {return sizeof(COMEDY_MOVIE_DATA_TYPES)/sizeof(*COMEDY_MOVIE_DATA_TYPES);};
*/