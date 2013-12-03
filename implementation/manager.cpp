#include "manager.h"
#include <sstream>

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

    cIndex = NULL;
    pCollect = NULL;
    cFactory = NULL;
    pFactory = NULL;
}

bool Manager::inputProduct(std::string movieDetails){
    Product* pdtPtr = pFactory->create(movieDetails);
    pCollect->insert(pdtPtr);
    return true; //TODO
} 

void Manager::displayAllProducts(){
    pCollect->displayAll();
}

bool Manager::inputCustomer(std::string custDetails){
    std::stringstream ss;
    std::string custID, first, last;

    ss << custDetails;
    ss >> custID; 
    ss >> first; 
    ss >> last; 

    Customer* cust = new Customer(custID, first, last);
    cIndex->insertCustomer(cust);
    cust = NULL;
    return true; //TODO
}

bool Manager::inputCmd(std::string cmdString){
    Error e;
    Command* cmd = cFactory->create(cmdString);
    e = cmd->execute();
    std::cout << e << std::endl;
    return true; //TODO
}