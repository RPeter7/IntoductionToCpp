#pragma once
#include <string>
#include "Storage.h"

using namespace std;

class Media
{
public:
	Media();
 	virtual ~Media();
	int getID() const;
	virtual string toSting() const;
	void setLocation(Storage* location_);

private:
	static int ID_COUNTER; //Static miatt nem lehet itt inicializalni, ezert .cpp-ben adunk erteket neki.
	Storage* _location;

protected:
	int _myID;
};

