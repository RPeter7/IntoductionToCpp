#include "pch.h"
#include "Media.h"

int Media::ID_COUNTER = 0; //itt kell a statikus inicalizalas

Media::Media()
{
	_myID = ID_COUNTER++;
}


Media::~Media()
{
}

int Media::getID() const
{
	return _myID;
}

string Media::toSting() const
{
	return to_string(_myID);
}

void Media::setLocation(Storage* location_)
{
	_location = location_;
}
