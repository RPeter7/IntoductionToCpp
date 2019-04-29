#include "pch.h" //Ha forditani akarjuk akkor be kell includealni a pch.h t!! (VS hulyesege)
#include "Hallgato.h"

//ide kerul az, hogy mi a mûködés.

//Hallgato::Hallgato()
//{
//}
//
//
//Hallgato::~Hallgato()
//{
//}

Hallgato::Hallgato(const std::string& nev_) :
	//_nev(), //Valójában ez is lefut, DE
	_nev(nev_), //itt adunk erteket
	_kedvencTantargy("C++"), //nem ebben a sorrendben fut le, hanem deklarációs sorrendbe!!
	_utaltTantargy(NULL) //itt null erteket adunk neki. (EZ POINTER) NEM KELL ITT LENNIE! NEM IS SZOKTAK LETREHOZNI
{
	//_nev = nev_; ennel
	_utaltTantargy = new Tantargy("Nincs ilyen"); //Pointert itt inicializalunk! EZT FEL KELL SZABDITANI
}

Hallgato::Hallgato(const Hallgato& hallgato_) :
	_nev(hallgato_._nev),
	_kedvencTantargy(hallgato_._kedvencTantargy)
{
	_utaltTantargy = new Tantargy(hallgato_._utaltTantargy->getNev());
}

Hallgato::~Hallgato()
{
	delete _utaltTantargy;
}

std::string Hallgato::getNev() const
{
	return _nev;
}

Hallgato& Hallgato::setNev(const std::string & nev_)
{
	_nev = nev_;
	return *this;

}

Hallgato& Hallgato::setKedvencTantargy(const std::string & tantargyNev_)
{
	_kedvencTantargy.setNev(tantargyNev_);
	return *this;
}