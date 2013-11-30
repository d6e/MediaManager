#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main{
    std::vector<std::string> v;
    std::string teststring = "What does the fox say?";
    std::string token;
    std::stringstream ss;
    ss << teststring;
    while (ss >> token)
    {
        v.push_back(token);
    }

    return 0;
}
