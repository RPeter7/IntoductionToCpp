#pragma once
#include <string>

enum Category
{
	Crime, Historical, Professional, Scientific
};

class ICategory
{
public:
	ICategory();
	ICategory(const Category& category_);
	virtual ~ICategory();
	virtual Category getCategory() const = 0;
protected:
	Category _category;
};

