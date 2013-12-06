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

//Insert a product into the productcollection
bool Manager::inputProduct(std::string movieDetails){
    Product* pdtPtr = pFactory->create(movieDetails);
    Error e = pCollect->insert(pdtPtr);
    if(e.getErrorMessage() != ""){
        std::cout << e << std::endl;
        return false;
    }
    return true;
} 

//display all the products in the product collection
void Manager::displayAllProducts(){
    pCollect->displayAll();
}

//Insert a customer into the customer index
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

//Create and run a command
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

//Read the specified file and output a vector of the read data
std::vector<std::string> Manager::getInputData(const char* file){
    Input in;
    in.read(file);
    return in.get();
}