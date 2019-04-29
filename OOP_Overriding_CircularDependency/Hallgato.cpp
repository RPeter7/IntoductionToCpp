#include "pch.h"
#include "Hallgato.h"


Hallgato::Hallgato(const std::string& nev_) :
	_nev(nev_),
	_legjobbBarat(NULL),
	_kedvTantargy(NULL)
{
	_kedvTantargy = new Tantargy("C++");
}


Hallgato::~Hallgato()
{
	delete _kedvTantargy;
}