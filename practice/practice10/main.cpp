#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>
#include <memory>

const double PI = 3.14159;

// Base class
class Shape {
public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
};

// Derived class: Rectangle
class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double getArea() const override {
        return width * height;
    }
};

// Derived class: Circle
class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    double getArea() const override {
        return PI * radius * radius;
    }
};

// Function to print all areas
void printAllAreas(const std::vector<std::unique_ptr<Shape>>& shapes) {
    for (const auto& shape : shapes) {
        std::cout << "Area: " << std::fixed << std::setprecision(4)
                  << shape->getArea() << std::endl;
    }
}

int main() {
    std::ifstream file("shapes.txt");
    if (!file) {
        std::cerr << "Failed to open shapes.txt\n";
        return 1;
    }

    std::vector<std::unique_ptr<Shape>> shapes;
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream iss(line);
        std::string type;
        iss >> type;

        if (type == "rectangle") {
            double w, h;
            if (iss >> w >> h) {
                shapes.push_back(std::make_unique<Rectangle>(w, h));
            }
        } else if (type == "circle") {
            double r;
            if (iss >> r) {
                shapes.push_back(std::make_unique<Circle>(r));
            }
        }
    }

    printAllAreas(shapes);

    return 0;
}
