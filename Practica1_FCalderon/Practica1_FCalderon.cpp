// Practica1_FCalderon.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>

#define MASK_1_BYTE 0x000000FF
#define MASK_BYTE_BULLETS 0x00FF0000
#define MASK_BYTE_BULLETS_2 0xFF00FFFF
#define MASK_BYTE_LIFE 0xFF000000
#define MASK_BYTE_BULLETS_INF 0x0000000F

int GetNumBullets_(unsigned int _iData);

int GetLife_(unsigned int _iData);

int AddBalas_(int _iData, int _iAmount);

bool CheckBalasInfinitas(int _iData);

bool ActiveInfiniteBullets(int _iData);


int main()
{
	unsigned const int  uData(0x554D400C);

	//std::cout << uData << "\n";

	int iCurrentLife(GetLife_(uData));

	std::cout << iCurrentLife << " es la cantidad de vida actual.\n";
	
	int iCurrentBullets = GetNumBullets_(uData);

	std::cout << iCurrentBullets << " es la cantidad de balas actuales.\n";
	

	std::cout << "Recargando Arma... le Sumo 3 balas a las que tenia\n";
	int iBulletPlus = (AddBalas_(uData, 3));

	std::cout << iBulletPlus << " Sumadas balas.\n";

	//uData = AddBalas_(uData, 3); No sirve puesto que uData es constante!
	//

	//iCurrentBullets = GetNumBullets_(uData);
	//std::cout << iCurrentBullets << " es la cantidad de balas actuales despues cambio.\n";


	bool bHasInfiniteBullets = CheckBalasInfinitas(uData);

	std::cout << bHasInfiniteBullets << " Inf Bullets.\n";


	bool bActiveInfiniteBullets = ActiveInfiniteBullets(uData);
	std::cout << bActiveInfiniteBullets << " Active infinite bullets.\n";



	return 0;
}




int GetNumBullets_(unsigned int _iData)
{
	//_iData = 0x054D400C;//
	int iNumBalas(0);

	//Movemos a la derecha los bits para conseguir 0xXXXX054D
	//4 posiciones x 4 bits que ocupa cada una = 16;
	iNumBalas = _iData >> 16;

	//Hacemos un AND para borrar los bits que no nos interesan y dejar 0x0000004D
	iNumBalas &= MASK_1_BYTE;
	//iNumBalas = iNumBalas & MASK_1_BYTE;


	//char* pChar = reinterpret_cast<char*>(&iNumBalas);
	//std::cout << iNumBalas << " cantBalas con Maskara.\n";
	//std::cout << *pChar << " Uno.\n";

	return iNumBalas;
}

int GetLife_(unsigned int _iData)
{
	//_iData = 0x054D400C;//

	int iCantVida(0);

	//Movemos a la derecha los bits para conseguir 0xXXXXXX05
	iCantVida = _iData >> 24;

	//Hago un AND-> borrar bits que no interesan y dejar  dejar 0x00000005
	iCantVida &= MASK_1_BYTE;

	return iCantVida;
}
/*
int AddBalas_(int _iData, int _iAmount)
{
	int iCurrBullets = GetNumBullets_(_iData);
	int iBulletsAdded = iCurrBullets + _iAmount;

	//std::cout << iBulletsAdded << " es la cantidad de balas sumadas.\n";

	//Devuelvo el valor de las balas a la posicion 0xXX
	iBulletsAdded = iBulletsAdded << 16;

	//Limpio los numeros sobrantes
	iBulletsAdded &= MASK_BYTE_BULLETS;


	char* pChar = reinterpret_cast<char*>(&iBulletsAdded);
	//std::cout << iBulletsAdded << " cantBalas2 con Maskara.\n";
	std::cout << *pChar << " cantBalas2 con Maskara en bytes.\n";
	printf("%02hhX", *pChar);

	//Limpio del dato original la parte de las balas (Sobran).
	_iData &= MASK_BYTE_BULLETS2;

	int iDataResultante_ = (iBulletsAdded | _iData);
	//std::cout << iDataResultante_ << " es la cantidad de algo movido.\n";

	return iDataResultante_;
}
*/

int AddBalas_(int _iData, int _iAmount)
{
	int iCantBullets = GetNumBullets_(_iData);
	iCantBullets += _iAmount;

	return iCantBullets;
	//std::cout << iCantBullets << " es la cantidad de balas sumadas.\n";

	////Devuelvo el valor de las balas a la posicion 0xXX
	//iCantBullets = iCantBullets << 16;

	////Limpio los numeros sobrantes
	//iCantBullets &= MASK_BYTE_BULLETS;


	////Limpio del dato original la parte de las balas (Sobran).
	//_iData &= MASK_BYTE_BULLETS_2;

	//int iDataResultante_ = (iCantBullets | _iData);

	//return iDataResultante_;
}

bool CheckBalasInfinitas(int _iData)
{
	//_iData = 0x054D400C;//
	int iInfiniteBullets(0);

	iInfiniteBullets = _iData >> 4; //Deberia quedar  = 0xX054D400;//

	iInfiniteBullets &= MASK_1_BYTE;

	return iInfiniteBullets;
}

bool ActiveInfiniteBullets(int _iData)
{
	int iActiveInfBullets(0);
	iActiveInfBullets = CheckBalasInfinitas(_iData);

	//iActiveInfBullets = (iActiveInfBullets | MASK_BYTE_BULLETS_INF);
	iActiveInfBullets |= MASK_BYTE_BULLETS_INF;
	return iActiveInfBullets;
}