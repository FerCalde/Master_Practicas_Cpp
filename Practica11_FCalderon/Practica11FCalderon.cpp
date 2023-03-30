// Practica11FCalderon.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#pragma once
#include "TList.h"


int main()
{

	TList* miListaOriginal = new TList();
	int auxPorDevolverInt = 0;
	// std::cout << "Lista creada!\n"<<"\tEsta lista tiene: "<< miLista->ElementsCounter() <<" Elementos (NUEVA)"<< "\n";

	auxPorDevolverInt = miListaOriginal->Push("Hola");
	auxPorDevolverInt = miListaOriginal->Push("mi");
	auxPorDevolverInt = miListaOriginal->Push("nombre");
	auxPorDevolverInt = miListaOriginal->Push("es");
	auxPorDevolverInt = miListaOriginal->Push("Fer");


	std::cout << "Lista ORIGINAL creada!\n" << "\tEsta lista tiene: " << miListaOriginal->ElementsCounter() << " Elementos" << "\n";

	std::cout << "\n\tEl elemento-" << miListaOriginal->GetCurrentElementID() << "- es [" << miListaOriginal->GetFirstElement() << "]" << "\n";

	while (miListaOriginal->m_ptrIterator->m_nextNode) //Recorre toda la lista hasta que el iterador no encuentra un nodo siguiente
	{
		std::cout << "\n\tEl elemento-" << miListaOriginal->GetCurrentElementID() << "- es [" << miListaOriginal->GetNextElement() << "]" << "\n";
	}



	TList* miListaCopiada = new TList(miListaOriginal);

	std::cout << "\n\n\nLista COPIADA!\n" << "\tEsta lista tiene: " << miListaCopiada->ElementsCounter() << " Elementos" << "\n";

	std::cout << "\tEl primer elemento-" << miListaCopiada->GetCurrentElementID() << "- es [" << miListaCopiada->GetFirstElement() << "]" << "\n";

	while (miListaCopiada->m_ptrIterator->m_nextNode)
	{
		std::cout << "\n\tEl elemento-" << miListaCopiada->GetCurrentElementID() << "- es [" << miListaCopiada->GetNextElement() << "]" << "\n";

	}

	/*std::cout << "\n\n\tEl Ultimo elemento es [" << miListaCopiada->GetLastElement() << "]" << "\n Voy a mostrar los nodos desde atras de la lista hacia delante\n\n";

	while (miListaCopiada->GetCurrentElementID()>=0)
	{
		std::cout << "\n\tEl elemento-" << miListaCopiada->GetCurrentElementID() << "- es [" << miListaCopiada->GetPreviousElement() << "]" << "\n";
	}*/





	TList miListaInvertida = TList::GetReverseList(miListaOriginal);
	//TList* ptrMiListaInvert = &miListaInvertida;
	std::cout << "\nLista Reverse!\n" << "\tEsta lista tiene: " << miListaInvertida.ElementsCounter() << " Elementos" << "\n";
	std::cout << "\tEl primer elemento-" << miListaInvertida.GetCurrentElementID() << "- es [" << miListaInvertida.GetFirstElement() << "]" << "\n";
	while (miListaInvertida.m_ptrIterator->m_nextNode)
	{
		std::cout << "\n\tEl elemento-" << miListaInvertida.GetCurrentElementID() << "- es [" << miListaInvertida.GetNextElement() << "]" << "\n";
	}



	std::cout << "\n\n\tREPITO LISTA INVERTIDA [" << miListaInvertida.GetFirstElement() << "]" << "\n";
	while (miListaInvertida.m_ptrIterator->m_nextNode)
	{
		std::cout << "\n\tEl elemento-" << miListaInvertida.GetCurrentElementID() << "- es [" << miListaInvertida.GetNextElement() << "]" << "\n";
	}



	std::cout << "\n\n\n\nSEGUNDA VUELTA A LAS LISTAS\n\n\n\n";

	std::cout << "Lista ORIGINAL creada!\n" << "\tEsta lista tiene: " << miListaOriginal->ElementsCounter() << " Elementos" << "\n";

	std::cout << "\n\tEl elemento-" << miListaOriginal->GetCurrentElementID() << "- es [" << miListaOriginal->GetFirstElement() << "]" << "\n";

	while (miListaOriginal->m_ptrIterator->m_nextNode) //Recorre toda la lista hasta que el iterador no encuentra un nodo siguiente
	{
		std::cout << "\n\tEl elemento-" << miListaOriginal->GetCurrentElementID() << "- es [" << miListaOriginal->GetNextElement() << "]" << "\n";
	}


	std::cout << "\n\n\nLista COPIADA!\n" << "\tEsta lista tiene: " << miListaCopiada->ElementsCounter() << " Elementos" << "\n";

	std::cout << "\tEl primer elemento-" << miListaCopiada->GetCurrentElementID() << "- es [" << miListaCopiada->GetFirstElement() << "]" << "\n";

	while (miListaCopiada->m_ptrIterator->m_nextNode)
	{
		std::cout << "\n\tEl elemento-" << miListaCopiada->GetCurrentElementID() << "- es [" << miListaCopiada->GetNextElement() << "]" << "\n";

	}



	std::cout << "\nLista Reverse!\n" << "\tEsta lista tiene: " << miListaInvertida.ElementsCounter() << " Elementos" << "\n";
	std::cout << "\tEl primer elemento-" << miListaInvertida.GetCurrentElementID() << "- es [" << miListaInvertida.GetFirstElement() << "]" << "\n";
	while (miListaInvertida.m_ptrIterator->m_nextNode)
	{
		std::cout << "\n\tEl elemento-" << miListaInvertida.GetCurrentElementID() << "- es [" << miListaInvertida.GetNextElement() << "]" << "\n";
	}



	std::cout << "\n\n\tREPITO LISTA INVERTIDA [" << miListaInvertida.GetFirstElement() << "]" << "\n";
	while (miListaInvertida.m_ptrIterator->m_nextNode)
	{
		std::cout << "\n\tEl elemento-" << miListaInvertida.GetCurrentElementID() << "- es [" << miListaInvertida.GetNextElement() << "]" << "\n";
	}



	//std::cout << "\n\n\tEl anterior al Utlimo elemento es [" << miListaCopiada->m_tailTList->m_previousNode->GetNodeData() << "]" << "\n\n\n";
	//std::cout << "\n\n\tEl anterior al Utlimo elemento es [" << miListaCopiada->m_tailTList->m_previousNode->GetNodeData() << "]" << "\n\n\n";


	//std::cout << "\n\n\nLista COPIADA!\n" << "\tEsta lista tiene: " << miListaCopiada->ElementsCounter() << " Elementos" << "\n";
	////std::cout << "\nReiniciar siguiente elemento mediante FirstElement\n";

	////std::cout << "\n\tEl primer elemento es [" << miLista->FirstElement() << "]" << "\n";
	////std::cout << "\tEl Siguiente elemento es [" << miLista->NextElement() << "]" << "\n";
	////std::cout << "\tEl Siguiente elemento es [" << miLista->NextElement() << "]" << "\n";
	////std::cout << "\tEl Siguiente elemento es [" << miLista->NextElement() << "]" << "\n";

	//std::cout << "\n\n\n\n\n\n\nVoy a sacar el primer Elemento que es [" << miLista->Pop() << "]\n\n\n\n\n\n";
	//std::cout << "\n\n\n\n\n\n\nVoy a sacar el primer Elemento que es [" << miLista->Pop() << "]\n\n\n\n\n\n";
	//std::cout << "\n\n\n\n\n\n\nVoy a sacar el primer Elemento que es [" << miLista->Pop() << "]\n\n\n\n\n\n";
	//std::cout << "\n\n\n\n\n\n\nVoy a sacar el primer Elemento que es [" << miLista->Pop() << "]\n\n\n\n\n\n";
	//std::cout << "\n\n\n\n\n\n\nVoy a sacar el primer Elemento que es [" << miLista->Pop() << "]\n\n\n\n\n\n";




	//std::cout << "Lista creada!\n" << "\tEsta lista tiene: " << miLista->ElementsCounter() << " Elementos" << "\n";

	//std::cout << "\n\tEl elemento-" << miLista->CurrentElementID() << "- es [" << miLista->GetFirstElement() << "]" << "\n";
	//std::cout << "\n\tEl elemento-" << miLista->CurrentElementID() << "- es [" << miLista->GetNextElement() << "]" << "\n";
	//std::cout << "\n\tEl elemento-" << miLista->CurrentElementID() << "- es [" << miLista->GetNextElement() << "]" << "\n";
	//std::cout << "\n\tEl elemento-" << miLista->CurrentElementID() << "- es [" << miLista->GetNextElement() << "]" << "\n";
	//std::cout << "\n\tEl elemento-" << miLista->CurrentElementID() << "- es [" << miLista->GetNextElement() << "]" << "\n";
	//std::cout << "\n\tEl elemento-" << miLista->CurrentElementID() << "- es [" << miLista->GetNextElement() << "]" << "\n";

	//std::cout << "\n\n\nLista COPIADA!\n" << "\tEsta lista tiene: " << miListaCopiada->ElementsCounter() << " Elementos" << "\n";

	////// //std::cout << "\tEsta lista tiene: "<< miLista->ElementsCounter() <<" Elementos"<< "\n";

	//std::cout << "\tEl primer elemento-" << miListaCopiada->CurrentElementID() << "- es [" << miListaCopiada->GetFirstElement() << "]" << "\n";
	//std::cout << "\n\tEl elemento-" << miListaCopiada->CurrentElementID() << "- es [" << miListaCopiada->GetNextElement() << "]" << "\n";
	//std::cout << "\n\tEl elemento-" << miListaCopiada->CurrentElementID() << "- es [" << miListaCopiada->GetNextElement() << "]" << "\n";
	//std::cout << "\n\tEl elemento-" << miListaCopiada->CurrentElementID() << "- es [" << miListaCopiada->GetNextElement() << "]" << "\n";
	//std::cout << "\n\tEl elemento-" << miListaCopiada->CurrentElementID() << "- es [" << miListaCopiada->GetNextElement() << "]" << "\n";
	//std::cout << "\n\tEl elemento-" << miListaCopiada->CurrentElementID() << "- es [" << miListaCopiada->GetNextElement() << "]" << "\n";
	//std::cout << "\n\tEl elemento-" << miListaCopiada->CurrentElementID() << "- es [" << miListaCopiada->GetNextElement() << "]" << "\n";
	//std::cout << "\n\tEl elemento-" << miListaCopiada->CurrentElementID() << "- es [" << miListaCopiada->GetNextElement() << "]" << "\n";
	//std::cout << "\n\tEl elemento-" << miListaCopiada->CurrentElementID() << "- es [" << miListaCopiada->GetNextElement() << "]" << "\n";


	////std::cout << "\nReiniciar siguiente elemento mediante FirstElement\n";
	////std::cout << "\n\tEl primer elemento es [" << miLista->FirstElement() << "]" << "\n";
	////std::cout << "\tEl Siguiente elemento es [" << miLista->NextElement() << "]" << "\n";
	////std::cout << "\tEl Siguiente elemento es [" << miLista->NextElement() << "]" << "\n";
	////std::cout << "\tEl Siguiente elemento es [" << miLista->NextElement() << "]" << "\n";
	////std::cout << "\tEl Siguiente elemento es [" << miLista->NextElement() << "]" << "\n";
	////std::cout << "\tEl Siguiente elemento es [" << miLista->NextElement() << "]" << "\n";



	////std::cout << "\nElimino todos los Elementos con Reset()\n";
	////miLista->Reset();



	////std::cout << "\nReiniciar siguiente elemento mediante FirstElement\n";
	////std::cout << "\n\tEl primer elemento es [" << miLista->FirstElement() << "]" << "\n";
	////std::cout << "\tEl Siguiente elemento es [" << miLista->NextElement() << "]" << "\n";
	////std::cout << "\tEl Siguiente elemento es [" << miLista->NextElement() << "]" << "\n";
	////std::cout << "\tEl Siguiente elemento es [" << miLista->NextElement() << "]" << "\n";
	////std::cout << "\tEl Siguiente elemento es [" << miLista->NextElement() << "]" << "\n";
	////std::cout << "\tEl Siguiente elemento es [" << miLista->NextElement() << "]" << "\n";




	////std::cout << "\nMeto nuevos elementos a la lista\n";
	////auxPorDevolverInt = miLista->Push("Adios");
	////auxPorDevolverInt = miLista->Push("mi");
	////auxPorDevolverInt = miLista->Push("nombre");
	////auxPorDevolverInt = miLista->Push("Cambio");
	////auxPorDevolverInt = miLista->Push("Marta");
	////auxPorDevolverInt = miLista->Push(" ");


	////std::cout << "\nReiniciar siguiente elemento mediante FirstElement\n";
	////std::cout << "\n\tEl primer elemento es [" << miLista->FirstElement() << "]" << "\n";
	////std::cout << "\tEl Siguiente elemento es [" << miLista->NextElement() << "]" << "\n";
	////std::cout << "\tEl Siguiente elemento es [" << miLista->NextElement() << "]" << "\n";
	////std::cout << "\tEl Siguiente elemento es [" << miLista->NextElement() << "]" << "\n";
	////std::cout << "\tEl Siguiente elemento es [" << miLista->NextElement() << "]" << "\n";
	////std::cout << "\tEl Siguiente elemento es [" << miLista->NextElement() << "]" << "\n";

	////std::cout << "\nHello World!\n";



	//TList miLista;
	//int auxSuda = 0;
	////std::cout << "Lista creada!\n" << "\tEsta lista tiene: " << miLista.ElementsCounter() << "Elementos (NUEVA)" << "\n";


	//std::cout << "Lista creada!\n" << "\tEsta lista tiene: " << miLista.ElementsCounter() << " Elementos" << "\n";


	//std::cout << "Hello World!\n";

	//miLista.Push("t");
	//miLista.Push("s");
	//std::cout << "Lista creada!\n" << "\tEsta lista tiene: " << miLista.ElementsCounter() << " Elementos" << "\n";

	std::cout << "\nDestuir Lista Original-";
	delete miListaOriginal;
	miListaOriginal = nullptr;
	std::cout << "\nDestuir Lista Copiada-";
	delete miListaCopiada;
	miListaCopiada = nullptr;

	std::cout << "\nDestuir Lista Invertida (SE HACE AUTOMATICO ANTES DE SALIR DEL SCOPE)-";
	//delete ptrMiListaInvert;
	//ptrMiListaInvert = nullptr;

	return 0;
}
