#include "pch.h"
#include <iostream>
#include <string>

std::string s = "Elso tipus";

//using namespace std;
int a = 3; //Glob�lis v�ltoz�
const int x = 5; //Itt fontosak a const-ok! Amit lehet tegy�nk const-�.
//c++ -ban NINCS DEFAULT VALUE!!
//unsigned int 
//signed int = sima int;
//short //1 2 vagy 4 bajt
//long --legal�bb annyi mint az int, de lehet t�bb
//long long --nem rovidebb mint a long
char c1 = 3; //biztos 1 bajtot foglal!
char c2 = 'a';

// ami nem 0 az igaz.
bool l1 = true;
bool l2 = false;
bool l3 = 35; // true
bool l4 = -3; // true
bool l5 = 0; // = false

int main()
{
	int x = 4;
	std::cout << x << ", " << &x << std::endl;

	int* p = &x; //Mem�riac�m t�rol�s. * -> p mutat� egy int t�pus� c�mre.
	std::cout << p << ", " << *p /* dereferencia mutat� */ << std::endl;

	const int* p1 = &x;
	//(*p1)++; //ez nem lehet, mert const
	int* p2 = &x;
	*p2++;

	//int x = 4;
	//if ( x = 3 ) //Tipikus hiba.. == helyett = �rtelmezve van
	//{

	//}

	//int y = 5;
	//while (y--)
	//{

	//}

	//std::cout << "Hello World!\n"; HELYETT:
	//std::cout << "Hello World!" << std::endl;
	//cout << "Hello World!" << endl;

	//int x = 0; //32bites kornyezetben 4bajt, 64 esen: 8bajt //Lok�lis v�ltoz� //Musz�j kezdeti �rt�ket adni!
	//std::cin >> x;
	//std::cout << ++x << ", " << ::x << std::endl;
}