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
#include "commandfactory.h"
#include "historycmd.h"    
#include "productformat.h"    
#include "productformatcollection.h"    
#include "productcollection.h"    
#include "comedy.h"    
#include "product.h"    
#include "nodedata.h"    
#include <vector>

using namespace std;

int main(){
    cout << "----------------------------------------------------------------------" << endl;

    Manager M;

    vector<string> custData;
    Input custInput;
    custInput.read("data4customers.txt");
    custData = custInput.get();

    for(int i = 0; i < custData.size(); ++i){
        M.inputCustomer(custData[i]);
    }
    M.inputCmd("H 1373");
    
    return 0;
}