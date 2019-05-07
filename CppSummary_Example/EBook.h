#pragma once
#include "Media.h"
#include "ICategory.h"
#include <string>

class EBook :
	public Media, public ICategory
{
public:
	EBook(Category);
	virtual ~EBook();
	virtual Category getCategory() const;
	string toString() const;
};

