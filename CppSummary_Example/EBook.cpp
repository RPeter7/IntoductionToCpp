#include "pch.h"
#include "EBook.h"





EBook::EBook(Category category_) : Media()
{
	_category = category_;
}

EBook::~EBook()
{
}

Category EBook::getCategory() const
{
	return _category;
}

string EBook::toString() const
{
	return "EBook(" + Media::toSting() + ")";
}
