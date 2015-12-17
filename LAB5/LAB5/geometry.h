#pragma once
#include <iostream>
#include <cmath>
#include <string>

class Geometry
{
public:
	virtual float perimeter() const = 0;
	virtual float area() const = 0;
	virtual std::string toString() const = 0;

	~Geometry() {};
	Geometry() {};

};

class Triangle : public Geometry
{
	float a;
public:
	Triangle(float a) : a(a){};
	Triangle(Triangle& T) { a = T.a; };
	Triangle(Triangle&& T) { a = T.a; };
	float perimeter() const
	{
		return 3 * a;
	}

	float area() const
	{
		return a*a*sqrt(3) / 4;
	}
	std::string toString() const
	{
		return "Trojkat o boku a=" + std::to_string(a) + " ma obwod: " + std::to_string(perimeter()) + " i pole: " + std::to_string(area());
	}
};

class Circle : public Geometry
{
	float r;
public:
	Circle(float r) : r(r){};
	Circle(Circle& T) { r = T.r; };
	Circle(Circle&& T) { r = T.r; };
	float perimeter() const
	{
		return 2 * 3.14*r;
	}

	float area() const
	{
		return 3.14*r*r;
	}
	std::string toString() const
	{
		return "Okrag o promieniu r=" + std::to_string(r) + " ma obwod: " + std::to_string(perimeter()) + " i pole: " + std::to_string(area());
	}
};

class Rectangle : public Geometry
{
	float a;
	float b;
public:
	Rectangle(float a, float b) : a(a), b(b){};
	Rectangle(Rectangle& T) { a = T.a; b = T.b; };
	Rectangle(Rectangle&& T) { a = T.a; b = T.b; };
	float perimeter() const
	{
		return 2 * a + 2 * b;
	}

	float area() const
	{
		return a*b;
	}
	std::string toString() const
	{
		return "Prostokat o boku a=" + std::to_string(a) + " i b= " + std::to_string(b) + " ma obwod: " + std::to_string(perimeter()) + " i pole: " + std::to_string(area());
	}
};