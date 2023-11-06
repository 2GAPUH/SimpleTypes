#pragma once
#include "ICopyable.h"
#include "IValue.h"
#include "IPrintable.h"
#include <iostream>
#include "Point.h"

#define BASE_SIZE 100
#define BUFFER_SIZE 100
#define ERROR 1.123123123124


class IManagable : public ICopyable, public IValue, public IPrintable {};

void Append(IManagable** array, int& size, IManagable* element, int& position);
int Min(IManagable** array, int& size);
int Max(IManagable** array, int& size);
int Find(IManagable** array, int& size, float& val);
void PrintLine(IManagable** array, int& size);
void PrintColumn(IManagable** array, int& size);
float TotalSum(IManagable** array, int& size);
int CountInRange(IManagable** array, int& size, float leftBoard, float rightBoard);
void PrintPikes(IManagable** array, int& size);
IManagable** MakeCopy(IManagable** array, int& size);
void Join(IManagable**& array1, IManagable**& array2, int& size1, int& size2);
void Sort(IManagable** array, int& size);
void PrintUnique(IManagable** array, int& size);