#include <iostream>
#include <string>
#include "calc.h"

int main() {
    std::string input;

    std::cout << "enter example or stop if you want to stop working:\n";

    while (true) {
        std::cout << "> ";
        std::getline(std::cin, input);

        if (input == "stop") {
            std::cout << "program completed.\n";
            break;
        }

        try {
            double result = evaluate(input);
            std::cout << "result: " << result << "\n";
        } catch (const std::exception& e) {
            std::cerr << "error: " << e.what() << "\n";
        }
    }

    return 0;

    try {
        std::string expression = "3.5*2";
        double result = evaluate(expression);
        std::cout << "result of expression \"" << expression << "\" = " << result << std::endl;
    } catch (const std::exception& e) {
        std::cerr << "error: " << e.what() << std::endl;
    }

    return 0;
}
