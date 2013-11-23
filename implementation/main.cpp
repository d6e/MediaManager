#include <iostream>
#include <fstream>
#include <string>
#include "input.h"
#include "error.h"
#include "manager.h"

using namespace std;

int main(){
    // TESTING INPUT
    Input I;
    I.read("data.txt");
    // cout << I.get() << endl;

    // TESTING ERROR
    Error E("Testing error message");
    // cout << E.getErrorMessage() << endl;

    Manager M();


    return 0;
}