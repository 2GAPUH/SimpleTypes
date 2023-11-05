#pragma once

class ICopyable
{
public:
	virtual bool IsEqual(IManagable* n) = 0;
	virtual IManagable* Copy() = 0;
};

