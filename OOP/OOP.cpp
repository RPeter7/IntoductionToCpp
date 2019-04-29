#include "pch.h"
#include <iostream>
#include "Hallgato.h"
#include <string>
//class Hallgato //hallgatot nem hozunk itt letre! MINDIG kulon fajlba
//{

//}/* h1, h2*/; // igy jön automatikusan létre példány (globalis valtozok lesznek, nem csinalunk ilyet csak a pontosvesszo miatt mutatta)

void kiir(const Hallgato& h_) //refkent adjuk at -> takarekoskodunk a memoriaval.
{
	std::cout << h_.getNev() << std::endl;
}

//void kiir(Hallgato h_) //Ha ez van const es ref nelkul, akkor itt masolodik a h1 a h_ba!!! ez Copy Constuktorral jön létre. => Hallhato h_(h1)
//{
//	std::cout << h_.getNev() << std::endl;
//} Itt van egy destruktor hivas! Elszall a KÓD a main destruktoranal! Mert megpróbálja a destruktor a h1 utalltTantargyat felszabadítani! DE AZT ITT a kiir metodus vegen mar felszabaditottuk

int main()
{
	// Fontos!! ezt NEM kell megszuntetni!!
	//Hallgato h1/*()*/; //igy mar letrejon egy objektum. (STACKEN jon letre) (+ konstruktor termeszetesen meghivodik, ha nincs zarojel)

	//Hallgato* h2 = new Hallgato; //ez van a HEAPEN (ez a h2 pointer lesz)
	// Fontos!! ezt meg is kell szuntetni!!
	/*=>*/// delete h2;

	Hallgato h1("Gipsz Jakab");
	std::cout << h1.getNev() << std::endl;
	kiir(h1);

	/*h1.setNev("Tegla Jalab");
	h1.setKedvencTantargy("C++11");*/
	// => ehelyett:

	h1.setNev("Tegla Jalab").setKedvencTantargy("C++11");


	Hallgato* h2 = new Hallgato("Hallgato Helga");
	std::cout << h2->getNev() << std::endl;

	const Hallgato h3("Okos Otto");
	std::cout << h3.getNev() << std::endl;

	delete h2; //destruktor h2 itt hivodik
} // itt h1 destruktora. AUTOMATIKUSAN
