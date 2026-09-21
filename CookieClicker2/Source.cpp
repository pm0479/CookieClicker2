// Patrick Murray
// CIS-2542-NET01
// Homework 6

// Source.cpp

// Thouroughly testing the CookieNotation class for
// the upcoming game "Cookie Clicker 2: Grandma's Wrath"

#include <iostream>
#include "CookieNotation.h"

int main()
{
	// Basic construction, setters and output tests
	CookieNotation blank;
	CookieNotation example1(3.5, 6);
	CookieNotation example2;
	example2.setCoefficient(2.0);
	example2.setExponent(5);

	CookieNotation sixtyTwo(6.2, 1);
	CookieNotation thirtyThree(3.3, 1);

	std::cout << "[Basic construction and output tests]" << std::endl;
	std::cout << "Expected: 0e0   | " << blank << std::endl;
	std::cout << "Expected: 3.5e6 | " << example1 << std::endl;
	std::cout << "Expected: 2e5   | " << example2 << '\n' << std::endl;
	std::cout << "62 = " << sixtyTwo << std::endl;
	std::cout << "33 = " << thirtyThree << std::endl;
	std::cout << '\n';

	// Normalization during construction tests
	CookieNotation notNormal(0.25, 0);
	CookieNotation unNormal(25, 10);
	CookieNotation abNormal(2576);
	CookieNotation deNormal(-0.067);
	CookieNotation stayWierd(0.25, -3, false);

	std::cout << "[Normalization tests]" << std::endl;
	std::cout << "0.25e0 = " << notNormal << std::endl;
	std::cout << "25e10  = " << unNormal << std::endl;
	std::cout << "2576   = " << abNormal << std::endl;
	std::cout << "-0.067 = " << deNormal << '\n' << std::endl;
	std::cout << "Expected: 0.25e-3 | " << stayWierd << std::endl;
	std::cout << '\n';

	// Basic addition tests
	CookieNotation example3(1.423, 9);
	CookieNotation example4(2.173, 6);

	CookieNotation tenThousand(10000);
	CookieNotation fiveThousand(5000);
	CookieNotation twoFiftyTwo(252);

	std::cout << "[Basic addition tests]" << std::endl;
	std::cout << "Expected: 3.7e6      | " << example1 + example2 << std::endl;
	std::cout << "Expected: 1.425173e9 | " << example3 + example4 << '\n' << std::endl;
	std::cout << "6.2e1 + 3.3e1 = " << sixtyTwo + thirtyThree << std::endl;

	std::cout << "10,000 + 5000 + 252 = " << (tenThousand + fiveThousand) + twoFiftyTwo << std::endl;
	std::cout << '\n';

	// Large number addition tests
	CookieNotation big1(4.5, 9);
	CookieNotation big2(1.1, 5);

	std::cout << "[Large number addition tests]" << std::endl;
	std::cout << "4.5e9 + 1.1e5 = " << big1 + big2 << std::endl;
	std::cout << '\n';
	
	CookieNotation big3 = big1 + big1;
	CookieNotation big4 = big2 + big2 + big2;
	CookieNotation bigCopy = big4;

	std::cout << "4.5e9 + 4.5e9 = " << big3 << std::endl;
	std::cout << "9.0e9 + 4.5e9 = " << big3 + big1 << '\n' << std::endl;
	std::cout << "Expected: 3.3e5 | " << big4 << std::endl;
	std::cout << "Expected: 3.3e5 | " << bigCopy << std::endl;
	std::cout << '\n';

	// Negative values tests
	CookieNotation negativeBase(-6700000);
	CookieNotation oneMillion(1, 6);
	
	CookieNotation negativeExp(0.00567);
	CookieNotation oneHundredth(0.01);

	std::cout << "[Negative values tests]" << std::endl;
	std::cout << "Expected: -5.7e6   | " << negativeBase + oneMillion << std::endl;
	std::cout << "Expected: 1.567e-2 | " << negativeExp + oneHundredth << std::endl;
	std::cout << '\n';

	// Copy construction/assignment tests
	std::cout << "[Copy construction/assignment tests]" << std::endl;

	CookieNotation a(1, 2);
	std::cout << "Expected: 1e2 | " << a << std::endl;

	CookieNotation b(a);
	std::cout << "Expected: 1e2 | " << b << std::endl;

	CookieNotation c(2, 4);
	std::cout << "Expected: 2e4 | " << c << std::endl;

	c = b;
	std::cout << "Expected: 1e2 | " << c << std::endl;
	std::cout << '\n';
}