#include <iostream>
#include <string>
#include "calc.h"

int main() {
    std::string input;

    std::cout << "Введите математическое выражение (или введите 'stop' для выхода):\n";

    while (true) {
        std::cout << "> ";
        std::getline(std::cin, input);

        if (input == "stop") {
            std::cout << "Программа завершена.\n";
            break;
        }

        try {
            double result = evaluate(input);
            std::cout << "Результат: " << result << "\n";
        } catch (const std::exception& e) {
            std::cerr << "Ошибка: " << e.what() << "\n";
        }
    }

    return 0;

    try {
        std::string expression = "3.5*2";
        double result = evaluate(expression);
        std::cout << "Результат выражения \"" << expression << "\" = " << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "Ошибка: " << e.what() << std::endl;
    }

    return 0;
}