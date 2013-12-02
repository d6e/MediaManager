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
            eventToken.push_back(eventDetails.at(i));        
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

// The display method displays the private data members using cout.
void Drama::display(){
    for(int i = 0; i < DRAMA_SORTED_BY.size(); ++i){
        std::cout << DRAMA_SORTED_BY[i] << ": " << productData[DRAMA_SORTED_BY[i]] << std::endl;
    }
}

// The dataTypeNames() and sortedByNames() are helper methods which quickly 
// retrieve the corresponding _DATA_TYPES and _SORTED_BY arrays. 
// const std::string* Drama::dataTypeNames() const{
//     return Drama::DRAMA_DATA_TYPES;
// }

// const std::string* Drama::sortedByNames() const{
//     return Drama::DRAMA_SORTED_BY;
// }

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