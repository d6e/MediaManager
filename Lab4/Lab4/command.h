#ifndef COMMAND_H
#define COMMAND_H
#include "customerindex.h"
#include "error.h"
#include <string>

/*
Pure virtual command class. It is the parent to the other command classes.
*/
class Command {
public:
    Command();
    ~Command();
    Error execute(String);
};

#endif