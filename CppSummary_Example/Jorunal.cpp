#include "pch.h"
#include "Jorunal.h"


Jorunal::Jorunal() : Media(), ICategory(Scientific)
{
}


Jorunal::~Jorunal()
{
}

Category Jorunal::getCategory() const
{
	return _category;
}

string Jorunal::toString() const
{
	return "Journal(" + Media::toSting() + ")";
}
