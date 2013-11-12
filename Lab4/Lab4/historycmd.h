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
public:
    HistoryCMD();
    ~HistoryCMD();
    execute(); 
};

#endif