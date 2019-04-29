#ifndef Hallgato_hpp
#define Hallgato_hpp
#include "Tantargy.h"
#include <string>

using std::string;

class Tantargy;

class Hallgato
{
public:
	Hallgato(const string& nev_);
	Hallgato(const string& nev_, Hallgato* const legjobbBarat_);
	Hallgato(const Hallgato& hallgato_);
	void operator=(const Hallgato& hallgato_);

	string getNev() const;
	Hallgato* getLegjobbBarat() const;
	string getLegjobbBaratNeve() const;

	void setNev(const string& nev_);
	void setLegjobbBarat(Hallgato* const hallgato_);
	void setKedvencTantargy(Tantargy* const kedvencTantargy_);
private:
	string _nev;
	Hallgato* _legjobbBarat;
	Tantargy* _kedvencTantargy;
};

#endif /* Hallgato_hpp */
