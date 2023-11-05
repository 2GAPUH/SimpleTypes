#include "Text.h"
#include <iostream>

void Text::PrintShort()
{
	if (size <= 10)
		std::cout << buf;
	else
		std::cout << buf[0] << buf[1] << buf[2] <<  "..." << buf[size - 3] << buf[size - 2] << buf[size - 1];
}

void Text::PrintFull()
{
	std::cout << buf << std::endl;
}

float Text::Value()
{
	return size;
}

IManagable* Text::Copy()
{
	return new Text(buf);
}

bool Text::IsEqual(IManagable* buf)
{
	return std::strcmp(this->buf, ((Text*)buf)->buf);
}

Text::Text(char* buf)
{
	std::strcpy(this->buf, buf);
	size = std::strlen(buf);
}
