#ifndef MEDIAFACTORY_H
#define MEDIAFACTORY_H
#include "factory.h"
#include "media.h"
#include <string>

class MediaFactory : public Factory {
public:
	MediaFactory(void);
	~MediaFactory(void);
    Media* createMedia(String);
};

#endif