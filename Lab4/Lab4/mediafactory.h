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
    Media *createMedia(const Media& m); // used in place of a copy constructor for Media
};
