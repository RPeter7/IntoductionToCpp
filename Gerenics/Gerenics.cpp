// Gyak_08_Generics_Template.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include "Stack.h"

using namespace std;

template<typename T> //Nincs megszoritas!! Lehetne ilyen is: template<class T> UGYAN AZ!
T min(const T& a, const T& b)
{
	return a < b ? a : b;
}

//C++ forditas: 1. Eloforditas, 
//2. Forditas,
//3. linkelés
int main()
{
	//cout << min<int>(3, 5) << endl; //int
	//cout << min<double>(4.6, -2.3) << endl; //double
	//cout << min<string>("alma", "barack") << endl; // string de nem jon ra! segitsunk neki.
	Stack<int> intStack;
	/*Stack<string> stringStack;*/
	intStack.push(3);
	intStack.push(7);
	intStack.push(11);

	for (Stack<int>::iterator it = intStack.begin(); it != intStack.end(); it++)
	{
		cout << *it << endl;
	}

	//cout << intStack.pop() << endl;
	//cout << intStack.pop() << endl;

	//Stack<int> otherIntStack = intStack; //nem szol a fordito de nincs megirva altalunk a copy const, vagyis el fog szallni amig meg nem irjuk
	// Valojaban ez van a hatterben => Stack<int> otherIntStack(intStack);

}

//string min(const string& a, const string& b)
//{
//	return a < b ? a : b;
//}
//
//double min(double a, double b)
//{
//	return a < b ? a : b;
//}
//
//int min(int a, int b)
//{
//	return a < b ? a : b;
//}

