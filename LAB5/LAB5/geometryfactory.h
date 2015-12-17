#pragma once
#include "geometry.h"
#include <sstream>

class GeometryFactory
{
	
public:
	static Geometry* create(std::string nazwa){
		std::istringstream sent(nazwa);
		std::string name;
		sent >> name;
		if (name == "circle")
		{
			float r;
			sent >> r;
			return new Circle(r);
		}
		else if (name == "triangle")
		{
			float a;
			sent >> a;
			return new Triangle(a);
		}
		else if (name == "rectangle")
		{
			float a, b;
			sent >> a;
			sent >> b;
			return new Rectangle(a, b);
		}
	}
};
