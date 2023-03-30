// Practica5FCalderon.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Practica5FCalderon.h"


FILE* ptrFile;
errno_t err;

const char* fileName = { "FileToRead.txt" };

int main()
{
	ReadFileVoid();

	WriteFileVoid();



	/*EJEMPLOS Y PRUEBAS SOBRE LA PRACTICA,
	* Diferentes Métodos (Void / Int) + Pruebas de Funcionamiento Write/Read


	//************ CASO 1 *****************\\
	// 
	//Abrir un fichero (AKA File)
	//				
	//Int Funcion
	// 
	std::cout << "CASO 1 \n";
	std::cout << "ABRIR ARCHIVO (int Func): \n";

	err = OpenFile(fileName, "r+");

	if (err != 0)
	{
		std::cout << "Error! File cannot be open\n";

	}
	else
	{
		std::cout << "File is Open!\n";

	}
	WriteFileVoid();
	ReadFileVoid();

	std::cout << "\nCERRAR ARCHIVO (int Func): \n";

	err = CloseFile();

	if (err != 0)
	{
		std::cout << "Error! File cannot be close\n";

	}
	else
	{
		std::cout << "File is Close!\n";

	}

	std::cout << "\n\n\n";




	//************ CASO 2 *****************\\
	// 
	//Reviso que funcione para abrir un archivo diferente// 
	//				
	//Int Funcions
	// 
	std::cout << "CASO 2 \n";
	std::cout << "ABRIR ARCHIVO (int Func) (puntero = null): \n";

	err = OpenFile("prueba.txt", "r");

	if (err != 0)
	{
		std::cout << "Error! File cannot be open\n";

	}
	else
	{
		std::cout << "File is Open!\n";

	}

	//Cerrar File 
	std::cout << "\nCERRAR ARCHIVO (int Func): \n";

	err = CloseFile();

	if (err != 0)
	{
		std::cout << "Error! File cannot be close\n";

	}
	else
	{
		std::cout << "File is Close!\n";

	}

	std::cout << "\n\n\n";






	//************ CASO 3 *****************\\
	// 
	//Abrir un fichero (AKA File)
	//				
	//Void Funcions
	// 

	std::cout << "CASO 3 \n";
	std::cout << "ABRIR ARCHIVO (void Func) (puntero = null): \n";
	OpenFileVoid(fileName, "r");

	std::cout << "\n\n";

	std::cout << "CERRAR ARCHIVO (void Func): \n";
	CloseFileVoid();

	std::cout << "\n\n\n";




	//************ CASO 4.A *****************\\
	// 
	//Compruebo caso no hay FILE abierto (ptrFile NO sea null), no se cierra
	//Fuerzo el error para testearlo. 
	//				
	//Int Funcion
	// 
	std::cout << "CASO 4.A \n";
	std::cout << "CERRAR ARCHIVO (int Func) (puntero = null): \n";

	err = CloseFile();

	if (err != 0)
	{
		std::cout << "Error! File cannot be close\n";

	}
	else
	{
		std::cout << "File is Close!\n";

	}

	std::cout << "\n\n";

	//************ CASO 4.B *****************\\
	// 
	//NO FILE abierto (ptrFile NO sea null), no se cierra
	//Fuerzo el error para testearlo. 
	//				
	//Void Funcion
	// 
	std::cout << "CASO 4.B \n";
	std::cout << "CERRAR ARCHIVO (void Func) (puntero = null): \n";

	CloseFileVoid();

	std::cout << "\n\n\n";

	//************ CASO 5 *****************\\
	// 
	//Compruebo qué pasa cuando abro un archivo y
	// sin cerrarlo, abro otro File al mismo puntero
	//				
	//void Funcion
	// 
	std::cout << "CASO 5 \n";
	std::cout << "ABRIR ARCHIVO (void Func) (puntero = null): \n";
	OpenFileVoid(fileName, "r");

	std::cout << "\n\n";

	//Abro archivo con void Func y puntero OCUPADO!:
	std::cout << "ABRIR ARCHIVO (void Func) (puntero = OCUPADO): \n";
	OpenFileVoid(fileName, "r");

	std::cout << "\n\n";

	//Cierro File que estaba abierto para que no se quede pillada la memoria
	std::cout << "CERRAR ARCHIVO (void Func): \n";
	CloseFileVoid();

	std::cout << "\n\n\n";



	///Escribir en File abierto

	//Leer el File abierto

	std::cout << "\n";


	*/
}

//INT FUNC
//
//Abrir fichero y guardarlo en ptrFile
int OpenFile(const char* _ccFileName, const char* _ccOpenMode)
{
	//Compruebo que el puntero esta null, no tiene archivos ya asociados

	if (ptrFile == nullptr)
	{
		std::cout << "El puntero esta disponible para almacenar el archivo\n";

		return fopen_s(&ptrFile, _ccFileName, _ccOpenMode);
	}
	else
	{
		std::cout << "YA TIENES UN ARCHIVO ABIERTO!\n";
		return -1;
	}
}

//FILE OpenFile(const char* _ccFileName, const char* _ccOpenMode)
//{
//	//Compruebo que el puntero esta null, no tiene archivos ya asociados
//
//	if (ptrFile == nullptr)
//	{
//		std::cout << "El puntero esta disponible para almacenar el archivo\n";
//
//		return fopen_s(&ptrFile, _ccFileName, _ccOpenMode);
//	}
//	else
//	{
//		std::cout << "YA TIENES UN ARCHIVO ABIERTO!\n";
//		return FILE;
//	}
//}


int CloseFile()
{
	/*if (ptrFile)
	{
		return fclose(ptrFile);
	}
	else
	{
		std::cout << "El puntero esta nullptr. No tiene File asociado\n";
		return 1;
	}*/

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
			printf("ERROR! The file was not closed\n");
		}

		//Restablezco el puntero a null para poder asociarlo a otro archivo
		ptrFile = nullptr;

		return _err;
	}
	else
	{
		std::cout << "EL PUNTERO ESTA NULL!\n";
		return -1;
	}
}


//VOID FUNC
void OpenFileVoid(const char* _ccFileName, const char* _ccOpenMode)
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

void CloseFileVoid()
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


void ReadFileVoid()
{
	//Comprobacion de apertura archivo (Evitar errores por no tenerlo abierto)
	OpenFileVoid(fileName, "r");

	fseek(ptrFile, 0, SEEK_END);
	long lSize = ftell(ptrFile);
	printf("Size of myfile.txt: %ld bytes.\n", lSize);
	rewind(ptrFile);
	

	char* buffer = new char[lSize];

	if (buffer == NULL)
	{
		fputs("Memory error", stderr);
		exit(2);
	}

	// copy the file into the buffer:
	size_t resultado = fread(buffer, 1, lSize, ptrFile);
	buffer[resultado] = { '\0' };
	if (resultado != static_cast<size_t>(lSize))
	{
		fputs("Reading error", stderr);
		exit(3);
	}

	std::cout << "\nLectura: " << buffer << "\n";
	for (size_t i = 0; i < resultado; i++)
	{

		std::cout << *buffer << " " << i << "\n";
		buffer++; // con aritmetica de punteros
	}
	std::cout << "\nLectura: " << buffer << "\n";

	CloseFileVoid();

	//delete(*buffer);
	//free(buffer);

}

void WriteFileVoid()
{
	OpenFileVoid(fileName, "w");
	char buffer[] = { 'x', 'y', 'z' };
	fwrite(buffer, sizeof(char), sizeof(buffer), ptrFile);



	//Debugg
	CloseFile();
	ReadFileVoid();
}