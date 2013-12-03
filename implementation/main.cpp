#include <iostream>
#include <fstream>
#include <string>
#include "input.h"
#include "error.h"
#include "manager.h"
// #include "hashtable.h"
#include "event.h"
#include "history.h"
#include "customer.h"
#include "customerindex.h"
#include "command.h"
#include "bintree.h"
#include "commandfactory.h"
#include "historycmd.h"    
#include "productformat.h"    
#include "productformatcollection.h"    
#include "productcollection.h"    
#include "comedy.h"    
#include "product.h"    
#include "nodedata.h"    
#include <vector>

int main(){
    std::cout << "----------------------------------------------------------------------" << std::endl;

    Manager M;

    std::vector<std::string> custData;
    Input custInput;
    custInput.read("data4customers.txt");
    custData = custInput.get();

    std::vector<std::string> prodData;
    Input prodInput;
    prodInput.read("data4movies.txt");
    prodData = prodInput.get();

    for(int i = 0; i < custData.size(); ++i){
        M.inputCustomer(custData[i]);
    }

    for(int i = 0; i < 5; ++i){
        M.inputProduct(prodData[i]);
    }
    // M.inputProduct("F Todd Phillips, The Hangover, 2009");
    M.displayAllProducts();
    M.inputCmd("H 1373");



/*
    Product* movie = new Comedy();
    Event* e = new Event("F Todd Phillips, The Hangover, 2009");
    movie->setData(e);

    ProductFormat* pf = new ProductFormat("DVD");
    std::cout << pf->getName() << std::endl;


    ProductFormatCollection inventory;
    inventory.addProductFormat(*pf);
    std::cout << inventory.getFormatNames() << std::endl;
    std::cout << inventory.getFormatAmount(pf) << std::endl;
    inventory.duplicate("DVD");
    std::cout << inventory.getFormatAmount(pf) << std::endl;
    delete movie;
    delete pf;
    // delete e;
*/
    return 0;
}