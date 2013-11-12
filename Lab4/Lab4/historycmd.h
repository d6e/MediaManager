#ifndef HISTORYCMD_H
#define HISTORYCMD_H
#include <string>
#include "customerindex.h"
#include "command.h"

/*
*/
class HistoryCMD : public Command {    
private:
    CustomerIndex* cIndex;
	String custInfo;
public:
    HistoryCMD(CustomerIndex* index, String customerInfo);
    ~HistoryCMD();
    Error execute(); 
};

#endif