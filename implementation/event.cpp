#include "event.h"

Event::Event(){}

Event::~Event(){
	arguments.clear();
}

void Event::display() const{  // Display the data from one event object
	for (std::list<std::string>::const_iterator 
		it=arguments.begin(); 
		it != arguments.end(); ++it){
		std::cout << *it + " ";
	}
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