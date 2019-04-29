#pragma once
#ifndef Sikidom_hpp
#define Sikidom_hpp

#include <string>
#include <iostream>

class Sikidom
{
public:
	Sikidom(const std::string& szin_);
	virtual ~Sikidom();
	void kilyukaszt();
	virtual double kerulet() const = 0;
	virtual double terulet() const = 0;
	friend std::ostream& operator<<(std::ostream&, Sikidom* const);
protected:
	virtual std::string toString() const;

private:
	bool _lyukas;
	std::string _szin;
protected:
	mutable double cachedKerulet = 0.0;
	mutable double cachedTerulet = 0.0;
};

#endif /* Sikidom_hpp */
