#include "pch.h"
#include <iostream>
#include "ICategory.h"
#include "Media.h"
#include "EBook.h"
#include <map>
#include <vector>

using namespace std;

map<int, ICategory*> collectHasCategory(vector<Media*> v)
{
	map<int, ICategory*> m;
	for (vector<Media*>::const_iterator it = v.begin(); it != v.end(); it++)
	{
		if (ICategory* cat = dynamic_cast<ICategory*>(*it))
		{
			m[(*it)->getID()] = cat;
		}
	}

	return m;
}

int main()
{
	vector<Media*> mediaVector;
	mediaVector.push_back(new EBook(Crime));
	mediaVector.push_back(new EBook(Professional));
	for (vector<Media*>::const_iterator it = mediaVector.begin(); it != mediaVector.end(); it++)
	{
		cout << (*it)->toSting() << endl;
		if (ICategory* cat = dynamic_cast<ICategory*>(*it))
		{
			cout << cat->getCategory() << endl;
		}
	}

	map<int, ICategory*> m = collectHasCategory(mediaVector);
	for (map<int, ICategory*>::iterator it = m.begin(); it != m.end(); it++)
	{
		cout << it->first << it->second->getCategory() << endl;
	}
		

	for (vector<Media*>::const_iterator it = mediaVector.begin(); it != mediaVector.end(); it++)
	{
		delete *it;
	}















	/*Media* m1 = new EBook(Crime);
	cout << m1->getID() << endl;
	EBook* m2 = new EBook(Historical);
	cout << m2->getID() << endl;
	delete m1;
	delete m2;*/

	/*int apad = 2;
	int* ptr = &apad;
	int& refAnyad = *ptr;

	*ptr = 3;

	std::cout << "PTR:" << *ptr << "  APAD:" << apad << "  ANYAD:" << refAnyad <<std::endl; */



}