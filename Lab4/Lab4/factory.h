#pragma once
class Factory
{
public:
	Factory();
	~Factory();
};

class MediaFactory :
	public Factory
{
private:
	Media* mediaTemplates[];
public:
	MediaFactory();
	~MediaFactory();
	Media *createMedia(string,ifstream&);	//parses input to create movies
	Media *createMedia(const Movie& m);		//used in place of a copy constructor for Media
};

class CustomerFactory :
	public Factory
{
private:
	Customer* customerTemplates[];
public:
	CustomerFactory();
	~CustomerFactory();
};


