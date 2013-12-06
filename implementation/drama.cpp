#include "drama.h"

// The constructor creates a bunch of ProductData objects and initializes their
// keys.
Drama::Drama(){
    DRAMA_DATA_TYPES.push_back("DIRECTOR");
    DRAMA_DATA_TYPES.push_back("TITLE");
    DRAMA_DATA_TYPES.push_back("YEAR");

    dataTypeReadOrder.push_back("DIRECTOR");
    dataTypeReadOrder.push_back("TITLE");
    dataTypeReadOrder.push_back("YEAR");

    DRAMA_SORTED_BY.push_back("DIRECTOR");
    DRAMA_SORTED_BY.push_back("TITLE");
}

// cleans up any productdata objects it created
Drama::~Drama(){}

// The setData method takes in a pointer to an event object and the data it 
// contains to the event object's data. If the event object input is invalid,
// it returns false, otherwise true.
bool Drama::setData(Event* e){
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
            eventToken.push_back(eventDetails.at(i));//copy character to string
        }
    }
    // Need to get the last token after the comma
    productData[dataTypeReadOrder.at(dataTypeCounter)] = eventToken; 

    delete e;
    return true; 
}

// create() is merely an instatiation method called by the ProductFactory that 
// creates a product object.
Product* Drama::create(){
    return new Drama();
}

// The getDataTypes() and getSortedBy() are helper methods which quickly 
// retrieve the corresponding _DATA_TYPES and _SORTED_BY arrays. 
std::vector<std::string> Drama::getDataTypes() const{
    return DRAMA_DATA_TYPES;
}

std::vector<std::string> Drama::getSortedBy() const{
    return DRAMA_SORTED_BY;
}

// returns size of DataTypes
int Drama::getDataTypeSize() const{
    return DRAMA_DATA_TYPES.size();
}

// returns size of SortedBy
int Drama::getSortedBySize() const{
    return DRAMA_SORTED_BY.size();
}

// returns unique identifier
std::string Drama::getName() const{
    return "Drama";
}

// Returns the char that corresponds to the drama. Used as a key in maps
char Drama::getKey() const{
    std::string name = getName();
    return name[0];
}

// accessor for productData map
std::string Drama::getData(std::string key) const{
    std::map<std::string, std::string>::const_iterator it;
    it = productData.find(key);
    std::string retVal = "";
    if (it != productData.end()) {
        retVal = it->second;
    } 
    return retVal;
}


//comparison operators compare product by their sorting criteria
bool Drama::operator==(const NodeData &node) const{
    if(getName() != node.getName()){
        return false;  
    } 
    
    //cast to convert node to a product
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

bool Drama::operator!=(const NodeData &node) const{
    if(*this == node){
        return true;
    }
    else{
        return false;
    }
}

bool Drama::operator<(const NodeData &node) const{ 
    if(getName() != node.getName()){
        return false;
    } 
    
    //cast to convert node to a product
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

bool Drama::operator>(const NodeData &node) const{
    if(getName() != node.getName()){
        return false;
    }

    //cast to convert node to a product
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

bool Drama::operator<=(const NodeData &node) const{
    bool ret = false;
    ret = (*this < node); 
    ret = (*this == node);
    return ret;
}

bool Drama::operator>=(const NodeData &node) const{
    bool ret = false;
    ret = (*this < node); 
    ret = (*this == node);
    return ret;
}

