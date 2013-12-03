#include "customer.h"

void Customer::displayHistory() const{ // Calls history's displayAll method
	std::cout << "History for: " << firstName << " " << lastName
			  << "(ID: " + customerID << "):"<< std::endl;
	customerHistory.displayAll();
}

void Customer::setData(std::string id,std::string lName,std::string fName){
	customerID = id;
	lastName = lName;
	firstName = fName;
}

void Customer::addEvent(Event* e){ // Calls history's addTransaction method
	customerHistory.addEvent(e);
}

//TODO: comparison operators
bool Customer::operator==(const NodeData & n) const{return false;}
bool Customer::operator!=(const NodeData & n) const{return true;}
bool Customer::operator<(const NodeData & n) const{return false;}
bool Customer::operator>(const NodeData & n) const{return false;}
bool Customer::operator<=(const NodeData & n) const{return false;}
bool Customer::operator>=(const NodeData & n) const{return false;}

void Customer::duplicate(NodeData* n){} //TODO

void Customer::display(std::ostream& output) const{
	std::cout << firstName << " " << lastName << " (" << customerID << ")";
} 

const std::string Customer::getKey() const{return customerID;} //returns unique identifier (custID)

const std::string* Customer::dataTypeNames() const{return NULL;}	//TODO   
   
const int Customer::dataTypeCount() const{return 0;} //TODO 