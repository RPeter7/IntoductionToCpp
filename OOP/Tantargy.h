#pragma once
#include <string>
class Tantargy
{
public:
	Tantargy(const std::string nev_);
	std::string getNev() const;
	void setNev(const std::string& nev_);
private:
	std::string _nev;
};