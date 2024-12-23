#include <iostream>
#include <memory>

int main() {
    int *ptr= new int(17);
    std::cout<< *ptr<<"\n";
    delete ptr;
    std::unique_ptr<int> smart=std::make_unique<int>(17);
    std::cout<< *smart<<"\n";
    return 0;
}