#include <string>
#include <iostream>

void binary(int number);


int main(){

    std::string str = "AZ aztest is a test.";
    std::cout << str[0] << " --- " << (int)str[0] << std::endl;

    return 0;
}

void binary(int number) {
    int remainder;

    if(number <= 1) {
        std::cout << number;
        return;
    }

    remainder = number % 2;
    binary(number >> 1);    
    std::cout << remainder;
}