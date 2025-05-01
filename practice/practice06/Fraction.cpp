#include "Fraction.h"
#include <iostream>
#include <cmath>

// Default constructor
Fraction::Fraction() {
    num = 0;
    den = 1;
}

// Parameter constructor
Fraction::Fraction(int n, int d) {
    setFraction(n, d);
}

// Getters and Setters
int Fraction::getNumerator() const {
    return num;
}

int Fraction::getDenominator() const {
    return den;
}

bool Fraction::setFraction(int n, int d) {
    if (d == 0) {
        std::cout << "Error: Denominator cannot be zero!" << std::endl;
        return false;  // Failure
    }
    num = n;
    den = d;
    simplify();
    return true;  // Success
}

// Simplify the fraction using Euclidean algorithm
void Fraction::simplify() {
    if (num == 0) {
        den = 1;
        return;
    }

    int a = abs(num), b = abs(den);
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    int gcd = a;
    num /= gcd;
    den /= gcd;

    if (den < 0) {
        num = -num;
        den = -den;
    }
}

// Arithmetic Operators
Fraction operator+(const Fraction& lhs, const Fraction& rhs) {
    int newNum = lhs.num * rhs.den + rhs.num * lhs.den;
    int newDen = lhs.den * rhs.den;
    return Fraction(newNum, newDen);
}

Fraction operator-(const Fraction& lhs, const Fraction& rhs) {
    int newNum = lhs.num * rhs.den - rhs.num * lhs.den;
    int newDen = lhs.den * rhs.den;
    return Fraction(newNum, newDen);
}

Fraction operator*(const Fraction& lhs, const Fraction& rhs) {
    int newNum = lhs.num * rhs.num;
    int newDen = lhs.den * rhs.den;
    return Fraction(newNum, newDen);
}

Fraction operator/(const Fraction& lhs, const Fraction& rhs) {
    if (rhs.num == 0) {
        std::cout << "Error: Cannot divide by zero!" << std::endl;
        return Fraction(0, 1);  // Return a default fraction (0/1)
    }
    int newNum = lhs.num * rhs.den;
    int newDen = lhs.den * rhs.num;
    return Fraction(newNum, newDen);
}

// Comparison
bool operator==(const Fraction& lhs, const Fraction& rhs) {
    return lhs.num == rhs.num && lhs.den == rhs.den;
}

// Stream Output
std::ostream& operator<<(std::ostream& out, const Fraction& f) {
    if (f.den == 1) {
        out << f.num;
    }
    else {
        out << f.num << "/" << f.den;
    }
    return out;
}
