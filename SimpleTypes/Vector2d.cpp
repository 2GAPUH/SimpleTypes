#include "Vector2d.h"
#include <iostream>

void Vector2d::PrintShort()
{
	std::cout << "{" <<  end.x - start.x << ", " << end.y - start.y << "}";
}

void Vector2d::PrintFull()
{
	std::cout << "{(" << start.x << ", " << start.y << "), (" << end.x << ", " << end.y << ")}";
}

float Vector2d::Value()
{
	return size;
}

IManagable* Vector2d::Copy()
{
	return new Vector2d(start, end);
}

bool Vector2d::IsEqual(IManagable* n)
{
	return size == n->Value();
}

Vector2d::Vector2d(Point2 start, Point2 end)
{
	this->start.x = start.x;
	this->start.y = start.y;
	this->end.x = end.x;
	this->end.y = end.y;
	size = std::sqrt((end.x - start.x) * (end.x - start.x) + (end.y - start.y) * (end.y - start.y));
}
