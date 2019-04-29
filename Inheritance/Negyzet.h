#pragma once
#ifndef Negyzet_hpp
#define Negyzet_hpp

#include "Teglalap.h"

class Negyzet : public Teglalap
{
public:
	Negyzet(const std::string& szin_, double oldalHossz_);
	void setMagassag(double);
	void setSzelesseg(double);

private:
	void setOldalHossz(double);
	std::string toString() const;
};

#endif /* Negyzet_hpp */
