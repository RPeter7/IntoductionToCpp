#include <iostream>
#include "pch.h"
#include <iostream>
#include <vector>
#include "Sikidom.h"
#include "Kor.h"
#include "Teglalap.h"
#include "Negyzet.h"

//Származtatás: Publicus szárm nál: ugyan az mint a sima. Általában ezt használjuk, csak ezt használjuk... MINDIG KI KELL IRNI!
//				Protected: public -> protected a többi marad
//				Private: Minden private lesz

// C++ ban VAN TÖBBSZÖRÖS ÖRÖKLÕDÉS!! (Bármennyi lehet)
// class Manager : public Employee, public Investor...
//Ne használjuk!! 
//Ha mind ket Õsben van egy F() akkor Employee:F(), hogy melyiket használja
//Kötelezõ õs konstruktort hívni.
//Olyan sorrendben kell peldanyositani ahogy felsoroltam az õsöket!!
//Employee e = Manager("Boss", "HQ", 5) Ez itt copyconstruktor (stacken vagyunk) Managerbol csinalnunk employeet vagyis eltunik a level. (adatvesztes)
//Itt nem tortenik semmi a levellel (5)
//Fenti helyett: Employee* e = new Manager("Boss", "HQ", 5); Heapen lesz managerem employee resszel. e meg ramutat a manager e jere. De megint nem érem el a levelt
// Majd kasztolással fogjuk elérni (mint c# ban!)
//törléesnel a destruktornál kell majd mókolni!
//virtual metodus tabla MEGNEZNI!
//csak azok az osztalyok kasztolhatok az osse amelyek bentvannak a vmtbe!! depstruktort tegyuk virtualissa (hava van virt met akkor bekerul a vmtbe)
//csak a headerben kell virtualisnak jelolni!
//pure virtual = abstract in C# virtual void rotate(int) (ha van const ide irjatjuk) = 0;
// Ha egy osztálynak van pure virtual methodja akkor az egy absztrakt class lesz!! (Ugye nem lehet peldanyositani)
//Nincs interface de lehet hasnolnot csinalni = csak header file es pure virtual methodokat hasznalunk!!
//castolas: dynamic_cast<MIVE*> *gga kasztolom, ha amirol kasztolom az *os!

void Kilyukaszt(std::vector<Sikidom*> sikidomok_)
{
	for (std::vector<Sikidom*>::iterator it = sikidomok_.begin(); it != sikidomok_.end(); ++it)
	{
		if ((*it)->terulet() > (*it)->kerulet())
		{
			(*it)->kilyukaszt();
		}
	}
}

Teglalap* UjTeglalap(const std::string& szin_, double magassag_, double szelesseg_ = -1.0)
{
	if (szelesseg_ == -1.0)
	{
		return new Negyzet(szin_, magassag_);
	}
	else
	{
		return new Teglalap(szin_, magassag_, szelesseg_);
	}
}

Sikidom* LegnagyobbTeruletu(const std::vector<Sikidom*> sikidomok_)
{
	Sikidom* maxTeruletuSikidom = sikidomok_[0];
	double maxTerulet = maxTeruletuSikidom->terulet();
	for (std::vector<Sikidom*>::const_iterator it = sikidomok_.begin() + 1; it != sikidomok_.end(); ++it)
	{
		double aktTerulet = (*it)->terulet();
		if (aktTerulet > maxTerulet)
		{
			maxTeruletuSikidom = *it;
			maxTerulet = aktTerulet;
		}
	}
	return maxTeruletuSikidom;
}

int main()
{
	//Kor teszt
//    Sikidom* s1 = new Kor("piros", 3.0);
//    std::cout << s1;
//    if (Kor* k1 = dynamic_cast<Kor*>(s1))
//    {
//        k1->setSugar(4.0);
//        std::cout << "Modositott sugar: " << std::to_string(k1->getSugar()) << std::endl;
//    }
//    delete s1;

	//Teglalap teszt
//    Sikidom* s2 = new Teglalap("kek", 2.0, 4.5);
//    std::cout << s2;
//    if (Teglalap* t1 = dynamic_cast<Teglalap*>(s2))
//    {
//        t1->setMagassag(2.5);
//        t1->setSzelesseg(4.0);
//        std::cout << "Modositott magassag: " << std::to_string(t1->getMagassag()) + ", szelesseg: " + std::to_string(t1->getSzelesseg()) << std::endl;
//    }
//    delete s2;

	//Negyzet teszt
//    Sikidom* s3 = new Negyzet("zold", 2.5);
//    std::cout << s3;
//    if (Negyzet* n1 = dynamic_cast<Negyzet*>(s3))
//    {
//        n1->setMagassag(2.0);
//        std::cout << "Modositott magassag: " << std::to_string(n1->getMagassag()) << ", szelesseg: " << std::to_string(n1->getSzelesseg()) << std::endl;
//        n1->setSzelesseg(3.5);
//        std::cout << "Modositott szelesseg: " << std::to_string(n1->getSzelesseg()) << ", magassag: " << std::to_string(n1->getMagassag()) << std::endl;
//    }
//    delete s3;

	std::vector<Sikidom*> sikidomok;
	sikidomok.push_back(new Kor("piros", 3.0));
	sikidomok.push_back(new Teglalap("kek", 2.0, 3.4));
	sikidomok.push_back(new Negyzet("sarga", 1.2));
	sikidomok.push_back(UjTeglalap("fekete", 3.1, 1.9));
	sikidomok.push_back(UjTeglalap("feher", 1.3));

	Kilyukaszt(sikidomok);

	for (std::vector<Sikidom*>::iterator it = sikidomok.begin(); it != sikidomok.end(); ++it)
	{
		std::cout << *it;
	}

	std::cout << "Legnagyobb teruletu sikidom: " << LegnagyobbTeruletu(sikidomok);

	for (std::vector<Sikidom*>::iterator it = sikidomok.begin(); it != sikidomok.end(); ++it)
	{
		delete *it;
	}
}
