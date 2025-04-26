#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers;
    int n, value;

    std::cout << "How many integers do you want to input? ";
    std::cin >> n;

    std::cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; ++i) {
        std::cin >> value;
        numbers.push_back(value);
    }

    std::cout << "Your input:\n";
    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "\n";

    int evenSum = 0;
    for (auto it = numbers.begin(); it != numbers.end(); ++it) {
        if (*it % 2 == 0) {
            evenSum += *it;
        }
    }

    std::cout << "Sum of even numbers: " << evenSum << std::endl;

    return 0;
}
