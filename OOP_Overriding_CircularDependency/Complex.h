#pragma once
#include <string>
class Complex
{
public:
	Complex(double re_ = 0.0, double im_ = 0.0); //Default param�ter. Ezzel lehet t�bb param�terest l�tre hozni!!
	std::string toString() const;
	Complex operator+(const Complex& rhs_) const; //Mndig gondold v�gig, hogy const-e!!
	Complex operator+(const double& rhs_) const;
	Complex& operator+=(const Complex& rhs_); //nem kell v�g�re const, mert v�ltoztatja
	friend Complex operator+(const double& lhs_, const Complex& rhs_); //a friend miatt el�ri a priv�t adattagokat!!
	friend std::ostream& operator<< (std::ostream& lhs_, const Complex& rhs_);
	friend std::istream& operator>> (std::istream& lhs_, Complex& rhs_);
	/*~Complex();*/ //Nem fog kelleni! 
private:
	double _re;
	double _im;
};