#include <iostream>
#include <string>
#include "calc.h"

int main() {
    std::string input;

    std::cout << "Введите математическое выражение (например, 3 + 5 * (2 - 8)^2): ";
    std::getline(std::cin, input);

    try {
        double result = evaluate(input);
        std::cout << "Результат: " << result << std::endl;
    } catch (const std::exception &e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}
