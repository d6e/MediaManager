#ifndef MANAGER_H
#define MANAGER_H
#include <string>
#include <iostream>
#include "productcollection.h"
#include "productfactory.h"
#include "commandfactory.h"
/*
#include "customerindex.h"
*/

/*
The manager class is the main controller for the program. IO is handled 
outside the Manager class so all input is assumed to be lines of strings.
*/

class Manager{

private:
    
    ProductCollection* productDB; // Stores product information and quantities
    ProductFactory* mFactory; // Creates products.
    CommandFactory* cFactory; // Creates commands.
    CustomerIndex* customerDB; // Stores customer information and history.

public:
	Manager(); //Initializes all collections and factories
	
    virtual ~Manager();
	
    // Inputs new products, prints errors in process, returns false if failed.
	bool inputProduct(ifstream&); 
    // Inputs new customers, prints errors in process, returns false if failed.
    bool inputCustomer(ifstream&);
    // Inputs commands into system, prints errors in process,
    // returns false if failed.
    bool inputCmd(ifstream&);
};

#endif