#ifndef MEDIAFACTORY_H
#define MEDIAFACTORY_H
#include "media.h"
#include <string>

class MediaFactory
{
public:
    MediaFactory();    //fills mediatemplates with instances of each instantiatable Media object
    ~MediaFactory();
    Media *createMedia(std::string arg); //parses input to create Media objects
private:
	const std::string[] GENRE_CODES = {"F","C","D"};
	const std::string[] MEDIUM_CODES = {"D"};
	const int GENRE_AMOUNT = 3; 	
	
	bool createComedy(Media*&, std::string); // mItem doesn't point to anything unless return true
	bool createDrama(Media*&, std::string); // mItem doesn't point to anything unless return true
	bool createClassic(Media*&, std::string); // mItem doesn't point to anything unless return true
	
	
};
