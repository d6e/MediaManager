#include "drama.h"

// The constructor creates a bunch of ProductData objects and initializes their
// keys.
Drama::Drama(){
//TODO: find out if productdata objects should even be created.
    DRAMA_DATA_TYPES.push_back("director");
    DRAMA_DATA_TYPES.push_back("title");
    DRAMA_DATA_TYPES.push_back("date");

    DRAMA_SORTED_BY.push_back("director");
    DRAMA_SORTED_BY.push_back("title");
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
    for(int i = 1; i < eventDetails.size(); ++i){
        if(dataTypeCounter > DRAMA_DATA_TYPES.size()){            
            break;            
        }
        else if(eventDetails.at(i) == ','){
             //load into product's ht
            productData[DRAMA_DATA_TYPES.at(dataTypeCounter)] = eventToken;
            dataTypeCounter++;
            eventToken = "";
        }
        else{
            eventToken.push_back(eventDetails.at(i));//copy character to string
        }
    }
    // Need to get the last token after the comma
    productData[DRAMA_DATA_TYPES.at(dataTypeCounter)] = eventToken; 

    delete e;
    return true; //TODO
}

// create() is merely an instatiation method called by the ProductFactory that 
// creates a product object.
Product* Drama::create(){
    return new Drama();
}

// TODO: Not sure if this method is necessary
// The type method returns the type of the genre product object. For this one,
// it will return the string "drama". This is used as a key for the hashtable.
std::string Drama::type() const{
    return "Drama";
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

char Drama::getKey() const{
    std::string name = getName();
    return name[0];
}

std::string Drama::getData(std::string key) const{
    std::map<std::string, std::string>::const_iterator it = productData.find(key);
    std::string retVal = "";
    if (it != productData.end()) {
        retVal = it->second;
    } 
    return retVal;
}

//TODO: comparison operators
// //comparison operators compare product by their sorting criteria
bool Drama::operator==(const NodeData &node) const{ //TODO:rewrite
    if(getName() != node.getName()){
        return false;  
    } 
    const Product& p = static_cast<const Product&>(node);
    std::vector<std::string> tempSortedByNames = getSortedBy();
    const int sortedBySize = p.getSortedBySize();//sizeof(tempSortedByNames)/sizeof(*tempSortedByNames);

    for(int i = 0; i < sortedBySize; i++){
        if(getData(tempSortedByNames.at(i)) != p.getData(tempSortedByNames.at(i))){
            return false;  
        } 
    }
    return true;
}

bool Drama::operator!=(const NodeData &node) const{
    return !(*this == node);
}

bool Drama::operator<(const NodeData &n) const{ //TODO:REWRITE
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

bool Drama::operator>(const NodeData &n) const{ //TODO:REWRITE
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

bool Drama::operator<=(const NodeData &node) const{
    return (*this < node) || (*this == node);//TODO: probably should be &&
}

bool Drama::operator>=(const NodeData &node) const{
    return (*this > node) || (*this == node); //TODO: probably should be &&
}