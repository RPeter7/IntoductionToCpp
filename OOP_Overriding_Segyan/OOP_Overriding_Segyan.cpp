#include "pch.h"
#include <iostream>
#include "Complex.h"


int main(int argc, const char * argv[])
{
	Complex c1;
	Complex c2(1, 4);
	Complex c3;

	std::cin >> c3;

	std::cout << c2 << " + " << c3 << " = " << c2 + c3 << std::endl;
	std::cout << c2 << " - " << c3 << " = " << c2 - c3 << std::endl;
	std::cout << c2 << " * " << c3 << " = " << c2 * c3 << std::endl;
	try
	{
		std::cout << c2 << " / " << c3 << " = " << c2 / c3 << std::endl;
	}
	catch (...)
	{
		std::cout << "NaN" << std::endl;
	}

	std::cout << "Square of " << c2 << " = " << c2.pow(2) << std::endl;
	std::cout << "3rd root of " << c3 << " = " << c3.nthRoot(3) << std::endl;

	if (c2 += c3)
	{
		std::cout << "Real part of " << c2 << " = " << static_cast<double>(c2) << std::endl;
	}
}
