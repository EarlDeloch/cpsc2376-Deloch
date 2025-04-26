#include <iostream>
#include <vector>
#include <numeric> // for std::accumulate

int main() {
    std::vector<int> numbers;
    int n, value;

    std::cout << "How many numbers will you input? ";
    std::cin >> n;

    std::cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; ++i) {
        std::cin >> value;
        numbers.push_back(value);
    }

    // Sum using std::accumulate
    int sum = std::accumulate(numbers.begin(), numbers.end(), 0);

    // Product using std::accumulate with a custom lambda
    int product = std::accumulate(numbers.begin(), numbers.end(), 1, [](int a, int b) {
        return a * b;
    });

    std::cout << "Sum of all elements: " << sum << std::endl;
    std::cout << "Product of all elements: " << product << std::endl;

    return 0;
}
