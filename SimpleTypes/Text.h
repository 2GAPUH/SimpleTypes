#pragma once
#include "IManagable.h"
#define BUFFER_SIZE 1000

class Text :public IManagable
{
protected:
	char buf[BUFFER_SIZE] = {0};
	int size = 0;

public:
	void PrintShort();
	void PrintFull();
	float Value();
	IManagable* Copy();
	bool IsEqual(IManagable* n);
	Text(char* buf);
};

