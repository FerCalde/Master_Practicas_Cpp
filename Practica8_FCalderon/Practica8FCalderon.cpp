// Practica8FCalderon.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
//#include "Practica8FCalderon.h"

#include "FileUtils.h"

int main()
{
	std::cout << "FILE BY CLASS \n";
	CFile myFile;

	myFile.OpenFile(myFile.fileName, "r+");

	myFile.ReadFile();

	myFile.WriteFile();

	myFile.CloseFile();
	
	
	std::cout << "\n\nFILE BY POINTER TO CLASS \n";

	CFile* ptrMyFile = new CFile;

	ptrMyFile->OpenFile(ptrMyFile->fileName, "r+");

	ptrMyFile->ReadFile();

	ptrMyFile->WriteFile();

	ptrMyFile->CloseFile();

	delete ptrMyFile;



	///*FileUtils::ReadFile();

	//FileUtils::WriteFile();*/

}



