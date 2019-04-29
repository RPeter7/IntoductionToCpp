#pragma once
#include <string>
#include "Hallgato.h"

//class Hallgato;

class Tantargy
{
public:
	Tantargy(const std::string& nev_ = "");
	~Tantargy();
private:
	std::string _nev;
	Hallgato* _legjobbHallgato;
};

