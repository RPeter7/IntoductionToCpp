#pragma once
#include "ICategory.h"
#include "Media.h"

class Jorunal : public Media, public ICategory
{
public:
	Jorunal();
	~Jorunal();
	virtual Category getCategory() const;
	string toString() const;
};

