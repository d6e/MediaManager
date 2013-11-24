#include "historycmd.h"

HistoryCMD(CustomerIndex*, Event*);          // default constructor
virtual ~HistoryCMD();                       // default destructor
// Returns false if data invalid, for factory use only.
virtual bool setData(Event*); 


//     The execute command will execute the given command from the IO
// It will return true, if the command is found and return ERROR 
// message if the command is not found.
Error execute(){
    return Error("This is the execute command.")
}