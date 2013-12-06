#pragma once
#ifndef COMMANDFACTORY_H
#define COMMANDFACTORY_H
#include "customerindex.h"
#include "productcollection.h"
#include "productfactory.h"
#include "command.h"
#include "historycmd.h"
#include "borrowcmd.h"
#include "displayallproductcmd.h"
#include "returncmd.h"
#include <string>
#include <map>

/*
A factory that produces Commands based on a key to a hashtable containing 
the different types of Command objects.
*/


class CommandFactory {
private:
    CustomerIndex* cIndex; // For commands that need access to the customers
    // For commands that need to access the products
    ProductCollection* pCollect; 
    ProductFactory* pFactory; // For commands that need to create products.
    std::map<char, Command*> cmds; //stores possible commands
    std::map<char, Command*>::iterator it; //an iterator for cmds

public:
    // constructor, inits hash table
	CommandFactory(CustomerIndex*, ProductCollection*); 
	virtual ~CommandFactory();    // destructor
    // Creates and inits cmd obj based on key given, returns null if invalid key
    Command* create(std::string key);   
    bool keyExists(char);
};

#endif