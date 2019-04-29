
#include "pch.h"
#include "Complex.h"
#include <cmath>
#include <string>

Complex::Complex(double re_, double im_) :
	_re(re_),
	_im(im_)
{
}

Complex Complex::operator+(const Complex& rhs_) const
{
	Complex res(_re + rhs_._re, _im + rhs_._im);
	return res;
}

Complex operator+(const double& lhs_, const Complex& rhs_)
{
	Complex res(lhs_ + rhs_._re, rhs_._im);
	return res;
}

Complex& Complex::operator+=(const Complex& rhs_)
{
	_im += rhs_._im;
	_re += rhs_._re;
	return *this;
}

Complex Complex::operator-(const Complex& rhs_) const
{
	Complex res(_re - rhs_._re, _im - rhs_._im);
	return res;
}

Complex operator-(const double& lhs_, const Complex& rhs_)
{
	Complex res(lhs_ - rhs_._re, -rhs_._im);
	return res;
}

Complex& Complex::operator-=(const Complex& rhs_)
{
	_re -= rhs_._re;
	_im -= rhs_._im;
	return *this;
}

Complex Complex::operator*(const Complex& rhs_) const
{
	Complex res(_re * rhs_._re - _im * rhs_._im, _re * rhs_._im + _im * rhs_._re);
	return res;
}

Complex operator*(const double& lhs_, const Complex& rhs_)
{
	Complex res(lhs_ * rhs_._re, lhs_ * rhs_._im);
	return res;
}

Complex& Complex::operator*=(const Complex& rhs_)
{
	_re = _re * rhs_._re - _im * rhs_._im;
	_im = _re * rhs_._im + _im * rhs_._re;
	return *this;
}

Complex Complex::operator/(const Complex& rhs_) const
{
	double denominator = rhs_.abs();
	if (denominator == 0.0)
	{
		throw "Division by zero is not allowed";
	}
	Complex res((_re * rhs_._re + _im * rhs_._im) / denominator, (_im * rhs_._re - _re * rhs_._im) / denominator);
	return res;
}

Complex operator/(const double& lhs_, const Complex& rhs_)
{
	double denominator = rhs_.abs();
	if (denominator == 0.0)
	{
		throw "Division by zero is not allowed";
	}
	Complex res((lhs_ * rhs_._re) / denominator, -(lhs_ * rhs_._im) / denominator);
	return res;
}

Complex& Complex::operator/=(const Complex& rhs_)
{
	double denominator = rhs_.abs();
	if (denominator == 0.0)
	{
		throw "Division by zero is not allowed";
	}
	_re = (_re * rhs_._re + _im * rhs_._im) / denominator;
	_im = (_im + rhs_._re + _re * rhs_._im) / denominator;
	return *this;
}

bool Complex::operator==(const Complex& rhs_) const
{
	return _re == rhs_._re && _im == rhs_._im;
}

bool Complex::operator!=(const Complex& rhs_) const
{
	return !(*this == rhs_);
}

bool Complex::operator<(const Complex& rhs_) const
{
	return this->abs() < rhs_.abs();
}

bool Complex::operator<=(const Complex& rhs_) const
{
	return this->abs() <= rhs_.abs();
}

bool Complex::operator>(const Complex& rhs_) const
{
	return !(*this <= rhs_);
}

bool Complex::operator>=(const Complex& rhs_) const
{
	return !(*this < rhs_);
}

Complex Complex::operator!() const
{
	Complex res(_re, -_im);
	return res;
}

double Complex::abs() const
{
	return sqrt(_re * _re + _im * _im);
}

Complex::operator bool() const
{
	return _re || _im;
}

Complex::operator double() const
{
	return _re;
}

Complex Complex::pow(int n_) const
{
	double resR = ::pow(r(), n_);
	Complex res(resR * cos(phi() * n_), resR * sin(phi() * n_));
	return res;
}

Complex Complex::nthRoot(int n_) const
{
	double resR = ::pow(r(), 1.0 / n_);
	Complex res(resR * cos(phi() / n_), resR * sin(phi() / n_));
	return res;
}

std::ostream& operator<<(std::ostream& lhs_, const Complex& rhs_)
{
	std::string sep = rhs_._im < 0 ? "" : "+";
	lhs_ << rhs_._re << sep << rhs_._im << "*j";
	return lhs_;
}

std::istream& operator>>(std::istream& lhs_, Complex& rhs_)
{
	std::cout << "Re: ";
	lhs_ >> rhs_._re;
	std::cout << "Im: ";
	lhs_ >> rhs_._im;
	return lhs_;
}

double Complex::r() const
{
	return this->abs();
}

double Complex::phi() const
{
	return atan2(_re, _im);
}