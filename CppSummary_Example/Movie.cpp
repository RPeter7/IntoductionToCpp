#include "pch.h"
#include "Movie.h"


Movie::Movie() : Media()
{
}


Movie::~Movie()
{
}

string Movie::toString() const
{
	return "Movie(" + Media::toSting() + ")";
}
