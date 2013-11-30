#include "commandfactory.h"
#include <sstream>
#include <typeinfo>
#include <iostream>

// The CommandFactory constructor that takes a CustomerIndex and a
// ProductCollection is used to pass along the two data structures 
// to it's products.
// constructor, inits hash table
CommandFactory::CommandFactory(CustomerIndex* cI, ProductCollection* pC) 
        : HASH_TABLE_SIZE(256){
    cIndex = cI;
    pCollect = pC;    
    
    cmds['H'] = new HistoryCMD(cIndex);
    cmds['B'] = new BorrowCMD(cIndex, pCollect);
    cmds['R'] = new ReturnCMD(cIndex, pCollect);
    cmds['S'] = new DisplayAllProductCMD(pCollect);
} 

CommandFactory::~CommandFactory(){
    for(it = cmds.begin(); it != cmds.end(); ++it) {
        std::cout << "type: " << typeid(*it).name() << std::endl;
        delete it->second;
    }
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
    ss >> cmdString;
    restOfString = ss.str();
    char cmdChar = cmdString.at(0); //Convert string to a char

    Command* cmd = NULL;
    cmd = cmds[cmdChar];
    cmd->setData(new Event(restOfString));
    return cmd;

/*
    Command* cmd = NULL;
    switch (cmdString.at(0)) //Convert string to a char
    {
        case 'H':  // history
            cmd = new HistoryCMD(cIndex, new Event(restOfString));
            cmds.push_back(cmd);
            return cmd;
            break;
        case 'B': // borrow
            cmd = new BorrowCMD(cIndex, pCollect, new Event(restOfString));
            cmds.push_back(cmd);
            return cmd;
            break;
        case 'R': // return
            cmd = new ReturnCMD(cIndex, pCollect, new Event(restOfString));
            cmds.push_back(cmd);
            return cmd;
            break;
        case 'S': // display all products
            cmd = new DisplayAllProductCMD(pCollect);
            cmds.push_back(cmd);
            return cmd;
            break;
        default: // command not accepted, returning NULL Command pointer
            cmds.push_back(cmd);
            return cmd;
    }
    */
}

int CommandFactory::hash(std::string key){
    return 0; //TODO: finish this
}