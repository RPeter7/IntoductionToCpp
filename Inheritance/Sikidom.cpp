#include "pch.h"
#include "Sikidom.h"

Sikidom::Sikidom(const std::string& szin_) :
	_szin(szin_)
{
	_lyukas = false;
}

void Sikidom::kilyukaszt()
{
	_lyukas = true;
}

std::string Sikidom::toString() const
{
	return "Szin: " + _szin + (_lyukas ? " (lyukas)" : " (teli)") + "\nKerulet: " + std::to_string(kerulet()) + ", terulet: " + std::to_string(terulet()) + "\n";
}

std::ostream& operator<<(std::ostream& os_, Sikidom* const sikidom_)
{
	os_ << sikidom_->toString();
	return os_;
}

Sikidom::~Sikidom()
{
}
