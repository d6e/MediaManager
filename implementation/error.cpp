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

std::string Error::getErrorMessage() const{
    return msg;
}

std::ostream& operator<< (std::ostream &out, Error &error){
    out << error.getErrorMessage();
    return out;
}  