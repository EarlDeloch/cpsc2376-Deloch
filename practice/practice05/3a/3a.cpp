#include <iostream>
#include <vector>
#include <algorithm> // for std::for_each
#include <numeric>   // for std::accumulate

int main() {
    std::vector<int> numbers;
    int n, value;

    std::cout << "How many numbers will you enter? ";
    std::cin >> n;

    std::cout << "Enter " << n << " integers:\n";
    for (int i = 0; i < n; ++i) {
        std::cin >> value;
        numbers.push_back(value);
    }

    // Print each element squared using std::for_each and a lambda
    std::cout << "Squares:\n";
    std::for_each(numbers.begin(), numbers.end(), [](int x) {
        std::cout << x * x << " ";
    });
    std::cout << "\n";

    // Sum of squared elements using std::accumulate and a lambda
    int sumOfSquares = std::accumulate(numbers.begin(), numbers.end(), 0, [](int sum, int x) {
        return sum + x * x;
    });

    std::cout << "Sum of squares: " << sumOfSquares << std::endl;

    return 0;
}