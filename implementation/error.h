#pragma once
#ifndef ERROR_H
#define ERROR_H
#include <string>
#include <ostream>

/*
The error class has a private string datamember that holds an error message.
*/

class Error {
private:
    std::string msg;
public:
    Error();  // Creates an error object with an empty string
     // assigns error message string to datamember string
    Error(std::string err); 
    virtual ~Error();
    std::string getErrorMessage() const;  // returns msg
    friend std::ostream& operator<< (std::ostream &out, Error &error);
};


#endif