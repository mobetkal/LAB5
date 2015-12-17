#pragma once
#include <set>
#include "geometry.h"
#include "uniquegeometrylist.h"
#include <memory>
#include <functional>
#include <vector>

class GeometrySet
{

public:
	std::set<std::shared_ptr<Geometry>, std::function<bool(const std::shared_ptr<Geometry>&, const std::shared_ptr<Geometry>&)>> zbior;
	
	GeometrySet(UniqueGeometryList&& lista) :zbior((
		[](const std::shared_ptr<Geometry>& a, const std::shared_ptr<Geometry>& b)->bool
	{
		return (a->area() < b->area());
	}
	))
	{
		for (auto& elem : lista.lista)
		{
			zbior.insert(move(elem));
		}
	};
	
};