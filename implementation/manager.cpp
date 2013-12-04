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
    Error e = pCollect->insert(pdtPtr);
    if(e.getErrorMessage() != ""){
        // delete pdtPtr;
        // pdtPtr = NULL;
        std::cout << e << std::endl;
        return false;
    }
    return true;
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
    Error e = cIndex->insertCustomer(cust);
    if(e.getErrorMessage() != ""){
        delete cust;
        cust = NULL;
        std::cout << e << std::endl;
        return false;
    }
    return true;
}

bool Manager::inputCmd(std::string cmdString){
    Error e;
    Command* cmd = cFactory->create(cmdString);
    if(cmd == NULL){
        return false;
    }
    e = cmd->execute();
    if(e.getErrorMessage() != ""){
        std::cout << e << std::endl;
        return false;
    }
    return true;
}

std::vector<std::string> Manager::getInputData(const char* file){
    Input in;
    in.read(file);
    return in.get();
}