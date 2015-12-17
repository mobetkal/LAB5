#include <iostream>
#include "geometry.h"

using namespace std;

void main()
{
	Triangle test1(10.0f);
	Circle test2(10.0f);
	Rectangle test3(10.0f, 10.0f);
	cout << test1.toString() << endl;
	cout << test2.toString() << endl;
	cout << test3.toString() << endl;
	system("PAUSE");
}