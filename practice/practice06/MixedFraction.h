#pragma once
#ifndef MIXEDFRACTION_H
#define MIXEDFRACTION_H

#include "Fraction.h"

class MixedFraction : public Fraction {
private:
    int whole;  // Whole number part

public:
    // Constructors
    MixedFraction(int whole, int numerator, int denominator);
    MixedFraction(const Fraction& fraction);

    // Getter
    int getWhole() const { return whole; }

    // Stream Output
    friend std::ostream& operator<<(std::ostream& out, const MixedFraction& mf);
};

#endif
