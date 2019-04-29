#include "pch.h"
#include "Negyzet.h"

Negyzet::Negyzet(const std::string& szin_, double oldalHossz_) :
	Teglalap(szin_, oldalHossz_, oldalHossz_)
{
}

void Negyzet::setMagassag(double magassag_)
{
	setOldalHossz(magassag_);
}

void Negyzet::setSzelesseg(double szelesseg_)
{
	setOldalHossz(szelesseg_);
}

void Negyzet::setOldalHossz(double oldalHossz_)
{
	if (oldalHossz_ >= 0.0)
	{
		_magassag = oldalHossz_;
		_szelesseg = oldalHossz_;
	}
	cachedKerulet = 0.0;
	cachedTerulet = 0.0;
}

std::string Negyzet::toString() const
{
	return Sikidom::toString() + "Oldalhossz: " + std::to_string(_magassag) + "\n";
}
