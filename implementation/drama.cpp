#include "drama.h"


// The constructor creates a bunch of ProductData objects and initializes their
// keys.
Drama::Drama(){
//TODO: find out if productdata objects should even be created.
    T_SIZE = 3;
    S_SIZE = 2;

    //TODO: Makes these const and put them in an initializer list
    std::string DRAMA_DATA_TYPES[3] = {"director","title","date"};
    std::string DRAMA_SORTED_BY[2] = {"director","title"};
}

// cleans up any productdata objects it created
Drama::~Drama(){}

// The setData method takes in a pointer to an event object and the data it 
// contains to the event object's data. If the event object input is invalid,
// it returns false, otherwise true.
bool Drama::setData(Event*){
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

// The display method displays the private data members using cout.
void Drama::display(){

}

// The dataTypeNames() and sortedByNames() are helper methods which quickly 
// retrieve the corresponding _DATA_TYPES and _SORTED_BY arrays. 
const std::string* Drama::dataTypeNames() const{
    return Drama::DRAMA_DATA_TYPES;
}

const std::string* Drama::sortedByNames() const{
    return Drama::DRAMA_SORTED_BY;
}

// returns unique identifier
std::string Drama::getKey(){
    return "Drama";
}


//TODO: comparison operators
// //comparison operators compare product by their sorting criteria
// bool Drama::operator==(const NodeData &) const{

// }

// bool Drama::operator!=(const NodeData &) const{

// }

// bool Drama::operator<(const NodeData &) const{

// }

// bool Drama::operator>(const NodeData &) const{

// }

// bool Drama::operator<=(const NodeData &) const{

// }

// bool Drama::operator>=(const NodeData &) const{

// }