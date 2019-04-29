#include <iostream>
#include "Bank.h"

using namespace std;
using namespace bankLogProcess;

int main()
{
	Bank bank;
	ifstream inputFile("banklog.txt");
	while (!inputFile.eof())
	{
		inputFile >> bank;
	}
	inputFile.close();
	bank.endOfDayProcess();
	cout << bank;
}