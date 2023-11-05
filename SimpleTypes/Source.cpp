#include <iostream>
#include "Text.h"
#include "Vector2d.h"
#include "Vector3d.h"
#include "Complex.h"
#define BASE_SIZE 100

void Append(IManagable** array, int& type2, int& size)
{
	int main = 0, sub = 0;
	char buf[BUFFER_SIZE] = { NULL };
	Point2 startPoint1 = { 0, 0 };
	Point2 endPoint1 = { 0, 0 };
	Point3 startPoint = { 0, 0, 0 };
	Point3 endPoint = { 0, 0, 0 };

	switch (type2)
	{
	case 1:
		std::cout << "Enter main: ";
		std::cin >> main;
		std::cout << "Enter sub: ";
		std::cin >> sub;
		array[size++] = new Complex(main, sub);
		break;
	case 2:
		std::cout << "Enter message: ";
		while (getchar() != '\n');
		std::cin.getline(buf, BUFFER_SIZE);
		array[size++] = new Text(buf);
		break;
	case 3:
		std::cout << "Enter start x: ";
		std::cin >> startPoint1.x;
		std::cout << "Enter start y: ";
		std::cin >> startPoint1.y;
		std::cout << "Enter end x: ";
		std::cin >> endPoint1.x;
		std::cout << "Enter end y: ";
		std::cin >> endPoint1.y;
		array[size++] = new Vector2d(startPoint1, endPoint1);
		break;
	case 4:
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
		break;
	}
}

void Min(IManagable** array,  int& size)
{
	if (size > 0)
	{
		int minPos = 0;
		for (int i = 0; i < size; i++)
			if (array[i]->Value() < array[minPos]->Value())
				minPos = i;
		std::cout << "min = ";
		array[minPos]->PrintFull();
		std::cout << "\n";
	}
}

void Max(IManagable** array, int& size)
{
	if (size > 0)
	{
		int maxPos = 0;
		for (int i = 0; i < size; i++)
			if (array[i]->Value() > array[maxPos]->Value())
				maxPos = i;
		std::cout << "max = ";
		array[maxPos]->PrintFull();
		std::cout << "\n";
	}
}

void Find(IManagable** array, int& size)
{
	if (size > 0)
	{
		float buf = 0.;
		std::cout << "Enter value: ";
		std::cin >> buf;
		for (int i = 0; i < size; i++)
			if (buf == array[i]->Value())
			{
				std::cout << "Value found\n";
				return;
			}
		std::cout << "Value not found\n";
	}
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

float TotalSum()
{
	return 1;
}

int CountInRange()
{
	return 1;
}

void PrintPikes()
{

}

void MakeCopy()
{

}

void Join()
{

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

void PrintUnique()
{

}

int main()
{
	IManagable* text[BASE_SIZE] = { nullptr };
	IManagable* complex[BASE_SIZE] = { nullptr };
	IManagable* vector2d[BASE_SIZE] = { nullptr };
	IManagable* vector3d[BASE_SIZE] = { nullptr };
	int textSize = 0;
	int complexSize = 0;
	int vector2dSize = 0;
	int vector3dSize = 0;
	int type2 = 0;
	int type1 = 1;
	std::string instruction1 = "1 - Sort\n2 - Minimum value\n3 - Maximum value\n4 - Find value\n5 - Print line\n\
6 - Print column\n 7 - Total sum\n8 - Number in range\n9 - Print peaks\n10 - Make a copy\n11 - Append\n\
12 - Other add\n13 - Print unique\n0 - Exit\nEnter your choice: ";
	std::string instruction2 = "1 - Complex array \n2 - Text array \n3 - Vector2d array \n4 - Vector3d array \nEnter your choice: ";


	while (type1)
	{
		system("cls");
		std::cout << instruction2;
		std::cin >> type2;
		std::cout << instruction1;
		std::cin >> type1;

		switch (type1)
		{
		case 1:
			switch (type2)
			{
			case 1:
				Sort(complex, complexSize);
				break;
			case 2:
				Sort(text, textSize);
				break;
			case 3:
				Sort(vector2d, vector2dSize);
				break;
			case 4:
				Sort(vector3d, vector3dSize);
				break;
			}
			break;

		case 2:
			switch (type2)
			{
			case 1:
				Min(complex, complexSize);
				break;
			case 2:
				Min(text, textSize);
				break;
			case 3:
				Min(vector2d, vector2dSize);
				break;
			case 4:
				Min(vector3d, vector3dSize);
				break;
			}
			break;

		case 3:
			switch (type2)
			{
			case 1:
				Max(complex, complexSize);
				break;
			case 2:
				Max(text, textSize);
				break;
			case 3:
				Max(vector2d, vector2dSize);
				break;
			case 4:
				Max(vector3d, vector3dSize);
				break;
			}
			break;

		case 4:
			switch (type2)
			{
			case 1:
				Find(complex, complexSize);
				break;
			case 2:
				Find(text, textSize);
				break;
			case 3:
				Find(vector2d, vector2dSize);
				break;
			case 4:
				Find(vector3d, vector3dSize);
				break;
			}
			system("pause");
			break;

		case 5:
			switch (type2)
			{
			case 1:
				PrintLine(complex, complexSize);
				break;
			case 2:
				PrintLine(text, textSize);
				break;
			case 3:
				PrintLine(vector2d, vector2dSize);
				break;
			case 4:
				PrintLine(vector3d, vector3dSize);
				break;
			}
			system("pause");
			break;

		case 6:
			switch (type2)
			{
			case 1:
				PrintColumn(complex, complexSize);
				break;
			case 2:
				PrintColumn(text, textSize);
				break;
			case 3:
				PrintColumn(vector2d, vector2dSize);
				break;
			case 4:
				PrintColumn(vector3d, vector3dSize);
				break;
			}
			system("pause");
			break;

		case 7:
			switch (type2)
			{
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			}
			break;

		case 8:
			switch (type2)
			{
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			}
			break;

		case 9:
			switch (type2)
			{
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			}
			break;

		case 10:
			switch (type2)
			{
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			}
			break;

		case 11:
			switch (type2)
			{
			case 1:
				Append(complex, type2, complexSize);
				break;
			case 2:
				Append(text, type2, textSize);
				break;
			case 3:
				Append(vector2d, type2, vector2dSize);
				break;
			case 4:
				Append(vector3d, type2, vector3dSize);
				break;
			}
			break;

		case 12:
			switch (type2)
			{
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			}
			break;

		case 13:
			switch (type2)
			{
			case 1:
				break;
			case 2:
				break;
			case 3:
				break;
			case 4:
				break;
			}
			break;

		case 0:
			break;
		}
	}

	return 0;
}