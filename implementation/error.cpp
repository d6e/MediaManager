#include "error.h"

Error::Error(){
    msg = "";
}

Error::Error(std::string err){
    msg = err;
}

Error::~Error(){
    msg = "";
}

//Accessor for error message
std::string Error::getErrorMessage() const{
    return msg;
}

//ostream override
std::ostream& operator<< (std::ostream &out, Error &error){
    out << error.getErrorMessage();
    return out;
}  