#include "productfactory.h"


class MediaFactory
{
private:
	Media* mediaTemplates[];
public:
	MediaFactory();
	~MediaFactory();
	Media *createMedia(string,ifstream&);	//parses input to create movies
	Media *createMedia(const Movie& m);		//used in place of a copy constructor for Media
};