#ifndef COMMANDCONTROL_H
#define COMMANDCONTROL_H
#include <string>
#include "command.h"
#include "error.h"

/*
*/
class CommandControl {    
private:
    int size = 0;
    Command[] cmds;
public:
    CommandControl(size);
    ~CommandControl();
    AddCommand(Command);
    Error RunCommand(String);
};

#endif