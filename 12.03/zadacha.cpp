#include<iostream>
#include<vector>
#include <random>

int sum=0;

void vec_sum(int index, const std::vector<int>&vec) {

}

int main() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(1, 100000);

    int random_number1 = dist(gen);
    std::cout << "Случайное число от 1 до 100'000: " << random_number1 << std::endl;


    return 0;
}