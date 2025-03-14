#include <iostream>
#include <regex>
#include <string>


int main() {
    std::string s{"I LOVE MSU Baku"};
    std::regex r{"MSU[a-z, A-Z, ]?"};

    /*std::regex r{"|(MSU)(.*)"};
    if(std::regex_match(s,r)) {
        std::cout<<"it's regex\n";
    }
    if(std::regex_match(s.begin(), s.end(), r)) {
        std::cout<<"it's SUB  regex\n";
    }*/

    std::smatch result;
    std::regex_search(s, result, r);

    for(auto x:result) {
        std::cout<< x<<"";
    }

    return 0;
}
