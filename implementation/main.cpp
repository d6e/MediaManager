#include <iostream>
#include "input.h"
#include "manager.h"
#include <vector>

int main(){
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
        M.inputCmd(cmdData[i]);
    }

    return 0;
}