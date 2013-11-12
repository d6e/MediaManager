#ifndef MEDIADATA_H
#define MEDIADATA_H
#include "nodedata.h"
#include "media.h"
#include <string>

class MediaData : public NodeData {
private:
   Media* data;
   virtual string dataString();   //calls its data's << operator          
public:
   virtual MediaData();      // constructor
   virtual ~MediaData();     // destructor
   MediaData(const Media *); // constructor for inserting Media 
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