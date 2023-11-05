#pragma once
#include "IManagable.h"
#include "Point.h"

class Vector3d : public IManagable
{
	Point3 start = { 0, 0, 0 };
	Point3 end = { 0 ,0, 0 };
	float size = 0.;

public:
	void PrintShort();
	void PrintFull();
	float Value();
	IManagable* Copy();
	bool IsEqual(IManagable* n);
	Vector3d(Point3 start, Point3 end);
};

