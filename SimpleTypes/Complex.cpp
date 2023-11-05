#include "Complex.h"
#include <iostream>



void Complex::PrintShort()
{
	std::cout << "{" << main << " + " << sub << "i}";
}

void Complex::PrintFull()
{
	std::cout << "{" << main << " + " << sub << "i} & val = " << size;
}

float Complex::Value()
{
	return size;
}

IManagable* Complex::Copy()
{
	return new Complex(main, sub);
}

bool Complex::IsEqual(IManagable* n)
{
	return size == n->Value();
}

Complex::Complex(int main, int sub)
{
	this->main = main;
	this->sub = sub;
	size = std::sqrt(main * main + sub * sub);
}
