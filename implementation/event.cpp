#include "event.h"

Event::Event(){}

Event::~Event(){}

void Event::display() const{  // Display the data from one event object
	if(arguments.empty() || product == NULL){
		return; 	//should this print out something to show that the event is empty?
	}
	//this would be more extensible if there were other formats besides DVD
	std::cout << "DVD " << transactionName() << "  " 
			  << product -> dataDisplay();
	std::cout << std::endl;
}
   
Error Event::set(std::ifstream& dataInput){ // Parses input a string into the list.
	Error empty;
	std::string dataLine;
    std::getline(dataInput, dataLine);
    std::stringstream stream(dataLine);
    std::string nextData;
    stream >> nextData;
	while(stream){
		arguments.push_back(nextData);
		stream >> nextData;
	}
	return empty;
}

void Event::makeEmpty(){
	arguments.clear();
}

std::string Event::getToken(unsigned int index) const{
	if (arguments.size() > index){
		std::list<std::string>::const_iterator it = arguments.begin();
		std::advance(it, index);
        return *it;
    }
    return "";
}

std::string Event::productData() const{
	if(arguments.size() > MIN_TRANSACTION_LENGTH){
		std::string data;
		std::list<std::string>::const_iterator it = arguments.begin();
		std::advance(it, MIN_TRANSACTION_LENGTH - 1);
		for(; it != arguments.end(); ++it){
			data += *it + " ";
		}
		return data;
	}
	return "";
}

std::string Event::transactionName() const{
	std::string t = getToken(0);
	if(t == "B") {return "Borrow";}
	if(t == "R") {return "Return";}
	return "";
}

void Event::setProduct(Product* p){
	product = p;
}