#include <iostream>
#include <fstream>
#include <string>
#include "input.h"
#include "error.h"
// #include "manager.h"
// #include "hashtable.h"
#include "event.h"
#include "history.h"
#include "customer.h"
#include "customerindex.h"
#include "command.h"
#include "commandfactory.h"
#include "historycmd.h"    
#include "productformat.h"    
#include "productformatcollection.h"    
#include "productcollection.h"    
#include "comedy.h"    
#include "product.h"    
#include "nodedata.h"    

using namespace std;

int main(){
    /*
    // TESTING INPUT
    Input I;
    I.read("data.txt");
    // cout << I.get() << endl;
*/
    // Manager M;
/*
    //clang++ main.cpp event.cpp history.cpp error.cpp customerindex.cpp customer.cpp
    Event* e = new Event("D F You've Got Mail, 1998");
    Event* e2 = new Event("f d shawn of the dead, 1458");
    Event* e3 = new Event("bitches need stitches");

    cout << "checking history... " <<  endl;
    History hist;
    hist.addEvent(e);
    hist.addEvent(e2);
    hist.displayAll();


    cout << endl << "checking customer index..." << endl;
    Customer* cust1 = new Customer("1232", "Anthony", "Giovannetti");
    CustomerIndex cindex;
    cindex.insertCustomer(cust1);
    cindex.addTransaction("1232", e);
    cindex.addTransaction("1232", e2);
    cindex.addTransaction("1232", e3);
    cindex.displayHistory("1232");
    if (cindex.customerExists("1232"))cout << "customer exists!!" << endl;
    if (!cindex.customerExists("4654"))cout << "customer doesnt'!!" << endl;

    delete e;
    delete e2;
    delete e3;
    delete cust1;
*/


/*
    //clang++ main.cpp productformat.cpp product.cpp productformatcollection.cpp nodedata.cpp
    ProductFormat* pf = new ProductFormat("D");
    ProductFormat* pf2 = new ProductFormat("B");
    cout << "product format: " << pf->getName() << endl;

    ProductFormatCollection* pfc = new ProductFormatCollection();
    pfc->addProductFormat(*pf);
    pfc->addProductFormat(*pf2);
    cout << "format amount: " << pfc->getFormatAmount(pf) << endl;
    cout << "formats: " << pfc->getFormatNames() << endl;
    delete pf;
    delete pf2;
    delete pfc;
*/

/*
    NodeData* nd = new Comedy();
    cout << nd->getKey() << endl;
    delete nd;
*/

    

// clang++ main.cpp event.cpp history.cpp error.cpp customerindex.cpp customer.cpp productcollection.cpp bintree.cpp
    CustomerIndex* cIndex = new CustomerIndex();
    ProductCollection* pColl = new ProductCollection();

    CommandFactory* cmdfact = new CommandFactory(cIndex, pColl);

    Error e;
    Error er;
    Customer* cust1 = new Customer("1373", "Anthony", "Giovannetti");
    cIndex->insertCustomer(cust1);

    Command* cmd = cmdfact->create("H 1373");
    e = cmd->execute();
    cout << e << endl;

    Command* cmd2 = cmdfact->create("H 1373");
    er = cmd2->execute();
    cout << er << endl;


    delete cIndex;
    delete pColl;
    delete cmdfact;
    delete cmd;
    delete cmd2;
    delete cust1;

    return 0;
}