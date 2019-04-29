#pragma once
#include "Sikidom.h"
#ifndef Teglalap_hpp
#define Teglalap_hpp

class Teglalap : public Sikidom
{
public:
	Teglalap(const std::string& szin_, double magassag_, double szelesseg_);
	double kerulet() const;
	double terulet() const;
	double getMagassag() const;
	virtual void setMagassag(double);
	double getSzelesseg() const;
	virtual void setSzelesseg(double);
private:
	std::string toString() const;

protected:
	double _magassag;
	double _szelesseg;
};

#endif /* Teglalap_hpp */
