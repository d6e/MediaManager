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

    //customers
    std::vector<std::string> custData = M.getInputData("data4customers.txt");
    for(int i = 0; i < custData.size(); ++i){
        M.inputCustomer(custData[i]);
    }

    //products
    std::vector<std::string> prodData = M.getInputData("data4movies.txt");
    for(int i = 0; i < prodData.size(); ++i){
        M.inputProduct(prodData[i]);
    }

    //commands
    std::vector<std::string> cmdData = M.getInputData("data4commands.txt");
    for(int i = 0; i < cmdData.size(); ++i){
        // M.inputCmd(cmdData[i]);
    }
    M.inputCmd("S");
/*
    Product* movie = new Comedy();
    Event* e = new Event("F Todd Phillips, The Hangover, 2009");
    movie->setData(e);

    ProductFormat* pf = new ProductFormat("DVD");
    std::cout << pf->getName() << std::endl;


    ProductFormatCollection pfc;
    pfc.addProductFormat(*pf);
    std::cout << pfc.getFormatNames() << std::endl;
    std::cout << pfc.getFormatAmount(pf) << std::endl;
    pfc.incrProductQuantity("DVD");
    std::cout << pfc.getFormatAmount(pf) << std::endl;
    delete movie;
    delete pf;
    // delete e;
*/
    return 0;
}