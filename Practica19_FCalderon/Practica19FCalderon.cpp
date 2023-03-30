// Practica19FCalderon.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#pragma once
#include "TList.h"


int main()
{
	TList<int> miListaInts;

	miListaInts.Push(1);
	miListaInts.Push(31);
	miListaInts.Push(41);
	miListaInts.Push(15);
	miListaInts.Push(11);


	std::cout<<"Lista de Ints\nLista Element [" << miListaInts.FirstElement()<<"]\n";
	while (miListaInts.m_ptrIterator->m_nextNode)
	{
		std::cout << "Lista Element [" << miListaInts.NextElement() << "]\n";
	}


	TList<const char*> miListaConstChar;
	miListaConstChar.Push("Hola");
	miListaConstChar.Push("HOlitta");
	miListaConstChar.Push("Vecinito");
	
	std::cout << "Lista de ConstChar\nLista Element [" << miListaConstChar.FirstElement() << "]\n";	
	
	while (miListaConstChar.m_ptrIterator->m_nextNode)
	{
		std::cout << "Lista Element [" << miListaConstChar.NextElement() << "]\n";
	}
	return 0;
}
