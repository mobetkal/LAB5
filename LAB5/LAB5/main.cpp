#include <iostream>
#include "geometry.h"
#include "geometryfactory.h"

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
	system("PAUSE");
}