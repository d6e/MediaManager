#ifndef MEDIA_H
#define MEDIA_H
#define DEFAULT_MEDIA_QUANTITY 10;
#include <map>
#include <string>
#include <iostream>
using namespace std;

/*
Media class

A media object is a movie, a book, a music album, or some other form of media.
At its most basic level, a Media has the ability to say which of this types it
is and/or what genre it is, store and output its data (which might include 
title, publication date, composer, sculptor, set designer, etc), and compare 
itself to other Media objects of the same type and genre. 

Each media object stores its format (DVD, blu-ray, book on tape, grain of rice,
etc) in a MediaFormat object, and all of its other data in a hashTable called
mediaData. The object is stored and sorted by  some (but not all) of this data, 
as defined in the string arrays in each specific media type. (example: 
CLASSIC_MOVIE_SORTED BY.) The order of the corresponding string array determines 
the prority of each data type for sorting. (For instance, classic movies are 
sorted first by date, then by famous actor.)

The full arrays of data types (any string arrays ending in "_DATA_TYPES") 
represent all data for a type of Media object, regardless of sorting, in the
order the mediafactory creating the Media reads these data members. (They are 
outputted in the same order.)

The mediaType() string is a pure virtual method which is overridden for each
direct subclass of Media. (Movie returns "movie", Music returns "music", etc.)
The genre() string works similarly, but is overridden only by instantiable
types like ComedyMovie (which would return "comedy"). dataType() concatenates
these two strings to create a unique idenifier for an instantiable media type,
aiding in sorting.

dataTypeNames() and sortedByNames() are helper metods which quickly retrieve the
corresponding _DATA_TYPES and _SORTED_BY arrays. 

dataString() outputs the Media object's format, along with all of its data in 
order of its dataTypeNames(). The dataString() method is called as part of a 
media BinTree's display method. This is the only method called by the <<
operator.

create() is merely an instatiation method called by the MediaFactory that 
creates a media object.

The addData() method inserts data into the Media's hashtable, with the form
<dataType,data> (Example: <"title","Titanic">). This data is retrieved in a
similar way by dataString().

All of any Media object's comparison operators work under the same principles:
Media objects are compared, in order, by their sorting criteria, ignoring any 
data found in _DATA_TYPES but not in _SORTED_BY. (format is always ignored.)
By this defintion, no "equal" Media objects are stored as separate objects. 
Instead, the quantity of an existing Media object is increased if an equal 
object is inserted.

Each media inserted into a MediaCollection counts as 10 identical Media objects,
in terms of both count and size variables. Whenever an identical Media is 
inserted, incrementQuantity() is called and increases each value by another 10.
"count" refers to the number of available copies of the media, while size refers
to the total number of copies that the store owns (i.e., all copies including
those borrowed.) borrowedCopies() subtracts count from size to determine how
many copies of a media have been borrowed.
*/

//most generic Media type
class Media {
	friend ostream & operator<<(ostream &, const Movie &);
public:
	Media();
	virtual ~Media();
	virtual string getFormat() const = 0; //allows the media to say whether it is a movie, music album, book, etc
	virtual string genre() const = 0;	//returns the work's genre. Overridden for each specific media type/genre combination.
	virtual const string* dataTypeNames() const = 0; // Returns all data, inorder of input, deliminated by commas
	virtual const string* sortedByNames() const = 0; // Returns the sorting data, deliminated by commas
	virtual void display(); // Displays contents via cout
	
	//comparison operators compare media by their sorting criteria
	virtual bool operator==(const Media &) const;
    virtual bool operator!=(const Media &) const;
    virtual bool operator<(const Media &) const;
    virtual bool operator>(const Media &) const;
    virtual bool operator<=(const Media &) const;
    virtual bool operator>=(const Media &) const;
	
    void incrementQuantity();		//increments count and size by DEFAULT_MEDIA_QUANTITY
    int getBorrowedItems() const; 			//number of copies borrowed by customers
	int getRemainingItems() const; 			//number of copies borrowed by customers
private:
	MediaFormat format;	
	map<string,string> mediaData;
	int count = DEFAULT_MEDIA_QUANTITY;
	int size = DEFAULT_MEDIA_QUANTITY;
	void addData(string,string);
	void setFormat(string);
};

#endif