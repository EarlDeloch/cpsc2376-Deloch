#include "MixedFraction.h"
#include <iostream>
#include <cmath>


MixedFraction::MixedFraction(int w, int n, int d) {
    if (d == 0) {
        throw std::invalid_argument("Denominator cannot be zero");
    }

    int absNum = std::abs(n);
    int sign = (w < 0 || n < 0) ? -1 : 1;

    whole = w;
    int improperNumerator = std::abs(w) * d + absNum;

    
    if (!setFraction(sign * improperNumerator, d)) {
        std::cout << "Failed to set fraction in MixedFraction." << std::endl;
    }
}

// Constructor from Fraction
MixedFraction::MixedFraction(const Fraction& fraction) {
    int n = fraction.getNumerator();
    int d = fraction.getDenominator();

    whole = n / d;
    int remainder = std::abs(n % d);

    
    if (!setFraction((n < 0 ? -1 : 1) * remainder, d)) {
        std::cout << "Failed to set fraction in MixedFraction." << std::endl;
    }
}

// Stream output
std::ostream& operator<<(std::ostream& out, const MixedFraction& mf) {
    if (mf.whole != 0) {
        out << mf.whole;
        if (mf.getNumerator() != 0) {
            out << " " << std::abs(mf.getNumerator()) << "/" << mf.getDenominator();
        }
    }
    else if (mf.getNumerator() != 0) {
        out << mf.getNumerator() << "/" << mf.getDenominator();
    }
    else {
        out << "0";
    }
    return out;
}

