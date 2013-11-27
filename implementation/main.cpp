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

using namespace std;

int main(){
    /*
    // TESTING INPUT
    Input I;
    I.read("data.txt");
    // cout << I.get() << endl;
*/
    // // TESTING ERROR
    // Error E("Testing error message");
    // cout << E.getErrorMessage() << endl;


    // Manager M;
/*    
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

    CommandFactory cmdfact();
    Command* cmd = cmdfact.create("H 1373");
    cmd->execute();


    return 0;
}