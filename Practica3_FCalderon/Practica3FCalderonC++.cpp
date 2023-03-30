// Practica3FCalderonC++.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

std::string RetornarCadena(std::string _tableStrings[], int _index);
const char* RetornarCadena(const char* _cTabla[], int _iIndex);
//char* RetornarCadenaInversa(const char* _cTabla[], int _iIndex);
 char* RetornarCadenaInversa(const char* _cTabla[], int _iIndex);


 char* InvertidaReturn = nullptr;

int main()
{
	const char* tablaCadenas[] = { "Hola", "TodoBien", "ChaoChaoChao" };
	/*
	const char* cadenaRetorno = RetornarCadena(tablaCadenas, 0);
	std::cout << cadenaRetorno << "\n";

	const char* cadenaRetorno1 = RetornarCadena(tablaCadenas, 1);
	std::cout << cadenaRetorno1 << "\n";

	const char* cadenaRetorno2 = RetornarCadena(tablaCadenas, 2);
	std::cout << cadenaRetorno2 << "\n";

	const char* cadenaRetorno3 = RetornarCadena(tablaCadenas, 3);
	std::cout << cadenaRetorno3 << "\n";

	const char* cadenaRetorno4 = RetornarCadena(tablaCadenas, 4);
	std::cout << cadenaRetorno4 << "\n";

	const char* cadenaRetorno5 = RetornarCadena(tablaCadenas, 5);
	std::cout << cadenaRetorno5 << "\n";
	*/


	const char* cadenaRetorno = RetornarCadenaInversa(tablaCadenas, 0);
	std::cout << cadenaRetorno << "\n";
	const char cc[] = { *cadenaRetorno };
	//std::cout << cc << "\n";
	//const char* cc2[] = { const_cast<const char*>( RetornarCadenaInversa(tablaCadenas, 0)) };
	//std::cout << *cc2 << "\n";
	const char* cadenaRetorno1 = RetornarCadenaInversa(tablaCadenas, 1);
	std::cout << cadenaRetorno1 << "\n";
	const char* cadenaRetorno2 = RetornarCadenaInversa(tablaCadenas, 2);
	std::cout << cadenaRetorno2 << "\n";
	const char* cadenaRetorno3 = RetornarCadenaInversa(tablaCadenas, 3);
	std::cout << cadenaRetorno3 << "\n";
	const char* cadenaRetorno4 = RetornarCadenaInversa(tablaCadenas, 4);
	std::cout << cadenaRetorno4 << "\n";

	std::cout << "\n\nHello World!\n\n";



	//std::string[] tableCharacters = { "Hola", "TodoBien", "ChaochaoChaoChaoo" };
	std::cout << "Hello World!\n\n";

	std::string tableStrings[] = { "Hola", "TodoBien", "ChaochaoChaoChaoo" };

	std::string resultado = RetornarCadena(tableStrings, 0);
	std::cout << resultado << "\n";

	std::string resultado1 = RetornarCadena(tableStrings, 1);
	std::cout << resultado1 << "\n";

	std::string resultado2 = RetornarCadena(tableStrings, 2);
	std::cout << resultado2 << "\n";

	std::string resultado3 = RetornarCadena(tableStrings, 3);
	std::cout << resultado3 << "\n";

	std::string resultado4 = RetornarCadena(tableStrings, 4);
	std::cout << resultado4 << "\n";

	std::string resultado5 = RetornarCadena(tableStrings, 5);
	std::cout << resultado5 << "\n";

	//std::cout << cadenaRetorno << "\n";
	//std::cout << cc << "\n";
	//std::cout << *cc2 << "\n";
	//char* result[]{ nullptr };
}

/*
char* RetornarCadena(std::string *tableStrings[], int index)
{
	int lengthTable = sizeof(*tableStrings-1);
	if (lengthTable > index)
	{
		//*result = reinterpret_cast<char*>(*tableStrings[index]);
		//return result;
	}

}*/

const char* RetornarCadena(const char* _cTabla[], int _iIndex)
{
	const int iSizeTable = sizeof(_cTabla); ///sizeof(*pTable);
	//printf("%d\n", iSizeTable);

	if ((iSizeTable - 1) > _iIndex)
	{
		return _cTabla[_iIndex];
	}
	else
	{
		return "Error: Index NOT FOUND. Out of Scope";
	}

}


std::string RetornarCadena(std::string _tableStrings[], int _index)
{
	int lengthTable = sizeof(_tableStrings - 1);
	printf("%d\n", _index);
	if (lengthTable - 1 > _index)
	{
		return _tableStrings[_index];
	}
	else
	{
		return "INDEX NOT FOUND";
	}
}


char* RetornarCadenaInversa(const char* _cTabla[], int _iIndex)
{
	const int iSizeTable = sizeof(_cTabla); ///sizeof(*pTable);


	if ((iSizeTable - 1) > _iIndex)
	{
		const char* cadenaWord[] = { (_cTabla[_iIndex]) };
		//std::cout << *cadenaWord;

		char* auxCandenaWord = const_cast<char*>(*cadenaWord);
		const int iSizeWord = strlen(*cadenaWord);
		
		std::cout << "\n lenght de la palabra " << iSizeWord << "\n";
		//printf("%d\n", iSizeWord);

		int iAux = iSizeWord-1;
		char cInv[256] = { 0 };

		for ( int i = 0; i < iSizeWord; i++)
		{
			if (iAux >= 0)
			{
				cInv[i] = auxCandenaWord[iAux];
				printf("%c\n", cInv[i]);
				iAux--;
			}

		}

		InvertidaReturn = const_cast<char*>(cInv);
		return InvertidaReturn;
	}
	else
	{
		char* outOfBound = const_cast<char*> ("\nError: Index NOT FOUND. Out of Scope" );
		return outOfBound;
	}

}


/*
char* RetornarCadenaInversa(const char* _cTabla[], int _iIndex)
{
	const int iSizeTable = sizeof(_cTabla); ///sizeof(*pTable);


	if ((iSizeTable - 1) > _iIndex)
	{
		//const char** pCadena[] = (*_cTabla[_iIndex]);
		const char* cadenaWord[] = { (_cTabla[_iIndex]) };
		char** cWord[] = { const_cast<char**>(cadenaWord) };
		std::cout << *cadenaWord;

		const int iSizeWord = strlen(_cTabla[_iIndex]);
		std::cout << "\n a ver esto " << iSizeWord << "\n";

		/*
		//int iAux = iSizeTable - 1;
		for (const int i = 0; i < iSizeWord; i++)
		{
			if (iAux > 0)
			{
				iAux--;
				//charInversa[i] = *(cadenaWord + iAux);

			}

		}



		return **cWord;
	}
	else
	{
		char outOfBound[] = { "Error: Index NOT FOUND. Out of Scope" };
		return outOfBound;
	}

}
*/