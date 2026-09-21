// Patrick Murray
// CIS-2542-NET01
// Homework 6

// CookieNotation.h

#ifndef COOKIE_NOTATION_H
#define COOKIE_NOTATION_H

#include <ostream>

class CookieNotation
{
public:
	CookieNotation(double coef = 0, int exp = 0, bool needsToBeNormal = true);
	double getCoefficient() const;
	int getExponent() const;
	void setCoefficient(double coef);
	void setExponent(int exp);

	// Modifies an object to standard scientific notation (ie. 0.25e4 -> 2.5e3)
	void normalize();

	// Converts an object to a specified exponent
	friend CookieNotation convertToE(const CookieNotation& num, int newExp);

	// Addition operator: "+"
	friend CookieNotation operator + (const CookieNotation& lhs, const CookieNotation& rhs);
	
	// Output operator: "<<"
	friend std::ostream& operator << (std::ostream& display, const CookieNotation& rhs);

	// Copy Assignment Operator: "="
	CookieNotation& operator = (const CookieNotation& rhs);

private:
	double coefficient;
	int exponent;
};

#endif