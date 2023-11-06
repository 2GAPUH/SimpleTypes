#include "IManagable.h"
#include "Text.h"
#include "Vector2d.h"
#include "Vector3d.h"
#include "Complex.h"


void Append(IManagable** array, int& size, IManagable* element, int& position)
{
	if (position < 0 || position >= size)
		return;
	if (array[position] != 0)
		delete array[position];
	array[position] = element;



	/*
	{
		

		std::cout << "Enter start x: ";
		std::cin >> startPoint1.x;
		std::cout << "Enter start y: ";
		std::cin >> startPoint1.y;
		std::cout << "Enter end x: ";
		std::cin >> endPoint1.x;
		std::cout << "Enter end y: ";
		std::cin >> endPoint1.y;
		array[size++] = new Vector2d(startPoint1, endPoint1);

		std::cout << "Enter start x: ";
		std::cin >> startPoint.x;
		std::cout << "Enter start y: ";
		std::cin >> startPoint.y;
		std::cout << "Enter start z: ";
		std::cin >> startPoint.z;
		std::cout << "Enter end x: ";
		std::cin >> endPoint.x;
		std::cout << "Enter end y: ";
		std::cin >> endPoint.y;
		std::cout << "Enter end z: ";
		std::cin >> endPoint.z;
		array[size++] = new Vector3d(startPoint, endPoint);

	}*/
}

int Min(IManagable** array, int& size)
{
	if (size > 0)
	{
		int minPos = 0;
		for (int i = 0; i < size; i++)
			if (array[i]->Value() < array[minPos]->Value())
				minPos = i;
		return minPos;
	}
	return -1;
}

int Max(IManagable** array, int& size)
{
	if (size > 0)
	{
		int maxPos = 0;
		for (int i = 0; i < size; i++)
			if (array[i]->Value() > array[maxPos]->Value())
				maxPos = i;
		return maxPos;
	}
	return -1;
}

int Find(IManagable** array, int& size, float& val)
{
	if (size > 0)
	{
		for (int i = 0; i < size; i++)
			if (val == array[i]->Value())
			{
				return i;
			}
	}
	return -1;
}

void PrintLine(IManagable** array, int& size)
{
	if (size > 0)
	{
		for (int i = 0; i < size;i++)
		{
			array[i]->PrintShort();
			std::cout << ", ";
		}
		std::cout << "\b\b  ";
		std::cout << "\n";
	}
}


void PrintColumn(IManagable** array, int& size)
{
	if (size > 0)
	{
		for (int i = 0; i < size;i++)
		{
			array[i]->PrintFull();
			std::cout << "\n";
		}
	}
}

float TotalSum(IManagable** array, int& size)
{
	if (size > 0)
	{
		float totalsum = 0.;
		for (int i = 0; i < size;i++)
			totalsum += array[i]->Value();
		return totalsum;
	}
	return ERROR;
}

int CountInRange(IManagable** array, int& size, float leftBoard, float rightBoard)
{
	if (size > 0)
	{
		int count = 0;
		for (int i = 0; i < size; i++)
			if (array[i]->Value() > leftBoard && array[i]->Value() < rightBoard)
				count++;
		return count;
	}
	return -1;
}

void PrintPikes(IManagable** array, int& size)
{
	if (size > 1)
	{
		bool direction = true;
		for (int i = 1; i < size; i++)
		{
			if (array[i - 1]->Value() > array[i]->Value() && direction)
			{
				std::cout << array[i - 1]->Value() << " ";
				direction = false;
			}
			else if (array[i - 1]->Value() < array[i]->Value() && !direction)
			{
				std::cout << array[i - 1]->Value() << " ";
				direction = true;
			}
		}
		
		if (array[size - 2]->Value() > array[size - 1]->Value() && direction)
		{
			std::cout << array[size - 1]->Value() << " ";
		}
		else if (array[size - 2]->Value() < array[size - 1]->Value() && !direction)
		{
			std::cout << array[size - 1]->Value() << " ";
		}
	}
}
IManagable** MakeCopy(IManagable** array, int& size)
{
	if (size > 0)
	{
		IManagable** tmpArray = { nullptr };
		tmpArray = new IManagable * [BASE_SIZE];
		for (int i = 0; i < size;i++)
		{
			tmpArray[i] = array[i]->Copy();
		}

		return tmpArray;
	}
}

void Join(IManagable** &array1, IManagable** &array2, int& size1, int& size2)
{
	if (size1 > 1 && size2 > 1)
	{
		array1 = (IManagable**)realloc(array1, sizeof(IManagable*) * (size1 + size2));
		

		for (int i = 0; i < size2;i++)
			array1[size1 + i] = array2[i]->Copy();
		size1 += size2;
	}
}

void Sort(IManagable** array, int& size)
{
	if (size > 0)
	{
		IManagable* tmp = nullptr;
		for (int i = size - 1; i >= 0; i--)
		{
			for (int j = 0; j < i; j++)
			{
				if (array[j]->Value() > array[j + 1]->Value())
				{
					tmp = array[j];
					array[j] = array[j + 1];
					array[j + 1] = tmp;
				}
			}
		}
	}
}

void PrintUnique(IManagable** array, int& size)
{
	if (size > 0)
	{
		for (int i = 0; i < size; i++)
		{
			bool tmp = 1;
			for (int j = 0; j < size; j++)
				if (array[i]->Value() == array[j]->Value() && i != j)
				{
					tmp = 0;
					break;
				}
			if (tmp)
				std::cout << "Unique: " << array[i]->Value() << "\n";
		}
	}
}