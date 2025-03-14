#include <iostream>
#include <thread>

int main() {
    unsigned int  num_threads = std::thread::hardware_concurrency();

    if(num_threads != 0) {
        std::cout << num_threads << "\n";
    }
    return 0;
}
