#pragma once
#include <list>
#include "geometry.h"
#include <memory>
#include <fstream>
#include <conio.h>
#include "geometryfactory.h"

class UniqueGeometryList
{
public:
	std::list<std::unique_ptr<Geometry>> lista;
	UniqueGeometryList(const std::string fileName)
	{
		std::ifstream file;
		file.open(fileName);
		std::string line;
		if (file.good())
		{
			while (!file.eof())
			{
				std::getline(file, line);
				lista.emplace_back(GeometryFactory::create(line));
			}
		}
		else
		{
			std::cout << "Plik nie został otwarty prawidłowo." << std::endl;
			return;
		}
	};
};