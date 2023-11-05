#include "Vector3d.h"
#include <iostream>

void Vector3d::PrintShort()
{
	std::cout << "{" << end.x - start.x << ", " << end.y - start.y << ", " << end.z - start.z << "}";
}

void Vector3d::PrintFull()
{
	std::cout << "{(" << start.x << ", " << start.y << ", " << start.z << "), (" << end.x << ", " << end.y << ", " << end.z << ")}";
}

float Vector3d::Value()
{
	return size;
}

IManagable* Vector3d::Copy()
{
	return new Vector3d(start, end);
}

bool Vector3d::IsEqual(IManagable* n)
{
	return size == n->Value();
}

Vector3d::Vector3d(Point3 start, Point3 end)
{
	this->start.x = start.x;
	this->start.y = start.y;
	this->start.z = start.z;
	this->end.x = end.x;
	this->end.y = end.y;
	this->end.z = end.z;
	size = std::sqrt((end.x - start.x) * (end.x - start.x) + (end.y - start.y) * (end.y - start.y) + (end.z - start.z) * (end.z - start.z));
}
