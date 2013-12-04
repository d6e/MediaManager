#include <string>
#include <fstream>
#include "manager.h"
//TODO: separate input reading from string reading (maybe)
//IDEA: could have methods for reading all of a file, which call the methods for
      //reading individual lines
int main(){
	ifstream movieInput("data4movies.txt");
  ifstream customerInput("data4customers.txt");
  ifstream cmdInput("data4commands.txt");
	if (!(movieInput&&customerInput&&cmdInput)) {
    	cout << "One or more files could not be opened." << endl;
        return 1;
   	}
   	//TODO: read other files as necessary
  Manager productManager;
  productManager.inputProduct(movieInput); 
  productManager.inputCustomer(customerInput);
  productManager.inputCmd(cmdInput);
   	
	return 1;
}