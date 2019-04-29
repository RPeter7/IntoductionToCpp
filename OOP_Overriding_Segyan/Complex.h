#pragma once
#include "pch.h"
#ifndef Complex_hpp
#define Complex_hpp

#include <iostream>

class Complex
{
public:
	Complex(double re_ = 0.0, double im_ = 0.0);

	Complex operator+(const Complex& rhs_) const;
	friend Complex operator+(const double& lhs_, const Complex& rhs_);
	Complex& operator+=(const Complex& rhs_);
	Complex operator-(const Complex& rhs_) const;
	friend Complex operator-(const double& lhs_, const Complex& rhs_);
	Complex& operator-=(const Complex& rhs_);
	Complex operator*(const Complex& rhs_) const;
	friend Complex operator*(const double& lhs_, const Complex& rhs_);
	Complex& operator*=(const Complex& rhs_);
	Complex operator/(const Complex& rhs_) const;
	friend Complex operator/(const double& lhs_, const Complex& rhs_);
	Complex& operator/=(const Complex& rhs_);

	bool operator==(const Complex& rhs_) const;
	bool operator!=(const Complex& rhs_) const;
	bool operator<(const Complex& rhs_) const;
	bool operator<=(const Complex& rhs_) const;
	bool operator>(const Complex& rhs_) const;
	bool operator>=(const Complex& rhs_) const;

	Complex operator!() const;

	double abs() const;
	Complex pow(int n_) const;
	Complex nthRoot(int n_ = 2) const;

	operator bool() const;
	operator double() const;

	friend std::ostream& operator<<(std::ostream& lhs_, const Complex& rhs_);
	friend std::istream& operator>>(std::istream& lhs_, Complex& rhs_);

private:
	double r() const;
	double phi() const;

private:
	double _re;
	double _im;
};

#endif /* Complex_hpp */
