#include "nodedata.h"

NodeData::NodeData(){}

NodeData::~NodeData(){}

std::ostream& operator<<(std::ostream& out, const NodeData& node){
   node.display(out);
   return out;
}

//------------------------- operator= ----------------------------------------
NodeData& NodeData::operator=(const NodeData& rhs) {
   return *this;
}
