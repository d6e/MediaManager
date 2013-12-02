#include <string>
#include <fstream>
#include "manager.h"
//TODO: separate input reading from string reading (maybe)
int main(){
	ifstream movieInput("data4movies.txt");
  ifstream cmdInput("data4customers.txt");
  ifstream customerInput("data4customers.txt");
	if (!(movieInput&&customerInput&&cmdInput)) {
    	cout << "One or more files could not be opened." << endl;
        return 1;
   	}
   	//TODO: read other files as necessary
  Manager productManager;
  productManager.inputProduct(movieInput); 
  productManager.inputCmd(cmdInput);
  productManager.displayAll();   //TODO: this will eventually be processed through commands instead.
   	
	return 1;
}