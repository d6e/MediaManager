#ifndef MEDIADATA_H
#define MEDIADATA_H
#include "nodedata.h"
#include "media.h"
#include <string>

/*
The MediaData class is a child of the NodeData class. It uses polymorphism
to override various functions and is stored in a bintree.

MediaData has a private Media pointer.

dataString() is an inherited method from NodeData, and calls the Media data's
<< operator.

The comparison operators are used to compare one MediaData object with another
by sorting criteria. To do so, they simply call the same operators on the
MediaData's respective data objects.

The duplictate() method is used to notify a NodeData object that a duplicate
data instance has been detected. It should call incrementQuantity() on data.

getKey() returns a unique identifier for the *class* (not the specific data) of
data. It does this by calling Media's dataType(). (for example, a comedy Movie
would return "moviecomedy" upon this call.) 
*/

class MediaData : public NodeData {
private:
   Media* data;
   virtual string dataString();   //calls its data's << operator          
public:
   MediaData();      // constructor
   ~MediaData();     // destructor
   MediaData(const Media *); // constructor for inserting Media 
   virtual MediaData* create(){return new MediaData();}
   void duplicate();  // signals media that quantity should be added.
   virtual string getKey(); // returns unique identifier 
   Media* getMedia();

   // comparison operators
   virtual bool operator==(const MediaData &) const;
   virtual bool operator!=(const MediaData &) const;
   virtual bool operator<(const MediaData &) const;
   virtual bool operator>(const MediaData &) const;
   virtual bool operator<=(const MediaData &) const;
   virtual bool operator>=(const MediaData &) const;
};

#endif