#include <iostream>
#include <limits>

// Template function
template<typename T>
T calculate(T a, T b, char op) {
    if (op == '+') return a + b;
    else if (op == '-') return a - b;
    else if (op == '*') return a * b;
    else if (op == '/') return (b != 0) ? a / b : 0;
    else return 0;
}

// Function to get a number from user
double getValidNumber(const std::string& prompt) {
    double num;
    while (true) {
        std::cout << prompt;
        std::cin >> num;

        if (std::cin.fail()) {
            std::cin.clear(); //Clear flag
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Remove invalid input
            std::cout << "Invalid number. Please try again.\n";
        } else {
            return num;
        }
    }
}

int main() {
    char op;

    double a = getValidNumber("Enter first number: ");
    double b = getValidNumber("Enter second number: ");

    std::cout << "Enter operation (+, -, *, /): ";
    std::cin >> op;

    std::cout << "Result: " << calculate(a, b, op) << "\n";

    return 0;
}
