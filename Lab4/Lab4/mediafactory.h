#ifndef MEDIAFACTORY_H
#define MEDIAFACTORY_H
#include "media.h"
#include <string>

class MediaFactory
{
public:
    MediaFactory();    //fills mediatemplates with instances of each instantiatable Media object
    ~MediaFactory();
    Media *createMedia(string arg); //parses input to create Media objects
private:
	const string[] GENRE_CODES = {"F","C","D"};
	const string[] MEDIUM_CODES = {"D"};
	const int GENRE_AMOUNT = 3; 	
	
	bool createComedy(Media*& mItem, String arg); // mItem doesn't point to anything unless return true;
	bool createDrama(Media*& mItem, String arg); // mItem doesn't point to anything unless return true;
	bool createClassicMedia*& mItem, String arg); // mItem doesn't point to anything unless return true;
	
	
};
