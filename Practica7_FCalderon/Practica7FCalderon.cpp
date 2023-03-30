#pragma once
//#include "Practica7FCalderon.h"
#include "FileUtils.h"


int main()
{
	//Lee el archivo con nombre por defecto (El de las cadenas)

	/*std::cout << "Lectura del Archivo  FileToRead.Txt: \n";
	std::cout << "\t" << FileUtils::ReadFile2() << "\n\n\n\n\n";*/

	std::cout << "Comparar Cadenas del Archivo  FileToRead.Txt: \n";
	std::cout << "\t" << FileUtils::AparicionesCadenaEnFile() << "\n\n\n\n\n";


	std::cout << "Sumas de Insts del Archivo  FileToSum.Txt: \n";
	std::cout << "\t" << FileUtils::TotalSumaDelFile() << "\n\n\n\n\n";


	std::cout << "Sobreescribir FileToRead.Txt: \n";
	//std::cout << "\t" << FileUtils::WriteFile("FileToRead.txt") << "\n\n\n\n\n";
	FileUtils::WriteFile("FileToRead.txt");


	std::cout << "\n\n\n\n\nComparar Cadenas del Archivo  FileToRead.Txt: \n";
	std::cout << "\t" << FileUtils::AparicionesCadenaEnFile() << "\n\n\n\n\n";

	/*FileUtils::ReadFile();

	FileUtils::WriteFile();*/
	return 0;
}



