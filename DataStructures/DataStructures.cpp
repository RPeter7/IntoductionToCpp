  #include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <list>

#include <deque> 
#include <queue>
#include <stack>
#include <set>
#include <unordered_set>
#include <map>
#include <unordered_map> 

using namespace std;

int main()
{



	//map<char, double> gyakorisag;
	//gyakorisag.emplace(pair<char,double>('a', 1));
	//gyakorisag.emplace(pair<char, double>('q', 34));
	//gyakorisag.emplace(pair<char, double>('e', 3));
	//gyakorisag.emplace(pair<char, double>('c', 2));
	//gyakorisag.emplace(pair<char, double>('p', 0));


	//gyakorisag['a'] = 3;

	//for (map<char,double>::iterator it = gyakorisag.begin(); it != gyakorisag.end(); it++)
	//{
	//	pair<char, double> aktualiPar = *it;
	//	cout << aktualiPar.first <<  ": " << aktualiPar.second << endl;
	//}






	//set<double> s1; //Nincsen ismetlodes. nem engedi a duplikalt dolgokat. RENDEZETT MINDIG.
	//s1.emplace(3.9);
	//s1.erase(3.9);





	//stack<double> s; //felul teszed be, felul szeded ki.
	//s.push(2.3);
	//s.top(); //torles
	//s.pop(); //lefgelso elem
	//s.empty(); //ures-e







	//queue<double> q; //egy helyen be, masik helyen ki.
	//q.push(1.0);
	//q.pop();

	//priority_queue<double> pq;
	//pq.push(1.0); //nem biztos h a vegere kerul
	//pq.pop(); //legnagyobb prioritasu elem jon ki.











	//std::deque<double> dq; //ketvegu sor. //ha csak az elejet meg veget akarom hasznalni akkor erdemes ezt hasznalni.

	//dq.push_back(4.5);
	//dq.push_front(2.5);

	//dq.pop_back();
	//dq.pop_front();

	//dq.back();
	//dq.front();







	//list<double> l; //ketiranyu lancolt lista --> nincs positionje.

	//find(l.begin(), l.end(), 1.5); //ugyan az mit lejjebb










	//std::vector<double> v; //osszefuggo memoriateruleten van, ezert gyorsan el lehet erni vmit.
	//v.size(); //Hany elem van a vektorba

	////std::cout << v.size() << ", " << v.capacity() << std::endl; 

	//v.push_back(4.5); //Vektor vegere szurunk be.
	//v.push_back(3.4);
	//v.push_back(1.4);
	//v.push_back(3.2);
	//v.push_back(6.2);

	////std::cout << v.size() << ", " << v.capacity() << std::endl; //valojaban mennyi helyet foglaluink le a memoriaba.

	//v.back(); //legutolso elem a vektorba.
	//v.front(); //legelso elem. //Ezekre referenciat ad vissza!!!! 

	//v.insert(v.begin() + 2, 0.0);
	//v.erase(v.begin() + 2);

	////std::cout << v.size() << ", " << v.capacity() << std::endl; 

	////v.clear(); //torli az osszes elemet, de a memoriat nem szabaditja fel.
	////v.resize(0); //csak a valadi tarolt meretet allitja. //torles utan. //torles elott:  eltunnek az elemeim de ott maradnak a memoriaba.
	////v.shrink_to_fit(); //ha azt akarom h a capacity egyenlo legyen a sizeal


	////std::cout << v.size() << ", " << v.capacity() << std::endl; 

	///*for (std::vector<double>::const_iterator it = v.begin(); it != v.end(); it++)
	//{
	//	std::cout << *it << std::endl;
	//}*/

	////for (std::vector<double>::reverse_iterator it = v.rbegin(); it != v.rend(); it++) //ez a hatulrol bejaras.
	////{
	////	std::cout << *it << std::endl;
	////}

	////for (std::vector<double>::const_iterator it = v.cbegin(); it != v.cend(); it++) //const iteratornal ezt kene haszalni, cend, cbegin
	////{
	////	std::cout << *it << std::endl;
	////}

	////for (std::vector<double>::const_reverse_iterator it = v.crbegin(); it != v.crend(); it++)
	////{
	////	std::cout << *it << std::endl;
	////}

	// std::vector<double>::iterator result = std::find(v.begin(), v.end(), 1.4);
	// if (result != v.end()) // ha nem taaljha meg a find, utolso elemmel ter vissza.
	// {
	//	 cout << *result << endl;
	// }
	// 
	// std::vector<double>::iterator maxIterator = max_element(v.begin(), v.end());

	// cout << *maxIterator << std::endl;

}