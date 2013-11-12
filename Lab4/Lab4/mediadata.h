#include "nodedata.h"

class MediaData:NodeData {
public:
   virtual MediaData();
   virtual ~MediaData();
   MediaData(const Media *);
   string dataType() const;
   void duplicate();

   virtual bool operator==(const MediaData &) const;
   virtual bool operator!=(const MediaData &) const;
   virtual bool operator<(const MediaData &) const;
   virtual bool operator>(const MediaData &) const;
   virtual bool operator<=(const MediaData &) const;
   virtual bool operator>=(const MediaData &) const;
private:
   Media* data;          
};