#include<iostream>
#include<future>
#include <chrono>

int returnTwo() {
    return 2;
}

int main() {
    std::future<int> f=std::async(std::launch::async, returnTwo);
    std::cout<<f.get();

    return 0;
}