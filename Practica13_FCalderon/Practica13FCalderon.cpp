// Practica13FCalderon.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "CImage.h"
#include "CJpg.h"
#include "CPng.h"

void EliminateAllAlpha(CImage** _pTableImg, int size);

int main()
{
	std::cout << "Hello World!\n";
	CImage* ptrTableImages[10];
	ptrTableImages[0] = new CPng();
	ptrTableImages[1] = new CImage();
	ptrTableImages[2] = new CJpg();
	ptrTableImages[3] = new CPng();
	ptrTableImages[4] = new CImage();
	ptrTableImages[5] = new CJpg();
	ptrTableImages[6] = new CPng();
	ptrTableImages[7] = new CImage();
	ptrTableImages[8] = new CJpg();
	ptrTableImages[9] = new CPng();

	int sizeTable = sizeof(ptrTableImages) / sizeof(int);

	EliminateAllAlpha(ptrTableImages, sizeTable);

	for (int i = 0; i < sizeTable; i++)
	{

		delete ptrTableImages[i];
	}

	return 0;
}


void EliminateAllAlpha(CImage** _pTableImg, int size)
{
	CImage* auxTable = nullptr;
	CPng* auxPng = nullptr;

	for (int i = 0; i < size; i++)
	{
		auxTable = *(_pTableImg + i);
		//if (*(_pTableImg + i)->cImgType == {"Png"})
		std::cout << "\nTipo " << auxTable->cImgType<<"\n";
		if (strcmp(auxTable->cImgType, "Png") == 0)
		{
			auxPng = static_cast<CPng*>(auxTable);
			auxPng->MakeTransparent();
		}
	}
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
