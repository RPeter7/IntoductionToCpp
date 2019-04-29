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
	//Hallgato _legjobbBarat; Ilyet nem lehet csinálni... 
	Hallgato* _legjobbBarat;
	Tantargy* _kedvTantargy;
};