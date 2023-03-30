// Practica6FCalderon.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Practica6FCalderon.h"





int main()
{
	std::cout << "\n\n Numero de apariciones " << AparicionesCadenaEnFile() << "\n\n\n\n";

	std::cout << "\n\n Suma total en File " << TotalSumaDelFile() << "\n";

	//const char* myBufferOutside = ReadFile();
	////std::cout << "\n\n Lectura de File " << ReadFile() << "\n";
	//std::cout << "\n\n Lectura de File " << myBufferOutside << "\n";
	//if (cadenaToIdentify == cadenaToIdentify)
	//{
	//std::cout << "\n\n Lectura de File " << myBufferOutside << "\n";

	//}
	//std::cout << "\n\n Lectura de File " << myBufferOutside << "\n";
	//std::cout << "\n\n Suma total en File " << ReadFile() << "\n";


	//ReadFile();

	//WriteFile();


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




//VOID FUNC
void OpenFile(const char* _ccFileName, const char* _ccOpenMode)
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

void CloseFile()
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

void WriteFile()
{
	OpenFile(fileNameDefault, "w");
	char buffer[] = { 'x', 'y', 'z' };
	fwrite(buffer, sizeof(char), sizeof(buffer), ptrFile);



	//Debugg
	CloseFile();
	ReadFile();
}


const char* ReadFile()
{
	//Comprobacion de apertura archivo (Evitar errores por no tenerlo abierto)
	OpenFile(fileNameDefault, "r");

	fseek(ptrFile, 0, SEEK_END);
	long lSize = ftell(ptrFile);
	printf("Size of myfile.txt: %ld bytes.\n", lSize);
	rewind(ptrFile);
	

	//char* buffer = (char*)malloc(sizeof(char) * lSize);
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

	//std::cout << "\nLectura: " << buffer << "\n";
	//char endWord = { '\0' };

	std::cout << "\nLectura total del buffer " << buffer << "\n\n";
	std::cout << "\tLetra a letra del buffer\n\n";

	for (size_t i = 0; i < resultado; i++)
	{
		//Con estas lineas movia todo el puntero, lo que me obligaba a dar marcha atras sobre mis pasos para recuperar el puntero al inicio
		/*std::cout << "Letra de Buffer[" << i << "] " << *buffer << "\n";
		buffer++;*/

		//Cambiado el sistema a aritmetica mas directa del puntero con el bucle for:
		std::cout << "Letra de Buffer[" << i << "] " << *(buffer + i) << "\n";

	}
	std::cout << "\n\n\tFinal Lectura del Buffer\n\n\n";

	CloseFile();

	//delete(*buffer);
	//free(buffer);
	return buffer;
}

const char* ReadFile(const char* _FileNameToOpen)
{
	//Comprobacion de apertura archivo (Evitar errores por no tenerlo abierto)
	OpenFile(_FileNameToOpen, "r");

	fseek(ptrFile, 0, SEEK_END);
	long lSize = ftell(ptrFile);
	//printf("Size of myfile.txt: %ld bytes.\n", lSize);
	rewind(ptrFile);

	//std::cout << "Hola " << bytesSize <<"\n";

	//char* buffer = (char*)malloc(sizeof(char) * lSize);
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

	//std::cout << "\nLectura: " << buffer << "\n";
	//char endWord = { '\0' };

	//for (size_t i = 0; i < resultado; i++)
	//{
	//	//Con estas lineas movia todo el puntero, lo que me obligaba a dar marcha atras sobre mis pasos para recuperar el puntero al inicio
	//	/*std::cout << "Letra de Buffer[" << i << "] " << *buffer << "\n";
	//	buffer++;*/
	//
	//	//Cambiado el sistema a aritmetica mas directa del puntero con el bucle for:
	//	std::cout << "Letra de Buffer[" << i << "] " << *(buffer + i) << "\n";
	//
	//}

	//CloseFile();

	//delete(*buffer);
	//free(buffer);
	return buffer;
}



int AparicionesCadenaEnFile()
{


	//Obtengo el puntero al buffer leido
	const char* ptrBufferReaded = ReadFile(fileNameCadenaAparicion);

	//Saco la cantidad de caracteres totales del archivo mediante el uso de aritmetica de punteros
	int iCantCharFile = 0;
	for (int i = 0; *(ptrBufferReaded + i) != '\0'; i++)
	{
		iCantCharFile++;
	}

	//Variables a utilizar en la funcion
	char endWord = { '\0' };

	int iCantVecesCadena = 0;
	int indexCadenaComparar = 0;


	//Recorro el bucle comparando las cadenas
	for (int i = 0; i < iCantCharFile; i++)
	{
		//std::cout << "Letra de Buffer[" << i << "] " << *(ptrBufferReaded + i) << "\n";
		//std::cout << "Letra de Cadena[" << i << "] " << *cadenaToIdentify << "\n";

		if (*(ptrBufferReaded + i) == *cadenaToIdentify)
		{
			std::cout << "Letra Buffer[" << i << "] (" << *(ptrBufferReaded + i) << ") SI COINCIDE con Letra  CadenaComparativa["<< indexCadenaComparar <<"] ("<< *cadenaToIdentify <<")\n";
			indexCadenaComparar++;
			cadenaToIdentify++;

			if (*cadenaToIdentify == endWord) //Final de la cadena
			{
				for (int j = indexCadenaComparar; j > 0; j--)
				{
					 //Retorno al inicio del puntero
					--cadenaToIdentify;
				}
				++iCantVecesCadena;
				indexCadenaComparar = 0;
				std::cout << "\n\nHABEMUS COINSIDENSIA\n\n";
			}
		}
		else if (*(ptrBufferReaded + i) != *cadenaToIdentify)
		{
			std::cout << "Letra Buffer[" << i << "] (" << *(ptrBufferReaded + i) << ") != Letra CadenaComparativa[" << indexCadenaComparar << "] (" << *cadenaToIdentify << ")\n";
			//for (int j = 0; j < indexCadenaComparar; j++)
			//{
			//	resultRead--; //Retorno al inicio del puntero
			//}
			for (int j = indexCadenaComparar; j > 0; j--)
			{
				//Retorno al inicio del puntero
				--cadenaToIdentify;
			}
				indexCadenaComparar = 0;
		}

		


	}

	CloseFile();

	return iCantVecesCadena;
}


int TotalSumaDelFile()
{

	//Obtengo el puntero al buffer leido
	const char* ptrBufferReaded = ReadFile(fileNameSumaIntsCadena);

	//Saco la cantidad de caracteres totales del archivo mediante el uso de aritmetica de punteros
	int iCantCharFile = 0;
	for (int i = 0; *(ptrBufferReaded + i) != '\0'; i++)
	{
		iCantCharFile++;
	}

	const char comaChar = { ',' };
	const char spaceChar = { ' ' };
	const char endTextChar = { '\0' };

	int sumaTotal = 0;
	std::string myCurrentNum;


	for (int i = 0; i <= iCantCharFile; i++)
	{

		std::cout << "Letra de Buffer[" << i << "] " << *(ptrBufferReaded + i) << "\n"; // con aritmetica de punteros

		if ((*(ptrBufferReaded + i) != comaChar) && (*(ptrBufferReaded + i) != spaceChar) && (*(ptrBufferReaded + i) != endTextChar))
		{
			myCurrentNum += *(ptrBufferReaded + i);
			std::cout << "Current Read Number " << myCurrentNum << "\n";
		}
		else
		{
			std::cout << "\nES COMA O SPACE, ejecuto logica de suma\n";
			int castStringToInt = std::stoi(myCurrentNum);
			sumaTotal += castStringToInt;

			std::cout << "\t Numero Suma " << sumaTotal << "\n\n";

			myCurrentNum.clear();//Limpio la string para seguir utilizandola hasta el final del archivo
		}

		//buffer++; 
	}
	//std::cout << "\n\n Numero de apariciones " << iCantVecesCadena;
	//std::cout << "\nLectura: " << buffer << "\n";

	CloseFile();
	return sumaTotal;

}






//////void ReadFile()
//////{
//////	//Comprobacion de apertura archivo (Evitar errores por no tenerlo abierto)
//////	OpenFile(fileName, "r");
//////
//////	fseek(ptrFile, 0, SEEK_END);
//////	long lSize = ftell(ptrFile);
//////	printf("Size of myfile.txt: %ld bytes.\n", lSize);
//////	rewind(ptrFile);
//////	const int bytesSize = lSize;
//////	const int* bSize = &bytesSize;
//////	//std::cout << "Hola " << bytesSize <<"\n";
//////
//////	char* buffer = (char*)malloc(sizeof(char) * lSize);
//////
//////	if (buffer == NULL)
//////	{
//////		fputs("Memory error", stderr);
//////		exit(2);
//////	}
//////
//////	// copy the file into the buffer:
//////	size_t resultado = fread(buffer, 1, lSize, ptrFile);
//////	buffer[resultado] = { '\0' };
//////	if (resultado != lSize)
//////	{
//////		fputs("Reading error", stderr);
//////		exit(3);
//////	}
//////
//////	std::cout << "\nLectura: " << buffer << "\n";
//////	char endWord = { '\0' };
//////
//////	int iCantVecesCadena = 0;
//////	int coincidencias = 0;
//////
//////	const char comaChar = { ',' };
//////	char auxCharSuma{'\0'};
//////	
//////	char* totCharSuma = new char[3];
//////	for (int i = 0; i < strlen(totCharSuma);  i++)
//////	{
//////		totCharSuma[i] = { '\0' };
//////	}
//////	int isNumTheChar = 0;
//////
//////	//char* numBuffer = { '\0' };
//////	int sumaTotal = 0;
//////
//////
//////	for (size_t i = 0; i < resultado; i++)
//////	{
//////
//////		std::cout << "Letra de Buffer[" << i << "] " << *buffer << "\n";
//////
//////
//////		/////////////////FUNC IDENTIFICA CADENA
//////		std::cout << "Letra de Cadena[" << i << "] " << *cadenaToIdentify << "\n";
//////
//////		if (*buffer == *cadenaToIdentify)
//////		{
//////			coincidencias++;
//////			cadenaToIdentify++;
//////			//buffer++;
//////			resultRead++;
//////			if (*cadenaToIdentify == endWord) //Final de la cadena
//////			{
//////				//std::cout << "\n "<<endWord <<"\n\n";
//////				std::cout << "Coincide\n ";
//////				for (int j = 0; j < coincidencias; j++)
//////				{
//////					resultRead--; //Retorno al inicio del puntero
//////					--cadenaToIdentify;
//////				}
//////				++iCantVecesCadena;
//////				coincidencias = 0;
//////			}
//////		}
//////		else if (*buffer != *cadenaToIdentify)
//////		{
//////			std::cout << "NO CCOINC\n ";
//////
//////			for (int j = 0; j < coincidencias; j++)
//////			{
//////				resultRead--; //Retorno al inicio del puntero
//////			}
//////		}
//////
//////
//////		/////// 
//////		/////// //////////////////// FIN PARTE 1
//////
//////
//////
//////
//////		/////////////SumarCadenas
//////	
//////
//////		//if (*buffer == comaChar)
//////		//{
//////		//	for (int i = 0; i < isNumTheChar; i++)
//////		//	{
//////		//		totCharSuma--;
//////		//	}
//////
//////		//	int changeCharToNum = static_cast<int>(*totCharSuma);
//////		//	sumaTotal += changeCharToNum;
//////		//	for (int i = 0; i < strlen(totCharSuma); i++)
//////		//	{
//////		//		totCharSuma[i] = { '\0' };
//////		//	}
//////		//	std::cout << "\n\nTotal Suma: " << sumaTotal<<"\n";
//////		//	//numBuffer += auxCharSuma;
//////		//}
//////		//else if (*buffer != comaChar)
//////		//{
//////		//	*totCharSuma = *buffer;
//////		//
//////		//	//std::cout << "\n\nCurrent Buffer Char: " << totCharSuma<<"\n";
//////		//	//buffer++; // con aritmetica de punteros
//////		//	totCharSuma++;
//////		//	isNumTheChar++;
//////		//	//int TotNumber = (*numBuffer);
//////		//	//std::cout << "\n\n TotNu " << TotNumber;
//////		//	//sumaTotal += TotNumber;
//////		//}
//////
//////
//////		/////////
//////
//////
//////
//////
//////		buffer++; // con aritmetica de punteros
//////	}
//////	std::cout << "\n\n Numero de apariciones " << iCantVecesCadena;
//////	//std::cout << "\n\n Numero Suma " << sumaTotal;
//////	std::cout << "\nLectura: " << buffer << "\n";
//////
//////	//CloseFile();
//////
//////	//delete(*buffer);
//////	//free(buffer);
//////
//////}


////void ReadFile()
////{
////	//Comprobacion de apertura archivo (Evitar errores por no tenerlo abierto)
////	OpenFile(fileName, "r");
////
////	fseek(ptrFile, 0, SEEK_END);
////	long lSize = ftell(ptrFile);
////	printf("Size of myfile.txt: %ld bytes.\n", lSize);
////	rewind(ptrFile);
////	const int bytesSize = lSize;
////	const int* bSize = &bytesSize;
////	//std::cout << "Hola " << bytesSize <<"\n";
////
////	char* buffer = (char*)malloc(sizeof(char) * lSize);
////
////	if (buffer == NULL)
////	{
////		fputs("Memory error", stderr);
////		exit(2);
////	}
////
////	// copy the file into the buffer:
////	size_t resultado = fread(buffer, 1, lSize, ptrFile);
////	buffer[resultado] = { '\0' };
////	if (resultado != lSize)
////	{
////		fputs("Reading error", stderr);
////		exit(3);
////	}
////
////	std::cout << "\nLectura: " << buffer << "\n";
////	char endWord = { '\0' };
////
////	
////
////	for (size_t i = 0; i < resultado; i++)
////	{
////		//Con estas lineas movia todo el puntero, lo que me obligaba a dar marcha atras sobre mis pasos para recuperar el puntero al inicio
////		/*std::cout << "Letra de Buffer[" << i << "] " << *buffer << "\n";	
////		buffer++;*/
////		
////		//Cambiado el sistema a aritmetica mas directa del puntero con el bucle for:
////		std::cout << "Letra de Buffer[" << i << "] " << *(buffer+i) << "\n";	
////
////	}
////
////	//CloseFile();
////
////	//delete(*buffer);
////	//free(buffer);
////
////}


//const char* ReadFile(char*& _ptrOutBuffer_)
//{
//	//Comprobacion de apertura archivo (Evitar errores por no tenerlo abierto)
//	OpenFile(fileName, "r");
//
//	fseek(ptrFile, 0, SEEK_END);
//	long lSize = ftell(ptrFile);
//	printf("Size of myfile.txt: %ld bytes.\n", lSize);
//	rewind(ptrFile);
//	const int bytesSize = lSize;
//	const int* bSize = &bytesSize;
//	//std::cout << "Hola " << bytesSize <<"\n";
//
//	//char* buffer = (char*)malloc(sizeof(char) * lSize);
//	char* buffer = new char[lSize];
//	if (buffer == NULL)
//	{
//		fputs("Memory error", stderr);
//		exit(2);
//	}
//
//	// copy the file into the buffer:
//	size_t resultado = fread(buffer, 1, lSize, ptrFile);
//	buffer[resultado] = { '\0' };
//	if (resultado != lSize)
//	{
//		fputs("Reading error", stderr);
//		exit(3);
//	}
//
//	//std::cout << "\nLectura: " << buffer << "\n";
//	//char endWord = { '\0' };
//
//
//
//	for (size_t i = 0; i < resultado; i++)
//	{
//		//Con estas lineas movia todo el puntero, lo que me obligaba a dar marcha atras sobre mis pasos para recuperar el puntero al inicio
//		/*std::cout << "Letra de Buffer[" << i << "] " << *buffer << "\n";
//		buffer++;*/
//
//		//Cambiado el sistema a aritmetica mas directa del puntero con el bucle for:
//		std::cout << "Letra de Buffer[" << i << "] " << *(buffer + i) << "\n";
//
//	}
//
//	CloseFile();
//
//	//delete(*buffer);
//	//free(buffer);
//	return buffer;
//}

//void AparicionesCadenaEnFile()
//{
//	//Comprobacion de apertura archivo (Evitar errores por no tenerlo abierto)
//	OpenFile(fileNameCadenaAparicion, "r");
//
//	fseek(ptrFile, 0, SEEK_END);
//	long lSize = ftell(ptrFile);
//	printf("Size of myfile.txt: %ld bytes.\n", lSize);
//	rewind(ptrFile);
//	const int bytesSize = lSize;
//	const int* bSize = &bytesSize;
//	//std::cout << "Hola " << bytesSize <<"\n";
//
//	char* buffer = (char*)malloc(sizeof(char) * lSize);
//
//	if (buffer == NULL)
//	{
//		fputs("Memory error", stderr);
//		exit(2);
//	}
//
//	// copy the file into the buffer:
//	size_t resultado = fread(buffer, 1, lSize, ptrFile);
//	buffer[resultado] = { '\0' };
//	if (resultado != lSize)
//	{
//		fputs("Reading error", stderr);
//		exit(3);
//	}
//
//	std::cout << "\nLectura: " << buffer << "\n";
//	char endWord = { '\0' };
//
//	int iCantVecesCadena = 0;
//	int coincidencias = 0;
//
//	const char comaChar = { ',' };
//	char auxCharSuma{ '\0' };
//
//	char* totCharSuma = new char[3];
//	for (int i = 0; i < strlen(totCharSuma); i++)
//	{
//		totCharSuma[i] = { '\0' };
//	}
//	int isNumTheChar = 0;
//
//	//char* numBuffer = { '\0' };
//	int sumaTotal = 0;
//
//
//	for (size_t i = 0; i < resultado; i++)
//	{
//
//		std::cout << "Letra de Buffer[" << i << "] " << *buffer << "\n";
//
//
//		/////////////////FUNC IDENTIFICA CADENA
//		std::cout << "Letra de Cadena[" << i << "] " << *cadenaToIdentify << "\n";
//
//		if (*buffer == *cadenaToIdentify)
//		{
//			coincidencias++;
//			cadenaToIdentify++;
//			//buffer++;
//			resultRead++;
//			if (*cadenaToIdentify == endWord) //Final de la cadena
//			{
//				//std::cout << "\n "<<endWord <<"\n\n";
//				std::cout << "Coincide\n ";
//				for (int j = 0; j < coincidencias; j++)
//				{
//					resultRead--; //Retorno al inicio del puntero
//					--cadenaToIdentify;
//				}
//				++iCantVecesCadena;
//				coincidencias = 0;
//			}
//		}
//		else if (*buffer != *cadenaToIdentify)
//		{
//			std::cout << "NO CCOINC\n ";
//
//			for (int j = 0; j < coincidencias; j++)
//			{
//				resultRead--; //Retorno al inicio del puntero
//			}
//		}
//
//		buffer++; // con aritmetica de punteros
//	}
//	std::cout << "\n\n Numero de apariciones " << iCantVecesCadena;
//	//std::cout << "\n\n Numero Suma " << sumaTotal;
//	std::cout << "\nLectura: " << buffer << "\n";
//
//	CloseFile();
//
//	//delete(*buffer);
//	//free(buffer);
//} NO BORRAR AUN! VOID METHOD PA PRUEBAS

//int AparicionesCadenaEnFile()
//{
//	//Comprobacion de apertura archivo (Evitar errores por no tenerlo abierto)
//	OpenFile(fileNameCadenaAparicion, "r");
//
//	fseek(ptrFile, 0, SEEK_END);
//	long lSize = ftell(ptrFile);
//	printf("Size of myfile.txt: %ld bytes.\n", lSize);
//	rewind(ptrFile);
//	const int bytesSize = lSize;
//	const int* bSize = &bytesSize;
//	//std::cout << "Hola " << bytesSize <<"\n";
//
//	//char* buffer = (char*)malloc(sizeof(char) * lSize);
//	char* buffer = new char [lSize];
//
//	if (buffer == NULL)
//	{
//		fputs("Memory error", stderr);
//		exit(2);
//	}
//
//	// copy the file into the buffer:
//	size_t resultado = fread(buffer, 1, lSize, ptrFile);
//	buffer[resultado] = { '\0' };
//	if (resultado != lSize)
//	{
//		fputs("Reading error", stderr);
//		exit(3);
//	}
//
//	std::cout << "\nLectura: " << buffer << "\n";
//	char endWord = { '\0' };
//
//	int iCantVecesCadena = 0;
//	int coincidencias = 0;
//
//	const char comaChar = { ',' };
//	char auxCharSuma{ '\0' };
//
//	char* totCharSuma = new char[3];
//	for (int i = 0; i < strlen(totCharSuma); i++)
//	{
//		totCharSuma[i] = { '\0' };
//	}
//	int isNumTheChar = 0;
//
//	//char* numBuffer = { '\0' };
//	int sumaTotal = 0;
//
//
//	for (size_t i = 0; i < resultado; i++)
//	{
//
//		std::cout << "Letra de Buffer[" << i << "] " << *buffer << "\n";
//
//
//		/////////////////FUNC IDENTIFICA CADENA
//		std::cout << "Letra de Cadena[" << i << "] " << *cadenaToIdentify << "\n";
//
//		if (*buffer == *cadenaToIdentify)
//		{
//			coincidencias++;
//			cadenaToIdentify++;
//			//buffer++;
//			resultRead++;
//			if (*cadenaToIdentify == //endWord) //Final de la cadena
//			{
//				//std::cout << "\n "<<endWord <<"\n\n";
//				std::cout << "Coincide\n ";
//				for (int j = 0; j < coincidencias; j++)
//				{
//					resultRead--; //Retorno al inicio del puntero
//					--cadenaToIdentify;
//				}
//				++iCantVecesCadena;
//				coincidencias = 0;
//			}
//		}
//		else if (*buffer != *cadenaToIdentify)
//		{
//			std::cout << "NO CCOINC\n ";
//
//			for (int j = 0; j < coincidencias; j++)
//			{
//				resultRead--; //Retorno al inicio del puntero
//			}
//		}
//
//		buffer++; // con aritmetica de punteros
//	}
//	//std::cout << "\n\n Numero de apariciones " << iCantVecesCadena;
//	//std::cout << "\n\n Numero Suma " << sumaTotal;
//	//std::cout << "\nLectura: " << buffer << "\n";
//
//	CloseFile();
//	return iCantVecesCadena;
//	//delete(*buffer);
//	//free(buffer);
//}
//