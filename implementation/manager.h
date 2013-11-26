#ifndef MANAGER_H
#define MANAGER_H
#include <string>
#include <iostream>
#include "productcollection.h"
#include "productfactory.h"
/*
#include "customerindex.h"

#include "commandfactory.h"

#include "error.h"
*/

/*
The manager class is the main controller for the program. IO is handled 
outside the Manager class so all input is assumed to be lines of strings.
*/

class Manager{

private:
    //CustomerIndex customerDB; // Stores customer information and history.
    ProductCollection productDB; // Stores product information and quantities
    ProductFactory mFactory; // Creates products.
    //CommandFactory cFactory; // Creates commands.
   

public:
	Manager(); //Initializes all collections and factories
	
    //virtual ~Manager();
	
    // Inputs new products, prints errors in process, returns false if failed.
	bool inputProduct(ifstream&); 

    //TEMPORARY
    void displayAll() const; //displays all products.
    //TEMPORARY

    // Inputs new customers, prints errors in process, returns false if failed.
    /*
    bool inputCustomer(std::string);
    // Inputs commands into system, prints errors in process, 
    // returns false if failed.
    bool inputCmd(std::string);
    */
};

#endif