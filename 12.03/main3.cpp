#include<iostream>
#include<future>
#include <chrono>

int returnTwo() {
    return 2;
}

int main() {
    std::future<int> f=std::async(std::launch::async, returnTwo);

    if(f.valid()) {
        std::cout<<f.get()<<"\n";
    } else {
        std::cout<<"invalid state\n";
    }

    if(f.valid()) {
        std::cout<<f.get()<<"\n";
    } else {
        std::cout<<"invalid state\n";
    }

    return 0;
}