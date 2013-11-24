#include <iostream>
#include <fstream>
#include <string>
#include "input.h"
#include "error.h"
// #include "manager.h"
// #include "hashtable.h"
#include "event.h"
#include "history.h"

using namespace std;

int main(){
    /*
    // TESTING INPUT
    Input I;
    I.read("data.txt");
    // cout << I.get() << endl;

    // TESTING ERROR
    Error E("Testing error message");
    // cout << E.getErrorMessage() << endl;
*/
    // Manager M;
    
    Event* e = new Event;
    e->set("D F You've Got Mail, 1998");
    Event* e2 = new Event;
    e2->set("f d shawn of the dead, 1458");


    History hist;
    hist.addEvent(e);
    hist.addEvent(e2);
    hist.displayAll();



    return 0;
}