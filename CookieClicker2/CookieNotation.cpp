// Patrick Murray
// CIS-2542-NET01
// Homework 6

// CookieNotation.cpp

#include "CookieNotation.h"
#include <cmath>
#include <algorithm>

// Constructor
CookieNotation::CookieNotation(double coef, int exp, bool needsToBeNormal)
    : coefficient(coef),
      exponent(exp)
{
    // During creation, only specify needsToBeNormal as false 
    // if you want it to stay in non-standard form. Default is true.
    if (needsToBeNormal == true)
    {
        normalize();
    }
}

double CookieNotation::getCoefficient() const
{
    return coefficient;
}

int CookieNotation::getExponent() const
{
    return exponent;
}

void CookieNotation::setCoefficient(double coef)
{
    coefficient = coef;
}

void CookieNotation::setExponent(int exp)
{
    exponent = exp;
}

// Modifies an object to standard scientific notation (ie. 0.25e4 -> 2.5e3)
void CookieNotation::normalize()
{
    while (std::abs(coefficient) >= 10)
    {
        coefficient /= 10;
        ++exponent;
    }
    while (std::abs(coefficient) > 0 && std::abs(coefficient) < 1)
    {
        coefficient *= 10;
        --exponent;
    }
}

// Converts object to a specified exponent
CookieNotation convertToE(const CookieNotation& num, int newExp)
{
    int expShiftVal = newExp - num.getExponent();

    if (expShiftVal == 0)
    {
        return num;
    }

    double newCoef = num.getCoefficient() / std::pow(10, expShiftVal);

    return CookieNotation(newCoef, newExp, false); // needsToBeNormal = false
}

// Addition operator: "+"
CookieNotation operator+(const CookieNotation& lhs, const CookieNotation& rhs)
{
    int exp = std::max(lhs.getExponent(), rhs.getExponent());
    CookieNotation left = convertToE(lhs, exp);
    CookieNotation right = convertToE(rhs, exp);

    double coef = left.getCoefficient() + right.getCoefficient();

    CookieNotation sum(coef, exp);
    return sum;
}

// Display operator: "<<"
std::ostream& operator<<(std::ostream& display, const CookieNotation& rhs)
{
    display << rhs.coefficient << "e" << rhs.exponent;
    return display;
}

// Copy Assignment Operator: "="
CookieNotation& CookieNotation::operator=(const CookieNotation& rhs)
{
    exponent = rhs.exponent;
    coefficient = rhs.coefficient;
    return *this;
}