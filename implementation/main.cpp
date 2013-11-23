#include <iostream>
#include <fstream>
#include <string>
#include "input.h"
#include "error.h"


using namespace std;

int main(){
    // TESTING INPUT
    Input I;
    I.read("data.txt");
    cout << I.get() << endl;

    // TESTING ERROR
    Error E("Testing error message");
    cout << E.getErrorMessage() << endl;



    return 0;
}