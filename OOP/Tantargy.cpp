#include "pch.h"
#include "Tantargy.h"


Tantargy::Tantargy(const std::string nev_)
{
	_nev = nev_;
}

std::string Tantargy::getNev() const
{
	return _nev;
}

void Tantargy::setNev(const std::string & nev_)
{
	_nev = nev_;
}
