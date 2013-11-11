#ifndef ERROR_H
#define ERROR_H
#include <string>

/*
*/
class Error {
private:
    String msg;
public:
    Error(String err);
    ~Error();
    String getErrorMessage() const;
};


#endif