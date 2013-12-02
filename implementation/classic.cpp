#include "classic.h"

// The constructor creates a bunch of ProductData objects and initializes their
// keys.
Classic::Classic(){
//TODO: find out if productdata objects should even be created.
    CLASSIC_DATA_TYPES.push_back("director");
    CLASSIC_DATA_TYPES.push_back("title");
    CLASSIC_DATA_TYPES.push_back("famous actor");
    CLASSIC_DATA_TYPES.push_back("date");

    CLASSIC_SORTED_BY.push_back("date");
    CLASSIC_SORTED_BY.push_back("famous actor");
}

// cleans up any productdata objects it created
Classic::~Classic(){}

// The setData method takes in a pointer to an event object and the data it 
// contains to the event object's data. If the event object input is invalid,
// it returns false, otherwise true.
bool Classic::setData(Event* e){
    std::string eventToken;
    std::string eventDetails = e->getEventDetails();
    int dataTypeCounter = 0;
    //deliminating eventDetails string by comma
    for(int i = 1; i < eventDetails.size(); ++i){
        if(dataTypeCounter > CLASSIC_DATA_TYPES.size()){            
            break;            
        }
        else if(eventDetails.at(i) == ','){
             //load into product's ht
            productData[CLASSIC_DATA_TYPES.at(dataTypeCounter)] = eventToken;
            dataTypeCounter++;
            eventToken = "";
        }
        else{
            eventToken.push_back(eventDetails.at(i));        
        }
    }
    // Need to get the last token after the comma
    productData[CLASSIC_DATA_TYPES.at(dataTypeCounter)] = eventToken; 

    delete e;
    return true; //TODO
}

// create() is merely an instatiation method called by the ProductFactory that 
// creates a product object.
Product* Classic::create(){
    return new Classic();
}

// TODO: Not sure if this method is necessary
// The type method returns the type of the genre product object. For this one,
// it will return the string "classic". This is used as a key for the hashtable.
std::string Classic::type() const{
    return "Classic";
}

// The display method displays the private data members using cout.
void Classic::display(){
    for(int i = 0; i < CLASSIC_SORTED_BY.size(); ++i){
        std::cout << CLASSIC_SORTED_BY[i] << ": " << productData[CLASSIC_SORTED_BY[i]] << std::endl;
    }
}

// The dataTypeNames() and sortedByNames() are helper methods which quickly 
// retrieve the corresponding _DATA_TYPES and _SORTED_BY arrays. 
// const std::string* Classic::dataTypeNames() const{
//     return Classic::CLASSIC_DATA_TYPES;
// }

// const std::string* Classic::sortedByNames() const{
//     return Classic::CLASSIC_SORTED_BY;
// }

// returns unique identifier
std::string Classic::getKey(){
    return "Classic";
}


//TODO: comparison operators
// //comparison operators compare product by their sorting criteria
// bool Classic::operator==(const NodeData &) const{

// }

// bool Classic::operator!=(const NodeData &) const{

// }

// bool Classic::operator<(const NodeData &) const{

// }

// bool Classic::operator>(const NodeData &) const{

// }

// bool Classic::operator<=(const NodeData &) const{

// }

// bool Classic::operator>=(const NodeData &) const{

// }