#include "nodedata.h"

NodeData::NodeData(){}

NodeData::~NodeData(){}

ostream& operator<<(ostream& out, const NodeData& node){
   node.display(out);
   return out;
}

//------------------------- operator= ----------------------------------------
NodeData& NodeData::operator=(const NodeData& rhs) {
   return *this;
}
