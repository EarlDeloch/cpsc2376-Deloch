#include <iostream>

double convertTemperature(double temp, char tempScale = 'F') {
    return (tempScale == 'F') ? (temp * 9.0 / 5 + 32) : ((temp - 32) * 5.0 / 9);
}

int main() {
    int choice;
    double inputTemp;

    std::cout << "1. Convert Celsius to Fahrenheit\n";
    std::cout << "2. Convert Fahrenheit to Celsius\n";
    std::cout << "Choose an option: ";
    std::cin >> choice;

    std::cout << "Enter temperature: ";
    std::cin >> inputTemp;

    if (choice == 1) {
        double result = convertTemperature(inputTemp, 'F');
        std::cout << "Converted: " << result << "°F\n";
    } else if (choice == 2) {
        double result = convertTemperature(inputTemp, 'C');
        std::cout << "Converted: " << result << "°C\n";
    } else {
        std::cout << "Invalid option.\n";
    }

    return 0;
}
