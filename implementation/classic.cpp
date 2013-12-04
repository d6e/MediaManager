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

    delete e;
    return true; //TODO
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

char Classic::getKey() const{
    std::string name = getName();
    return name[0];
}

std::string Classic::getData(std::string key) const{
    std::map<std::string, std::string>::const_iterator it = productData.find(key);
    std::string retVal = "";
    if (it != productData.end()) {
        retVal = it->second;
    } 
    return retVal;
}

//TODO: comparison operators
// //comparison operators compare product by their sorting criteria
bool Classic::operator==(const NodeData &node) const{ //TODO:rewrite
    if(getName() != node.getName()){
        return false;  
    } 
    const Product& p = static_cast<const Product&>(node);
    std::vector<std::string> tempSortedByNames = getSortedBy();
    const int sortedBySize = p.getSortedBySize();//sizeof(tempSortedByNames)/sizeof(*tempSortedByNames);

    for(int i = 0; i < sortedBySize; i++){
        if(getData(tempSortedByNames[i]) != p.getData(tempSortedByNames.at(i))){
            return false;  
        } 
    }
    return true;
}

bool Classic::operator!=(const NodeData &node) const{
    return !(*this == node);
}

bool Classic::operator<(const NodeData &n) const{ //TODO:REWRITE
        if(getName() != n.getName()) return false;        //NOTE: should this always return false? should keys be compared for sorting, too?
        const Product& p = static_cast<const Product&>(n);
        std::vector<std::string> tempSortedByNames = getSortedBy();
        const int sortedBySize = p.getSortedBySize();
        for(int i = 0; i <= sortedBySize; i++){
                std::string nextSortBy = tempSortedByNames.at(i);
                if(getData(nextSortBy) < p.getData(nextSortBy)) return true;
                if(getData(nextSortBy) > p.getData(nextSortBy)) return false;
        }
    return false;
}

bool Classic::operator>(const NodeData &n) const{ //TODO:REWRITE
        if(getName() != n.getName()) return false;
        const Product& p = static_cast<const Product&>(n);
        std::vector<std::string> tempSortedByNames = getSortedBy();
        const int sortedBySize = p.getSortedBySize();
        for(int i = 0; i <= sortedBySize; i++){
                std::string nextSortBy = tempSortedByNames.at(i);
                if(getData(nextSortBy) > p.getData(nextSortBy)) return true;
                if(getData(nextSortBy) < p.getData(nextSortBy)) return false;
        }
    return false;
}

bool Classic::operator<=(const NodeData &node) const{
    return (*this < node) || (*this == node);//TODO: probably should be &&
}

bool Classic::operator>=(const NodeData &node) const{
    return (*this > node) || (*this == node); //TODO: probably should be &&
}

