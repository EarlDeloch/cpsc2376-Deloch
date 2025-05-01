#pragma once
#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>


class Fraction {
private:
    int num;  // Numerator
    int den;  // Denominator

public:
    // Constructors
    Fraction();               // Default constructor (0/1)
    Fraction(int n, int d);   // Parameter constructor

    // Getters and Setters
    int getNumerator() const;
    int getDenominator() const;
    bool setFraction(int n, int d); // False if the denominator is 0

    // Simplification
    void simplify(); 

    // Operators
    friend Fraction operator+(const Fraction& lhs, const Fraction& rhs);
    friend Fraction operator-(const Fraction& lhs, const Fraction& rhs);
    friend Fraction operator*(const Fraction& lhs, const Fraction& rhs);
    friend Fraction operator/(const Fraction& lhs, const Fraction& rhs);

    // Comparison
    friend bool operator==(const Fraction& lhs, const Fraction& rhs);

    // Stream output
    friend std::ostream& operator<<(std::ostream& out, const Fraction& f);
};

#endif