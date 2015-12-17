#include <iostream>
#include "geometry.h"
#include "geometryfactory.h"
#include "uniquegeometrylist.h"
#include "geometryset.h"

using namespace std;

void main()
{
	Triangle test1(10.0f);
	Circle test2(10.0f);
	Rectangle test3(10.0f, 10.0f);
	cout << test1.toString() << endl;
	cout << test2.toString() << endl;
	cout << test3.toString() << endl;
	GeometryFactory test4;
	auto P1 = test4.create("circle 5");
	cout << P1->toString() << endl;
	GeometryFactory test5;
	auto P2 = test5.create("triangle 2.4");
	cout << P2->toString() << endl;
	GeometryFactory test6;
	auto P3 = test6.create("rectangle 3 10");
	cout << P3->toString() << endl;
	string name = "plik.txt";
	UniqueGeometryList lista(name);
	cout << "------------------------------------------------------------\n";
	GeometrySet test7(move(lista));
	for (auto& elem : test7.zbior)
		cout << elem->toString() << endl;

	std::vector<std::weak_ptr<Geometry>> wektor;
	for (auto& elem : test7.zbior)
	{
		wektor.push_back(elem);
		
	}
	test7.zbior.erase(test7.zbior.begin());
	for (auto aktywny : wektor)
	{
		if (shared_ptr<Geometry> s2 = aktywny.lock()) {
			cout << s2->toString() << endl;
		}
		else {
			cout << "Obiekt nie istnieje" << endl;
		}
	}
	
	system("PAUSE");
}