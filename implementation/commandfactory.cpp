#include "commandfactory.h"
#include <sstream>

// The CommandFactory constructor that takes a CustomerIndex and a
// ProductCollection is used to pass along the two data structures 
// to it's products.
// constructor, inits hash table
CommandFactory::CommandFactory(CustomerIndex* cI, ProductCollection* pC){
    cIndex = cI;
    pCollect = pC;
    //TODO: init hashtable
} 

// The create method takes in a string and parses out the command portion of the
// string. It then creates an instance of a child command object based on the 
// command it parsed. Finally, it returns a pointer to that command.
Command* CommandFactory::create(std::string key){
//TODO: parse string and create appropriate command
    std::string cmdString;
    std::string restOfString;
    std::stringstream ss;
    ss << key;
    ss >> cmd;
    restOfString = ss.str();

    Command* cmd = NULL;
    switch (cmdString)
    {
        case "H":  // history
            cmd = new HistoryCMD();
            return cmd;
            break;
        case "B": // borrow
            cmd = new BorrowCMD();
            return cmd;
            break;
        case "R": // return
            cmd = new ReturnCMD();
            return cmd;
            break;
        case "S": // display all products
            cmd = new DisplayAllProductCMD();
            return cmd;
            break;
        default: // command not accepted, returning NULL Command pointer
            return cmd;
    }
}

int CommandFactory::hash(std::string key){
    return 0; //TODO: finish this
}