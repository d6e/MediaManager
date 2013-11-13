#ifndef MANAGER_H
#define MANAGER_H
#include "customerindex.h"
#include "productcollection.h"
#include "commandfactory.h"
#include "productfactory.h"
#include "error.h"
#include <string>

/*
The manager class is the main controller for the program. IO is handled outside the Manager class
so all input is assumed to be lines of strings.
*/

class Manager{

private:
    CustomerIndex customerDB; // Stores customer information and history.
    ProductCollection productDB; // Stores product information and quantities
    CommandFactory cFactory; // Creates commands.
    ProductFactory mFactory; // Creates products.

public:
	Manager(); //Initializes all collections and factories
	virtual ~Manager();
	
	bool inputProduct(std::string); // Inputs new products, prints errors in process, returns false if failed.
    bool inputCustomer(std::string);// Inputs new customers, prints errors in process, returns false if failed.
    bool inputCmd(std::string);// Inputs commands into system, prints errors in process, returns false if failed.
};

#endif