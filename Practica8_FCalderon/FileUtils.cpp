#include "FileUtils.h"




//VOID FUNC
void  CFile::OpenFile(const char* _ccFileName, const char* _ccOpenMode)
{
	//Compruebo que el puntero esta null, no tiene archivos ya asociados

	if (ptrFile == nullptr)
	{
		std::cout << "El puntero esta disponible para almacenar el archivo\n";

		int _err = fopen_s(&ptrFile, _ccFileName, _ccOpenMode);

		if (_err != 0)
		{
			std::cout << "Error! File cannot be open\n";

		}
		else
		{
			std::cout << "File is Open!\n";

		}
	}
	else
	{
		std::cout << "YA TIENES UN ARCHIVO ABIERTO!\n";

	}

}

void CFile::CloseFile()
{

	//Compruebo que el puntero tiene archivos ya asociados (Diferente de nullptr)
	if (ptrFile)
	{
		//Diferencia con OpenFile, 
		//creo una variable auxiliar para comprobar dentro de la funcion que el archivo se cierra correctamente
		//Posible ser menos eficiente puesto que crea un int (8bits) 
		int _err = fclose(ptrFile);
		if (_err == 0)
		{
			printf("File is Close!\n");
		}
		else
		{
			printf("ERROR! File Cant be Closed\n");
		}

		//Restablezco el puntero a null para poder asociarlo a otro archivo
		ptrFile = nullptr;

	}
	else
	{
		std::cout << "EL PUNTERO ESTA NULL!\n";
	}
}


void CFile::ReadFile()
{
	//Comprobacion de apertura archivo (Evitar errores por no tenerlo abierto)
	if (ptrFile == nullptr)
	{
		OpenFile(fileName, "r");
	}

	fseek(ptrFile, 0, SEEK_END);
	long lSize = ftell(ptrFile);
	printf("Size of myfile.txt: %ld bytes.\n", lSize);
	rewind(ptrFile);
	//std::cout << "Hola " << bytesSize <<"\n";

	char* buffer = new char[lSize];

	if (buffer == NULL)
	{
		fputs("Memory error", stderr);
		exit(2);
	}

	// copy the file into the buffer:
	size_t resultado = fread(buffer, 1, lSize, ptrFile);
	buffer[resultado] = { '\0' };
	if (resultado != lSize)
	{
		fputs("Reading error", stderr);
		exit(3);
	}

	std::cout << "\nLectura: " << buffer << "\n\n";

	//CloseFile();
	//std::cout << "\n\n";


}

void CFile::WriteFile()
{
	if (ptrFile == nullptr)
	{
		OpenFile(fileName, "w+");
	}

	char buffer[] = { 'x', 'y', 'z' };
	fwrite(buffer, sizeof(char), sizeof(buffer), ptrFile);



	//Debugg
	//CloseFile();
	ReadFile();
}






















////////
////////
////////
////////
////////
////////
////////
////////
////////
////////
////////
////////
////////
////////
////////
////////
////////
////////
//////////VOID FUNC
////////void FileUtils::OpenFile(const char* _ccFileName, const char* _ccOpenMode)
////////{
////////	//Compruebo que el puntero esta null, no tiene archivos ya asociados
////////
////////	if (ptrFile == nullptr)
////////	{
////////		std::cout << "El puntero esta disponible para almacenar el archivo\n";
////////
////////		int _err = fopen_s(&ptrFile, _ccFileName, _ccOpenMode);
////////
////////		if (_err != 0)
////////		{
////////			std::cout << "Error! File cannot be open\n";
////////
////////		}
////////		else
////////		{
////////			std::cout << "File is Open!\n";
////////
////////		}
////////	}
////////	else
////////	{
////////		std::cout << "YA TIENES UN ARCHIVO ABIERTO!\n";
////////
////////	}
////////
////////}
////////
////////void FileUtils::CloseFile()
////////{
////////
////////	//Compruebo que el puntero tiene archivos ya asociados (Diferente de nullptr)
////////	if (ptrFile)
////////	{
////////		//Diferencia con OpenFile, 
////////		//creo una variable auxiliar para comprobar dentro de la funcion que el archivo se cierra correctamente
////////		//Posible ser menos eficiente puesto que crea un int (8bits) 
////////		int _err = fclose(ptrFile);
////////		if (_err == 0)
////////		{
////////			printf("File is Close!\n");
////////		}
////////		else
////////		{
////////			printf("ERROR! File Cant be Closed\n");
////////		}
////////
////////		//Restablezco el puntero a null para poder asociarlo a otro archivo
////////		ptrFile = nullptr;
////////
////////	}
////////	else
////////	{
////////		std::cout << "EL PUNTERO ESTA NULL!\n";
////////	}
////////}
////////
////////
////////void FileUtils::ReadFile()
////////{
////////	//Comprobacion de apertura archivo (Evitar errores por no tenerlo abierto)
////////	FileUtils::OpenFile(fileName, "r");
////////
////////	fseek(ptrFile, 0, SEEK_END);
////////	long lSize = ftell(ptrFile);
////////	printf("Size of myfile.txt: %ld bytes.\n", lSize);
////////	rewind(ptrFile);
////////	const int bytesSize = lSize;
////////	const int* bSize = &bytesSize;
////////	//std::cout << "Hola " << bytesSize <<"\n";
////////
////////	char* buffer = (char*)malloc(sizeof(char) * lSize);
////////
////////	if (buffer == NULL)
////////	{
////////		fputs("Memory error", stderr);
////////		exit(2);
////////	}
////////
////////	// copy the file into the buffer:
////////	size_t resultado = fread(buffer, 1, lSize, ptrFile);
////////	buffer[resultado] = { '\0' };
////////	if (resultado != lSize)
////////	{
////////		fputs("Reading error", stderr);
////////		exit(3);
////////	}
////////
////////	std::cout << "\nLectura: " << buffer << "\n";
////////
////////	FileUtils::CloseFile();
////////
////////	//delete(*buffer);
////////	//free(buffer);
////////
////////}
////////
////////void FileUtils::WriteFile()
////////{
////////	FileUtils::OpenFile(fileName, "w");
////////	char buffer[] = { 'x', 'y', 'z' };
////////	fwrite(buffer, sizeof(char), sizeof(buffer), ptrFile);
////////
////////
////////
////////	//Debugg
////////	FileUtils::CloseFile();
////////	FileUtils::ReadFile();
////////}