#include "pch.h"
#include "Teglalap.h"


Teglalap::Teglalap(const std::string& szin_, double magassag_, double szelesseg_) :
	Sikidom(szin_),
	_magassag(magassag_),
	_szelesseg(szelesseg_)
{
}

double Teglalap::kerulet() const
{
	if (cachedKerulet == 0.0)
	{
		cachedKerulet = 2 * (_magassag + _szelesseg);
	}
	return cachedKerulet;
}

double Teglalap::terulet() const
{
	if (cachedTerulet == 0.0)
	{
		cachedTerulet = _magassag * _szelesseg;
	}
	return cachedTerulet;
}

double Teglalap::getMagassag() const
{
	return _magassag;
}

void Teglalap::setMagassag(double magassag_)
{
	if (magassag_ >= 0.0)
	{
		_magassag = magassag_;
	}
	cachedKerulet = 0.0;
	cachedTerulet = 0.0;
}

double Teglalap::getSzelesseg() const
{
	return _szelesseg;
}

void Teglalap::setSzelesseg(double szelesseg_)
{
	if (szelesseg_ >= 0.0)
	{
		_szelesseg = szelesseg_;
	}
	cachedKerulet = 0.0;
	cachedTerulet = 0.0;
}

std::string Teglalap::toString() const
{
	return Sikidom::toString() + "Magassag: " + std::to_string(_magassag) + ", szelesseg: " + std::to_string(_szelesseg) + "\n";
}
