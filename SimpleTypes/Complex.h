#pragma once
#include "IManagable.h"

class Complex : public IManagable
{
protected:
	int main = 0;
	int sub = 0;
	float size = 0.;

public:
	void PrintShort();
	void PrintFull();
	float Value();
	IManagable* Copy();
	bool IsEqual(IManagable* n);
	Complex(int main, int sub);
};

