#ifndef MEDIADATA_H
#define MEDIADATA_H
#include "nodedata.h"
#include "media.h"
#include <string>

class MediaData : public NodeData {
private:
   Media* data;          
public:
   virtual MediaData();      // constructor
   virtual ~MediaData();     // destructor
   MediaData(const Media *); // constructor for inserting Media
   string dataType() const;  // returns unique identifier    
   void duplicate();  // signals overridden functions to handle its quantity
   virtual Error getKey(); //

   // comparison operators
   virtual bool operator==(const MediaData &) const;
   virtual bool operator!=(const MediaData &) const;
   virtual bool operator<(const MediaData &) const;
   virtual bool operator>(const MediaData &) const;
   virtual bool operator<=(const MediaData &) const;
   virtual bool operator>=(const MediaData &) const;
};

#endif