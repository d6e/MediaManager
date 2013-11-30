#include "comedy.h"

// The constructor creates a bunch of ProductData objects and initializes their
// keys.
Comedy::Comedy(){
//TODO: find out if productdata objects should even be created.
    T_SIZE = 3;
    S_SIZE = 2;

    //TODO: Makes these const and put them in an initializer list
    std::string COMEDY_DATA_TYPES[3] = {"director","title","date"};
    std::string COMEDY_SORTED_BY[2] = {"title","date"};
}

// cleans up any productdata objects it created
Comedy::~Comedy(){

}

// The setData method takes in a pointer to an event object and the data it 
// contains to the event object's data. If the event object input is invalid,
// it returns false, otherwise true.
bool Comedy::setData(Event*){
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

// The display method displays the private data members using cout.
void Comedy::display(){

}

// The dataTypeNames() and sortedByNames() are helper methods which quickly 
// retrieve the corresponding _DATA_TYPES and _SORTED_BY arrays. 
const std::string* Comedy::dataTypeNames() const{
    return Comedy::COMEDY_DATA_TYPES;
}

const std::string* Comedy::sortedByNames() const{
    return Comedy::COMEDY_SORTED_BY;
}

// returns unique identifier
std::string Comedy::getKey(){
    return "Comedy";
}


//TODO: comparison operators
// //comparison operators compare product by their sorting criteria
// bool Comedy::operator==(const NodeData &) const{

// }

// bool Comedy::operator!=(const NodeData &) const{

// }

// bool Comedy::operator<(const NodeData &) const{

// }

// bool Comedy::operator>(const NodeData &) const{

// }

// bool Comedy::operator<=(const NodeData &) const{

// }

// bool Comedy::operator>=(const NodeData &) const{

// }