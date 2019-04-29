#include "pch.h"
#include <iostream>
#include "Complex.h"

//Complex operator+(const Complex& lhs_, const Complex& rhs_) 
//{
//	Complex result(lhs_._re + rhs_._re, lhs_._im + rhs_._im); Ez nem jó, mert nem látja privát adattagokat
//	return result;
//}

int main()
{
	Complex c1; //Pramétermentes konstruktor
	Complex c2(3); //1 paraméteres konst
	Complex c3(3, -5); //2 paraméteres konst

	Complex c4 = c1; //Complex c4(c1); copy konst

	//std::cout << c3.toString() << std::endl;

	//C++ ban minden Operator egy függvény!!
	//Complex c1 = c2 + c3; igy Copy konst lenne!!
	c1 = c2 + c3; //értékadó operator alapértelmezetten definialva van!!

	std::cout << c1.toString() << std::endl;
	std::cout << (c4 = c1 + 5).toString() << std::endl;
	(c4 += c2).toString();

	Complex c5 = 3 + c4; //das ist nehéz

	std::cout << c5.toString() << std::endl;

	//std::ostream
	std::cout << c1 << std::endl;

	std::cin >> c5;
}


