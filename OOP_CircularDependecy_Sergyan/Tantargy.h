#pragma once
#ifndef Tantargy_hpp
#define Tantargy_hpp
#include <string>
#include "Hallgato.h"

class Hallgato;

class Tantargy
{
public:
	Tantargy(const std::string& nev_);

	std::string getNev() const;

private:
	std::string _nev;
	Hallgato* _legjobbHallgato;
};

#endif /* Tantargy_hpp */
