
#include "FileUtils.h"

FILE* ptrFile;
errno_t err;

extern const char* fileNameDefault = { "FileToSum.txt" }; //P6
extern const char* fileNameCadenaAparicion = { "FileToRead.txt" }; //P6
extern const char* fileNameSumaIntsCadena = { "FileToSum.txt" };//P6

extern const char* cadenaToIdentify = { "Hola Hola" };//P6


const char comaChar = { ',' };
const char spaceChar = { ' ' };
const char endTextChar = { '\0' };

//VOID FUNC
void FileUtils::OpenFile(const char* _ccFileName, const char* _ccOpenMode)
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

void FileUtils::CloseFile()
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



void FileUtils::WriteFile()
{
	FileUtils::OpenFile("DefaultTextToWrite.txt", "w");
	char buffer[] = { 'x', 'y', 'z', 'x', 'y', 'z','x', 'y', 'z','x', 'y', 'z','x', 'y', 'z', };
	fwrite(buffer, sizeof(char), sizeof(buffer), ptrFile);


	//Debugg
	FileUtils::CloseFile();
	FileUtils::ReadFile();

}

void FileUtils::WriteFile(const char* _FileNameToOpen)
{
	FileUtils::OpenFile(_FileNameToOpen, "w");
	char buffer[] = { 'x', 'y', 'z', 'x', 'y', 'z','x', 'y', 'z','x', 'y', 'z','x', 'y', 'z', };
	fwrite(buffer, sizeof(char), sizeof(buffer), ptrFile);


	//Debugg
	FileUtils::CloseFile();
	FileUtils::ReadFile();

}

//Metodo que LEE el archivo y lo CIERRA una vez que devuelve los datos
const char* FileUtils::ReadFile()
{
	//Comprobacion de apertura archivo (Evitar errores por no tenerlo abierto)
	FileUtils::OpenFile(fileNameDefault, "r");

	fseek(ptrFile, 0, SEEK_END);
	long lSize = ftell(ptrFile);
	printf("Size of myfile.txt: %ld bytes.\n", lSize);
	rewind(ptrFile);
	//const int bytesSize = lSize;
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


	std::cout << "\nLectura total del buffer " << buffer << "\n\n";
	std::cout << "\tLetra a letra del buffer\n\n";

	for (size_t i = 0; i < resultado; i++)
	{
		//Cambiado el sistema a aritmetica mas directa del puntero con el bucle for:
		std::cout << "Letra de Buffer[" << i << "] " << *(buffer + i) << "\n";

	}
	std::cout << "\n\n\tFinal Lectura del Buffer\n\n\n";

	FileUtils::CloseFile();


	return buffer;
}

//Deja el fichero abierto, RECORDAR CERRARLO CUANDO NO SE QUIERA MAS
const char* FileUtils::ReadFile(const char* _FileNameToOpen)
{
	//Comprobacion de apertura archivo (Evitar errores por no tenerlo abierto)
	FileUtils::OpenFile(_FileNameToOpen, "r");

	fseek(ptrFile, 0, SEEK_END);
	long lSize = ftell(ptrFile);
	rewind(ptrFile);
	//const int bytesSize = lSize;

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


	return buffer;
}



int FileUtils::AparicionesCadenaEnFile()
{


	//Obtengo el puntero al buffer leido
	const char* ptrBufferReaded = FileUtils::ReadFile(fileNameCadenaAparicion);

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
			std::cout << "Letra Buffer[" << i << "] (" << *(ptrBufferReaded + i) << ") SI COINCIDE con Letra  CadenaComparativa[" << indexCadenaComparar << "] (" << *cadenaToIdentify << ")\n";
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


int FileUtils::TotalSumaDelFile()
{

	//Obtengo el puntero al buffer leido
	const char* ptrBufferReaded = FileUtils::ReadFile(fileNameSumaIntsCadena);

	//Saco la cantidad de caracteres totales del archivo mediante el uso de aritmetica de punteros
	int iCantCharFile = 0;
	for (int i = 0; *(ptrBufferReaded + i) != '\0'; i++)
	{
		iCantCharFile++;
	}



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

	}


	FileUtils::CloseFile();
	return sumaTotal;

}

FileUtils::TList* FileUtils::RetornarTListConCadenaDeFile()
{
	//Obtengo el puntero al buffer leido
	const char* ptrBufferReaded = FileUtils::ReadFile(fileNameSumaIntsCadena);
	//Saco la cantidad de caracteres totales del archivo mediante el uso de aritmetica de punteros
	int iCantCharFile = 0;
	for (int i = 0; *(ptrBufferReaded + i) != '\0'; i++)
	{
		iCantCharFile++;
	}

	FileUtils::TList* ptrNewList = new FileUtils::TList;
	std::string myCurrentNumString;
	//Recorro el bucle comparando las cadenas
	for (int i = 0; i < iCantCharFile; i++)
	{
		if ((*(ptrBufferReaded + i) != comaChar) && (*(ptrBufferReaded + i) != spaceChar) && (*(ptrBufferReaded + i) != endTextChar))
		{
			myCurrentNumString += *(ptrBufferReaded + i);
			//std::cout << "Current Read Number " << myCurrentNumString << "\n";
			//std::cout << "Letra de Buffer[" << i << "] " << *(ptrBufferReaded + i) << "\n";
		}
		else
		{
			if (myCurrentNumString!="")
			{
				char* auxCurrentChar = new char[myCurrentNumString.size() + 1]; //NEW SIN DELETE! CUIDAO
				std::copy(myCurrentNumString.begin(), myCurrentNumString.end(), auxCurrentChar);
				auxCurrentChar[myCurrentNumString.size()] = '\0';
				std::cout << "Letra de Buffer[" << i << "] " << auxCurrentChar << "\n";

				ptrNewList->Push(auxCurrentChar);
				myCurrentNumString.clear();
			}

		}

		//delete auxChar;
	}

	return ptrNewList;
}


