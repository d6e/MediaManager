#ifndef ERROR_H
#define ERROR_H
#include <string>

/*
The error class has a private string datamember that holds an error message.

On construction, error takes in an error message string and assigns it to the
object's error message datamember. Alternatively, if no error message string
is passed in, the error object contains an empty string. 

It has an accessor method called getErrorMessage that returns the private 
error message datamember.
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
};


#endif