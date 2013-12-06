#include "nodedata.h"

NodeData::NodeData(){}

NodeData::~NodeData(){}

//Overloaded << operator
std::ostream& operator<<(std::ostream& out, const NodeData& node){
   node.display(out);
   return out;
}

//------------------------- operator= ----------------------------------------
NodeData& NodeData::operator=(const NodeData& rhs) {
   return *this;
}
