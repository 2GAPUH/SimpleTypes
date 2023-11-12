#include "IManagable.h"
#include <iostream>
#include "Text.h"
#include "Vector2d.h"
#include "Vector3d.h"
#include "Complex.h"

void SetElement(int& type, IManagable** array, int& arraySize, int& pos)
{
	char buf[BUFFER_SIZE] = { 0 };
	int tmp1, tmp2;
	Point2 startPoint2 = { 0, 0 };
	Point2 endPoint2 = { 0, 0 };
	Point3 startPoint3 = { 0, 0, 0 };
	Point3 endPoint3 = { 0, 0, 0 };


	switch (type)
	{
	case 1:
		std::cout << "Enter main: ";
		std::cin >> tmp1;
		std::cout << "Enter sub: ";
		std::cin >> tmp2;

		Append(array, arraySize, (IManagable*)(new Complex(tmp1, tmp2)), pos);
		break;

	case 2:
		while (getchar() != '\n');
		std::cout << "Enter message: ";
		std::cin.getline(buf, BUFFER_SIZE);
		Append(array, arraySize, (IManagable*)(new Text(buf)), pos);
		break;

	case 3:
		std::cout << "Enter start x: ";
		std::cin >> startPoint2.x;
		std::cout << "Enter start y: ";
		std::cin >> startPoint2.y;
		std::cout << "Enter end x: ";
		std::cin >> endPoint2.x;
		std::cout << "Enter end y: ";
		std::cin >> endPoint2.y;
		Append(array, arraySize, (IManagable*)(new Vector2d(startPoint2, endPoint2)), pos);
		break;

	case 4:
		std::cout << "Enter start x: ";
		std::cin >> startPoint3.x;
		std::cout << "Enter start y: ";
		std::cin >> startPoint3.y;
		std::cout << "Enter start z: ";
		std::cin >> startPoint3.z;
		std::cout << "Enter end x: ";
		std::cin >> endPoint3.x;
		std::cout << "Enter end y: ";
		std::cin >> endPoint3.y;
		std::cout << "Enter end z: ";
		std::cin >> endPoint3.z;
		Append(array, arraySize, (IManagable*)(new Vector3d(startPoint3, endPoint3)), pos);
		break;
	}
}

void FillArray(int& arraySize, int& type, IManagable** array)
{
	while (getchar() != '\n');
	for (int i = 0; i < arraySize; i++)
	{
		SetElement(type, array, arraySize, i);
	}
}

int main()
{
	IManagable** array = { nullptr };
	IManagable** tmpArray = { nullptr };
	int arraySize = 0;
	int type = 0;
	int action = 1;
	float tempF1 = 0.0;
	int tempI1 = 0;
	int tempI2 = 0;
	int tempI3 = 0;

	std::string instruction1 = "1 - Sort\n2 - Minimum value\n3 - Maximum value\n4 - Find value\n5 - Print line\n\
6 - Print column\n7 - Total sum\n8 - Number in range\n9 - Print peaks\n10 - Make a copy\n11 - Append\n\
12 - Join\n13 - Print unique\n0 - Exit\nEnter your choice: ";
	std::string instruction2 = "1 - Complex array \n2 - Text array \n3 - Vector2d array \n4 - Vector3d array \nEnter your choice: ";
	std::string instruction3 = "1 - Add new element \n0 - Exit \nEnter your choice: ";

	while (true)
	{
		std::cout << instruction2;
		std::cin >> type;
		if (type > 0 && type < 5) break;
		std::cout << "Invalid value!\n";
	}
	
	while(true)
	{
		std::cout << "Enter array size: ";
		std::cin >> arraySize;
		if (arraySize > 1 && arraySize < 100) break;
		std::cout << "Invalid value\n";
	}

	array = new IManagable * [arraySize] {0};

	FillArray(arraySize, type, array);

	while (action)
	{
		system("cls");
	
		std::cout << instruction1;
		std::cin >> action;

		switch (action)
		{
		case 1:
			Sort(array, arraySize);
			break;

		case 2:
			tempI1 = Min(array, arraySize);
			if (tempI1 > 0)
			{
				std::cout << "min = ";
				array[tempI1]->PrintFull();
				std::cout << "\n";
			}
			break;
			
		case 3:
			tempI1 = Max(array, arraySize);
			if (tempI1 > 0)
			{
				std::cout << "max = ";
				array[tempI1]->PrintFull();
				std::cout << "\n";
			}
			break;
			
		case 4:
			std::cout << "Enter value: ";
			std::cin >> tempF1;
			tempI1 = Find(array, arraySize, tempF1);
			if (tempI1 > 0)
				std::cout << "Position in array: " << tempI1 << "\n";
			else
				std::cout << "Value not found\n";
			system("pause");
			break;

		case 5:
			PrintLine(array, arraySize);
			system("pause");
			break;

		case 6:
			PrintColumn(array, arraySize);	
			system("pause");
			break;

		case 7:
			tempF1 = TotalSum(array, arraySize);
			if (tempF1 != ERROR)
				std::cout << "Total sum: " << tempF1 << "\n";
			else
				std::cout << "Operating failed!\n";
			system("pause");
			break;

		case 8:
			std::cout << "Enter left border: ";
			std::cin >> tempI1;
			std::cout << "Enter right border: ";
			std::cin >> tempI2;
			tempI3 = CountInRange(array, arraySize, tempI1, tempI2);
			if(tempI3 > 0)
				std::cout << "Count in range(" << tempI1 << ", " << tempI2 << "): "<< tempI3<< "\n";
			else
				std::cout << "Operating failed!\n";
			system("pause");
			break;

		case 9:
			PrintPikes(array, arraySize);
			system("pause");
			break;

		case 10:
			tmpArray = MakeCopy(array, arraySize);
			std::cout << "copy made successfully\n";
			for (int i = 0; i < arraySize; i++)
				delete tmpArray[i];
			delete tmpArray;
			system("pause");

		case 11:
			tempI1 = arraySize;
			array = (IManagable**)realloc(array, sizeof(IManagable*) * (++arraySize));
			array[tempI1] = nullptr;
			SetElement(type, array, arraySize, tempI1);
			break;

		case 12:
			Join(array, array, arraySize, arraySize);
			break;

		case 13:
			PrintUnique(array, arraySize);
			system("pause");
			break;

		case 0:
			action = 0;
			break;
		}
	}

	for (int i = 0; i < arraySize; i++)
		delete array[i];

	delete array;
	return 0;
}