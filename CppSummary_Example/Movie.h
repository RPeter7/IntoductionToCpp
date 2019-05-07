#pragma once
#include "Media.h"
class Movie :
	public Media
{
public:
	Movie();
	virtual ~Movie();
	string toString() const;
};

