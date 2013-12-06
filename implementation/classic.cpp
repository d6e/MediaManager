#include "classic.h"
#include <sstream>

// The constructor creates a bunch of ProductData objects and initializes their
// keys.
Classic::Classic(){
    CLASSIC_DATA_TYPES.push_back("DIRECTOR");
    CLASSIC_DATA_TYPES.push_back("TITLE");
    CLASSIC_DATA_TYPES.push_back("YEAR");
    CLASSIC_DATA_TYPES.push_back("MO");
    CLASSIC_DATA_TYPES.push_back("FAMOUS ACTOR");

    dataTypeReadOrder.push_back("DIRECTOR");
    dataTypeReadOrder.push_back("TITLE");
    dataTypeReadOrder.push_back("FAMOUS ACTOR");
    dataTypeReadOrder.push_back("MO");
    dataTypeReadOrder.push_back("YEAR");

    CLASSIC_SORTED_BY.push_back("YEAR");
    CLASSIC_SORTED_BY.push_back("FAMOUS ACTOR");
}

// cleans up any productdata objects it created
Classic::~Classic(){}

// The setData method takes in a pointer to an event object and the data it 
// contains to the event object's data. If the event object input is invalid,
// it returns false, otherwise true.
bool Classic::setData(Event* e){ //parses data 
    std::string eventToken;
    std::string eventDetails = e->getEventDetails();
    int dataTypeCounter = 0;
    //deliminating eventDetails string by comma
    for(int i = 2; i < eventDetails.size(); ++i){
        if(dataTypeCounter > dataTypeReadOrder.size()){            
            break;            
        }
        else if(eventDetails.at(i) == ','){
            i++; //skip space after comma
             //load into product's ht
            productData[dataTypeReadOrder.at(dataTypeCounter)] = eventToken;
            dataTypeCounter++;
            eventToken = "";
        }
        else{
            eventToken.push_back(eventDetails.at(i)); //copy character to string      
        }
    }
    //only the actor names and dates are left
    std::string actorFN, actorLN, month, year;
    std::stringstream ss;
    ss << eventToken;
    ss >> actorFN;    
    ss >> actorLN;    
    ss >> month;
    ss >> year;

    std::string actorName = actorFN + " " + actorLN;
    productData[dataTypeReadOrder.at(dataTypeCounter++)] = actorName;
    productData[dataTypeReadOrder.at(dataTypeCounter++)] = month;
    productData[dataTypeReadOrder.at(dataTypeCounter++)] = year;

    delete e; //We're done with the event obj
    return true;
}

// create() is merely an instatiation method called by the ProductFactory that 
// creates a product object.
Product* Classic::create(){
    return new Classic();
}


// The getDataTypes() and getSortedBy() are helper methods which quickly 
// retrieve the corresponding _DATA_TYPES and _SORTED_BY arrays. 
std::vector<std::string> Classic::getDataTypes() const{
    return CLASSIC_DATA_TYPES;
}

//Returns an array for the sortedBy order
std::vector<std::string> Classic::getSortedBy() const{
    return CLASSIC_SORTED_BY;
}

// returns size of DataTypes
int Classic::getDataTypeSize() const{
    return CLASSIC_DATA_TYPES.size();
}

// returns size of SortedBy
int Classic::getSortedBySize() const{
    return CLASSIC_SORTED_BY.size();
}

// returns unique identifier
std::string Classic::getName() const{
    return "Classic";
}

//Returns the char that corresponds to the product type
char Classic::getKey() const{
    std::string name = getName();
    return name[0];
}

//Accessor for the product's data
std::string Classic::getData(std::string key) const{
    std::map<std::string, std::string>::const_iterator it = productData.find(key);
    std::string retVal = "";
    if (it != productData.end()) {
        retVal = it->second;
    } 
    return retVal;
}

//comparison operators compare product by their sorting criteria
bool Classic::operator==(const NodeData &node) const{
    if(getName() != node.getName()){
        return false;  
    } 
    
    //convert node to a product
    const Product& pdt = static_cast<const Product&>(node);
    std::vector<std::string> sortByVect = getSortedBy();
    const int sortedBySize = pdt.getSortedBy().size();

    for(int i = 0; i < sortedBySize; i++){
        if(getData(sortByVect.at(i)) != pdt.getData(sortByVect.at(i))){
            return false;  
        } 
    }
    return true;
}

bool Classic::operator!=(const NodeData &node) const{
    if(*this == node){
        return true;
    }
    else{
        return false;
    }
}

bool Classic::operator<(const NodeData &node) const{ 
    if(getName() != node.getName()){
        return false;
    } 
    
    //convert node to a product
    const Product& pdt = static_cast<const Product&>(node);
    std::vector<std::string> sortByVect = getSortedBy();
    const int sortedBySize = pdt.getSortedBy().size();
    for(int i = 0; i <= sortedBySize; i++){
        std::string sortByStr = sortByVect.at(i);
        if(getData(sortByStr) < pdt.getData(sortByStr)){
            return true;
        }
        if(getData(sortByStr) > pdt.getData(sortByStr)){
            return false;
        }
    }
    return false;
}

bool Classic::operator>(const NodeData &node) const{
    if(getName() != node.getName()){
        return false;
    }

    //convert node to a product
    const Product& pdt = static_cast<const Product&>(node);
    std::vector<std::string> sortByVect = getSortedBy();
    const int sortedBySize = pdt.getSortedBy().size();
    for(int i = 0; i <= sortedBySize; i++){
        std::string sortByStr = sortByVect.at(i);
        if(getData(sortByStr) > pdt.getData(sortByStr)){
            return true;
        }
        if(getData(sortByStr) < pdt.getData(sortByStr)){
            return false;
        }
    }
    return false;
}

bool Classic::operator<=(const NodeData &node) const{
    bool ret = false;
    ret = (*this < node); 
    ret = (*this == node);
    return ret;
}

bool Classic::operator>=(const NodeData &node) const{
    bool ret = false;
    ret = (*this < node); 
    ret = (*this == node);
    return ret;
}

