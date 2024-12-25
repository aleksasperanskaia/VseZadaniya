#include <boost/algorithm/string.hpp>
#include <iostream>

int main() {
    std::string input="MSU\tBAKU\tLAB";
    std::vector<std::string>result;

    boost::split(result, input, boost::is_any_of("\t"));

    for(std::string item: result) {
        std::cout<<item<<"\t";
    }
    return 0;
}