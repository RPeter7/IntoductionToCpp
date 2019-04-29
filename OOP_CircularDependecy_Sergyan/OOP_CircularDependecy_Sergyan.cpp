#include "pch.h"
#include <iostream>
#include "Hallgato.h"

using std::cout;

int main()
{
	Hallgato* h1 = new Hallgato("Hallgato Helga");
	Hallgato* h2 = new Hallgato("Hallgato Huba", h1);
	Hallgato h3("Hallgato Helena");
	Hallgato h4("Hallgato Hugo", &h3);
	cout << h1->getNev() << ": " << h1->getLegjobbBaratNeve() << std::endl;
	cout << h2->getNev() << ": " << h2->getLegjobbBaratNeve() << std::endl;
	h1->setLegjobbBarat(h2);
	h2->setNev("Hallgato Homar");
	cout << h1->getNev() << ": " << h1->getLegjobbBaratNeve() << std::endl;
	h2->setLegjobbBarat(NULL);
	cout << h2->getNev() << ": " << h2->getLegjobbBaratNeve() << std::endl;
	h1->setLegjobbBarat(&h3);
	cout << h1->getNev() << ": " << h1->getLegjobbBaratNeve() << std::endl;
	delete h2;
	delete h1;
}
