// Practica2FCalderonC++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "Practica2FCalderonC++.h"


int main()
{
	//Ejercicio 2.A: DONE
	Ejercicio2A();


	//Ejercicio 2.B y 2C: DONE
	Ejercicio2ByC();


	// Ejercicio 2.D: DONE
	Ejercicio2D();

	return 0;
}

//Ejercicio 2.A: 

void Ejercicio2A()
{
	int iValue = -559038737;
	//int iValue(566185223);

	char* pCharValue = reinterpret_cast<char*>(&iValue);



	printf("El numero entero %d", iValue);
	printf(" se expresa con los siguientes bytes:\n");

	const int iSizeValue = sizeof(iValue);
	for (int i = 0; i < iSizeValue; i++)
	{
		printf("%02hhX\n", *(pCharValue + i));

		//unsigned int* pIntValue = reinterpret_cast<unsigned int*>(*(pCharValue + i));
	//	std::cout << &pIntValue << "\n";
	}

}

//Ejercicio 2.B y 2C:

void Ejercicio2ByC()
{
	int iTabla[] = { 1, 3, 2, 5, 3, static_cast<int>(0xFFFFFFFF), 2, 6 };

	int* pTable = &iTabla[0];

	const int iSizeTable = sizeof(iTabla) / sizeof(*pTable);

	printf("\nLa siguiente tabla contiene : %d", iSizeTable);
	printf(" numeros\n");

	printf("\nEn la tabla tenemos los siguientes numeros y sus bytes \n");

	int iMaxEntero = 0;
	unsigned char cMaxByte(0);

	for (int i = 0; i < iSizeTable; i++)
	{

		if ((*(pTable + i)) > iMaxEntero)
		{
			iMaxEntero = (*(pTable + i));
		}

		int uICurrentPTableValue = *(pTable + i);
		std::cout << "\n" << uICurrentPTableValue << "\n";

		unsigned char* pCharValue2 = reinterpret_cast<unsigned char*>(&uICurrentPTableValue);
		//std::cout << pCharValue2 << "\n\n";

		int iSizeValue2 = sizeof(uICurrentPTableValue);

		for (int k = 0; k < iSizeValue2; k++)
		{
			printf("%02hhX", *(pCharValue2 + k));
			if (cMaxByte < *(pCharValue2 + k))
			{
				cMaxByte = (*(pCharValue2 + k));
			}
		}

		std::cout << "\n";
	}

	std::cout << "\n\nEntero mas grande con Cout " << iMaxEntero << "\n";
	printf("\nEl entero mas grande de la tabla es (en decimal): %d\n", iMaxEntero);
	printf("\nByte Actual mas grande: %02hhX\n", cMaxByte);

}


// Ejercicio 2.D:
void Ejercicio2D()
{

	//char cadenaChar[] = { 'H', 'o', 'l', 'a', ' ', 'M', 'u', 'n', 'd','o', '\0'};
	//char cadenaChar[] = { "Hola Mundo" };
	char cadenaChar[] = { "Cadena vamos a dar la vuelta! jeje" };
	const int iSizeCadenaChar = sizeof(cadenaChar);

	char cadenaCharInversa[iSizeCadenaChar] = { 0 };

	int iAux = iSizeCadenaChar - 1;

	for (int i = 0; i < iSizeCadenaChar; i++)
	{
		if (iAux > 0) 
		{
			iAux--;
			cadenaCharInversa[i] = cadenaChar[iAux];
		}
	}
	std::cout << "\n\n" << cadenaChar<<"\n" << cadenaCharInversa << "\n";
}