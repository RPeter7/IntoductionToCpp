#pragma once
#include <string>
#include "Tantargy.h"
class Hallgato
{
	//Adattagok megadasa:
private://ez alatt MINDEN private, addig amig nem lesz egy masik modosito kulcsszo
	std::string _nev; //alapbol private
	Tantargy _kedvencTantargy;
	Tantargy* _utaltTantargy; //ez csak pointer, ha nincs ertek adva! 
public:
	Hallgato(const std::string& nev_); //parameter const, és referencia!
	Hallgato(const Hallgato& h_);
	~Hallgato(); //igy nez ki! nincs masik fajtaja! Nincs parméter stb...
	/*const Ha itt lenne akkor const stringet kerne be*/ std::string getNev() const; //MUSZAJ IDE IRNI A CONSTOT, ha egy fuggveny nem modosit csak leker!!!
	Hallgato& setNev(const std::string& nev_);
	Hallgato& setKedvencTantargy(const std::string& tantargyNev_);


	//public:
	//	Hallgato();
	//	~Hallgato();
};