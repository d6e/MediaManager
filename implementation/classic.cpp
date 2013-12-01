#include "classic.h"

Classic::Classic(){}

// The constructor creates a bunch of ProductData objects and initializes their
// keys.
Classic::Classic(std::string director, std::string title, 
        std::string famousActor, std::string date){
//TODO: find out if productdata objects should even be created.
    T_SIZE = 4;
    S_SIZE = 2;

    //TODO: Makes these const and put them in an initializer list
    std::string CLASSIC_DATA_TYPES[4] = {"director","title", "famous actor",
            "date"};
    std::string CLASSIC_SORTED_BY[2] = {"date","famous actor"};
}

// cleans up any productdata objects it created
Classic::~Classic(){}

// The setData method takes in a pointer to an event object and the data it 
// contains to the event object's data. If the event object input is invalid,
// it returns false, otherwise true.
bool Classic::setData(Event*){
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

}

// The dataTypeNames() and sortedByNames() are helper methods which quickly 
// retrieve the corresponding _DATA_TYPES and _SORTED_BY arrays. 
const std::string* Classic::dataTypeNames() const{
    return Classic::CLASSIC_DATA_TYPES;
}

const std::string* Classic::sortedByNames() const{
    return Classic::CLASSIC_SORTED_BY;
}

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