#pragma once
#ifndef Kor_hpp
#define Kor_hpp

#include <cmath>
#include "Sikidom.h"

const double pi = atan(1) * 4.0;

class Kor : public Sikidom
{
public:
	Kor(const std::string& szin_, double sugar_);
	double kerulet() const;
	double terulet() const;
	double getSugar() const;
	void setSugar(double);
private:
	std::string toString() const;

private:
	double _sugar;
};

#endif /* Kor_hpp */
