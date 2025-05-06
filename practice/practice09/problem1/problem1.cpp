#include <iostream>
#include <string>

int main() {
    float redPotion{0.0f};   
    float bluePotion{0.0f};  
    float* flask{nullptr};    

    std::string input;

    while (true) {
        std::cout << "Which potion do you want to add liquid to? (Red / Blue / Done): ";
        std::getline(std::cin, input);

        // Convert input to lowercase for flexibility
        for (auto& c : input) c = tolower(c);

        if (input == "done") {
            break;
        } else if (input == "red") {
            flask = &redPotion;
        } else if (input == "blue") {
            flask = &bluePotion;
        } else {
            std::cout << "Invalid input. Please type Red, Blue, or Done.\n";
            continue;
        }

        std::cout << "How many mL to add? ";
        float amount{};
        std::cin >> amount;
        std::cin.ignore(); // clear newline

        if (amount < 0) {
            std::cout << "You can't add a negative amount!\n";
            continue;
        }

        *flask += amount;

        std::cout << "Red Potion: " << redPotion << " mL\n";
        std::cout << "Blue Potion: " << bluePotion << " mL\n";
    }

    std::cout << "Potion brewing complete!\n";
    return 0;
}
