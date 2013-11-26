
#include "nodedata.h"

//------------------- constructors/destructor  -------------------------------
NodeData::NodeData() {}                         // default

NodeData::~NodeData() {}            // needed so strings are deleted properly

NodeData::NodeData(const NodeData& nd) { // copy. TODO (i think)
   //count = nd.count;
   //data = nd.data; 
} 

ostream& operator<<(ostream& output, const NodeData& n){
   //TODO
   output << n.dataString() << endl;
   return output;
}

//------------------------- operator= ----------------------------------------
NodeData& NodeData::operator=(const NodeData& rhs) {
   //TODO
   return *this;
}


//------------------------------ setData -------------------------------------
// returns true if the data is set, false when bad data, i.e., is eof

//TODO: write a new setdata
/*
bool NodeData::setData(istream& infile) { 
   getline(infile, data);
   return !infile.eof();       // eof function is true when eof char is read
}
*/
/*
//-------------------------- operator<< --------------------------------------
ostream& operator<<(ostream& output, const NodeData& nd) {
   output << "in stock: " << nd.count << endl;
   output << *(nd.data);   //TODO: change how this is done.
   return output;
}

string NodeData::genre(){
   if(data == NULL) return "";
   return data -> genre();
}

void NodeData::incrementCount(int added){
   count += added;
}
*/