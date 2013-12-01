#include "manager.h"
#include <sstream>
#include <iostream>

Manager::Manager(){
    cIndex = new CustomerIndex();
    pCollect = new ProductCollection(); 
    cFactory = new CommandFactory(cIndex, pCollect); 
    pFactory = new ProductFactory(pCollect); 
}

Manager::~Manager(){
    delete cIndex;
    delete pCollect;
    delete cFactory;
    delete pFactory;
}

bool Manager::inputProduct(std::string){
    return true; //TODO
} 

bool Manager::inputCustomer(std::string custDetails){
    std::stringstream ss;
    std::string token, custID, first, last;

    ss << custDetails;
    ss >> custID; 
    ss >> first; 
    ss >> last; 

    std::cout << "inputcustomer custID: " << custID << std::endl;

    Customer* cust = new Customer(custID, first, last);
    cIndex->insertCustomer(cust);
    return true; //TODO
}

bool Manager::inputCmd(std::string cmdString){
    Error e;
    Command* cmd = cFactory->create(cmdString);
    e = cmd->execute();
    std::cout << e << std::endl;
    return true; //TODO
}