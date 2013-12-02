#include "comedy.h"
#include <iostream>

const std::string Comedy::dataTypeArr[] = {"director","title","date"};
const std::string Comedy::sortedByArr[] = {"title","date"};


// The constructor creates a bunch of ProductData objects and initializes their
// keys.
Comedy::Comedy(){
//TODO: find out if productdata objects should even be created.
    COMEDY_DATA_TYPES.push_back("director");
    COMEDY_DATA_TYPES.push_back("title");
    COMEDY_DATA_TYPES.push_back("date");

    COMEDY_SORTED_BY.push_back("title");
    COMEDY_SORTED_BY.push_back("date");
}

// cleans up any productdata objects it created
Comedy::~Comedy(){}

// The setData method takes in a pointer to an event object and the data it 
// contains to the event object's data. If the event object input is invalid,
// it returns false, otherwise true.  //TODO: rewrite description
bool Comedy::setData(Event* e){
    std::string eventToken;
    std::string eventDetails = e->getEventDetails();
    int dataTypeCounter = 0;
    //deliminating eventDetails string by comma
    for(int i = 1; i < eventDetails.size(); ++i){
        if(dataTypeCounter > COMEDY_DATA_TYPES.size()){            
            break;            
        }
        else if(eventDetails.at(i) == ','){
            //load into product's ht
            productData[COMEDY_DATA_TYPES.at(dataTypeCounter)] = eventToken;
            dataTypeCounter++;
            eventToken = "";
        }
        else{
            eventToken.push_back(eventDetails.at(i));//copy character to string
        }
    }
    // Need to get the last token after the comma
    productData[COMEDY_DATA_TYPES.at(dataTypeCounter)] = eventToken; 

    delete e;
    return true; //TODO
}

// create() is merely an instatiation method called by the ProductFactory that 
// creates a product object.
Product* Comedy::create(){
    return new Comedy();
}

// TODO: Not sure if this method is necessary
// The type method returns the type of the genre product object. For this one,
// it will return the string "comedy". This is used as a key for the hashtable.
std::string Comedy::type() const{
    return "Comedy";
}

// The dataTypeNames() and sortedByNames() are helper methods which quickly 
// retrieve the corresponding _DATA_TYPES and _SORTED_BY arrays. 
const std::string* Comedy::dataTypeNames() const{
    return dataTypeArr;
}

const std::string* Comedy::sortedByNames() const{
    return sortedByArr;
}

// returns size of DataTypes
int Comedy::getDataTypeSize() const{
    return COMEDY_DATA_TYPES.size();
}

// returns size of SortedBy
int Comedy::getSortedBySize() const{
    return COMEDY_SORTED_BY.size();
}


// returns unique identifier
std::string Comedy::getKey() const{
    return "Comedy";
}

std::string Comedy::getData(std::string key) const{
    std::map<std::string, std::string>::const_iterator it = productData.find(key);
    std::string retVal = "";
    if (it != productData.end()) {
        retVal = it->second;
    } 
    return retVal;
}

//TODO: comparison operators
// //comparison operators compare product by their sorting criteria
bool Comedy::operator==(const NodeData &node) const{ //TODO:rewrite
    if(getKey() != node.getKey()){
        return false;  
    } 
    const Product& p = static_cast<const Product&>(node);
    const std::string* tempSortedByNames = sortedByNames();
    const int sortedBySize = p.getSortedBySize();//sizeof(tempSortedByNames)/sizeof(*tempSortedByNames);

    for(int i = 0; i < sortedBySize; i++){
        if(getData(tempSortedByNames[i]) != p.getData(tempSortedByNames[i])){
            return false;  
        } 
    }
    return true;
}

bool Comedy::operator!=(const NodeData &node) const{
    return !(*this == node);
}

bool Comedy::operator<(const NodeData &n) const{ //TODO:REWRITE
        if(getKey() != n.getKey()) return false;        //NOTE: should this always return false? should keys be compared for sorting, too?
        const Product& p = static_cast<const Product&>(n);
        const std::string* tempSortedByNames = sortedByNames();
        const int sortedBySize = p.getSortedBySize();
        for(int i = 0; i <= sortedBySize; i++){
                std::string nextSortBy = tempSortedByNames[i];
                if(getData(nextSortBy) < p.getData(nextSortBy)) return true;
                if(getData(nextSortBy) > p.getData(nextSortBy)) return false;
        }
    return false;
}

bool Comedy::operator>(const NodeData &n) const{ //TODO:REWRITE
        if(getKey() != n.getKey()) return false;
        const Product& p = static_cast<const Product&>(n);
        const std::string* tempSortedByNames = sortedByNames();
        const int sortedBySize = p.getSortedBySize();
        for(int i = 0; i <= sortedBySize; i++){
                std::string nextSortBy = tempSortedByNames[i];
                if(getData(nextSortBy) > p.getData(nextSortBy)) return true;
                if(getData(nextSortBy) < p.getData(nextSortBy)) return false;
        }
    return false;
}

bool Comedy::operator<=(const NodeData &node) const{
    return (*this < node) || (*this == node);//TODO: probably should be &&
}

bool Comedy::operator>=(const NodeData &node) const{
    return (*this > node) || (*this == node); //TODO: probably should be &&
}

