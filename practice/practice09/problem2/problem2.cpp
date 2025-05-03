#include <iostream>

struct Point {
    float x;
    float y;
};

// Function to calculate the midpoint between two points
Point calcMidpoint(const Point* p1, const Point* p2) {
    float midX = (p1->x + p2->x) / 2.0f;
    float midY = (p1->y + p2->y) / 2.0f;
    return Point{midX, midY};
}

int main() {
    //Get user input for the first point's coordinates
    Point a;
    std::cout << "Enter the coordinates for the first point (x y): ";
    std::cin >> a.x >> a.y;

    //Get user input for the second point's coordinates
    Point b;
    std::cout << "Enter the coordinates for the second point (x y): ";
    std::cin >> b.x >> b.y;

    //Call calcMidpoint using pointers to 'a' and 'b'
    Point mid = calcMidpoint(&a, &b);

    //Print the midpoint coordinates
    std::cout << "The midpoint is at (" << mid.x << ", " << mid.y << ")" << std::endl;

    return 0;
}