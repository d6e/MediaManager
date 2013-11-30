#include "manager.h"

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

bool Manager::inputCustomer(std::string){
    return true; //TODO

}

bool Manager::inputCmd(std::string){
    return true; //TODO

}