#include "pch.h"
#include "Complex.h"

Complex::Complex(double re_, double im_) :
	_re(re_),
	_im(im_)
{
}

std::string Complex::toString() const
{
	return std::to_string(_re) + (_im < 0 ? "" : "+") + std::to_string(_im) + "j";
}

Complex Complex::operator+(const Complex& rhs_) const
{
	return Complex(this->_re + rhs_._re, this->_im + rhs_._im);
}

Complex Complex::operator+(const double& rhs_) const
{
	return Complex(_re + rhs_, _im);
}

Complex& Complex::operator+=(const Complex& rhs_)
{
	_re += rhs_._re;
	_im += rhs_._im;
	return *this;
}
//Complex::~Complex()
//{
//}

Complex operator+(const double & lhs_, const Complex & rhs_)
{
	return Complex(lhs_ + rhs_._re, rhs_._im);
}

std::ostream & operator<<(std::ostream & lhs_, const Complex & rhs_)
{
	//return lhs_ << rhs_.toString();
	/*lhs_ << std::to_string(rhs_._re);
		 << (std::to_string(rhs_._im)*/
	return lhs_;
}

std::istream & operator>>(std::istream & lhs_, Complex & rhs_)
{
	/*std::cout << "Re: ";
	std::cin >> rhs_._re;
	std::cout << "Im: ";
	std::cin >> rhs_._im;*/
	return lhs_;
}

