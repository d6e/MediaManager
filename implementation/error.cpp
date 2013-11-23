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