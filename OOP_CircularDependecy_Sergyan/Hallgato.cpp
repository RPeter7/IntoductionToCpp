#include "pch.h"
#include "Hallgato.h"

Hallgato::Hallgato(const string& nev_) :
	_nev(nev_),
	_legjobbBarat(NULL),
	_kedvencTantargy(NULL)
{
}

Hallgato::Hallgato(const string& nev_, Hallgato* const legjobbBarat_) :
	_nev(nev_),
	_legjobbBarat(legjobbBarat_),
	_kedvencTantargy(NULL)
{
}

Hallgato::Hallgato(const Hallgato& hallgato_) :
	_nev(hallgato_._nev),
	_legjobbBarat(hallgato_._legjobbBarat),
	_kedvencTantargy(NULL)
{
}

void Hallgato::operator=(const Hallgato& hallgato_)
{
	_nev = hallgato_._nev;
	_legjobbBarat = hallgato_._legjobbBarat;
	_kedvencTantargy = hallgato_._kedvencTantargy;
}

string Hallgato::getNev() const
{
	return _nev;
}

Hallgato* Hallgato::getLegjobbBarat() const
{
	return _legjobbBarat;
}

string Hallgato::getLegjobbBaratNeve() const
{
	return getLegjobbBarat() ? getLegjobbBarat()->getNev() : "No best friend";
}

void Hallgato::setLegjobbBarat(Hallgato* const hallgato_)
{
	_legjobbBarat = hallgato_;
}

void Hallgato::setNev(const string& nev_)
{
	_nev = nev_;
}

void Hallgato::setKedvencTantargy(Tantargy* const kedvencTantargy_)
{
	_kedvencTantargy = kedvencTantargy_;
}
