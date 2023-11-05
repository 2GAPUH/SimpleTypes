#pragma once
#include "IManagable.h"
#include "Point.h"

class Vector2d : public IManagable
{
	Point2 start = { 0, 0 };
	Point2 end = { 0 ,0 };
	float size = 0.;

public:
	void PrintShort();
	void PrintFull();
	float Value();
	IManagable* Copy();
	bool IsEqual(IManagable* n);
	Vector2d(Point2 start, Point2 end);
};

