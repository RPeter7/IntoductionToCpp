#include "pch.h"
#include "Kor.h"

Kor::Kor(const std::string& szin_, double sugar_) :
	Sikidom(szin_),
	_sugar(sugar_)
{
}

double Kor::kerulet() const
{
	if (cachedKerulet == 0.0)
	{
		cachedKerulet = 2 * _sugar * pi;
	}
	return cachedKerulet;
}

double Kor::terulet() const
{
	if (cachedTerulet == 0.0)
	{
		cachedTerulet = _sugar * _sugar * pi;
	}
	return cachedTerulet;
}

double Kor::getSugar() const
{
	return _sugar;
}

void Kor::setSugar(double sugar_)
{
	if (sugar_ >= 0.0)
	{
		_sugar = sugar_;
	}
	cachedKerulet = 0.0;
	cachedTerulet = 0.0;
}

std::string Kor::toString() const
{
	return Sikidom::toString() + "Sugar: " + std::to_string(_sugar) + "\n";
}
