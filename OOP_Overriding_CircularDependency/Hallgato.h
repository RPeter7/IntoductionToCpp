#pragma once
#include <string>
#include "Tantargy.h"
class Tantargy;

class Hallgato
{
public:
	Hallgato(const std::string& nev_ = "");
	~Hallgato();
private:
	std::string _nev;
	//Hallgato _legjobbBarat; Ilyet nem lehet csin�lni... 
	Hallgato* _legjobbBarat;
	Tantargy* _kedvTantargy;
};