#pragma once

#include <iostream>
#include <stdlib.h>


//#include "Node.h"


template<typename T>
class TList
{
public:



	class Node
	{
	public:
		Node()
		{
			m_nextNode = nullptr;
			m_data = NULL;
		}

		~Node()
		{

			m_nextNode = nullptr;
			//m_data = nullptr;
			delete m_nextNode;

			//delete m_data;
			std::cout << "\tEliminadas las variables del node\n";
		}

		TList::Node* m_nextNode;
		T GetNodeData()
		{
			return m_data;
		}
		T m_data;
		T GetNextNode()
		{
			return m_nextNode;
		}
	
	};


	

	TList::Node* m_headTList; //Guarda el primer nodo
	TList::Node* m_ptrIterator; //auxiliar para operaciones
	int m_num_nodes;


	TList()
	{
		m_headTList = nullptr;
		m_ptrIterator = nullptr;
		m_num_nodes = 0;
	}


	int ElementsCounter()
	{
		//Node* auxCounter = m_ptrIterator; //Hace un new interno!
		int iAuxCounter = 0;
		if (m_headTList != nullptr)
		{
			iAuxCounter = 1;

		
			while (m_ptrIterator->m_nextNode != nullptr)
			{
				m_ptrIterator = m_ptrIterator->m_nextNode;
				++iAuxCounter;
			}
		}

		m_ptrIterator = m_headTList;
		return iAuxCounter;
	}



	int Push(T _dataNewNode) //Incluye en Final de la TList
	{
		TList::Node* newNode = new TList::Node();
		newNode->m_data = _dataNewNode;

		if (m_headTList == nullptr) //Para el primer elemento que incluye 
		{
			m_headTList = newNode;
			m_ptrIterator = m_headTList; //apunta al primer elemento de la lista;
		}
		else
		{
			//Utilizo el iterado, que apunta a head para setear la variable auxiliar

			while (m_ptrIterator->m_nextNode != nullptr)
			{
				m_ptrIterator = m_ptrIterator->m_nextNode;
			}

			
			m_ptrIterator->m_nextNode = newNode;
			m_ptrIterator = m_headTList; //Vuelvo a poner el iterador en su sitio
		}

		m_num_nodes++;

		return 1;
	}

	T FirstElement()
	{
		if (m_headTList != nullptr)
		{
			m_ptrIterator = m_headTList; //Muevo el iterador a la primera posicion
		}
			return m_headTList->GetNodeData();
	/*	else
		{
			return "Error! NULL HEAD, lista vacia";
		}*/
		//Devuelvo el valor data almacenado en el Head de la lista
	}

	T NextElement()
	{
		if (m_headTList != nullptr) //La lista no puede estar vacia! No habria un siguiente Element
		{

			if (m_ptrIterator->m_nextNode != nullptr)
			{
				m_ptrIterator = m_ptrIterator->m_nextNode;
			
			}
			else
			{
		
				return FirstElement();

			}

		}
				return m_ptrIterator->GetNodeData();
		//return  "Error! NULL HEAD, lista vacia, no hay un Next Element";
		//else
		//{
		//}
	}

	T Pop()
	{
		if (m_headTList != nullptr)
		{
			TList::Node* auxElementErase = m_headTList;

			//DevolverContenido del primer elemento
			const char* firstElementBeforeDelet = FirstElement();
			//Muevo el puntero head a la nueva primera posicion (El siguiente al anterior HEAD)
			m_headTList = m_headTList->GetNextNode(); //Avanzo la posicion del puntero
			m_ptrIterator = m_headTList;

			delete auxElementErase;


			return firstElementBeforeDelet;
		}


		return "ERROR! LISTA VACIA. No se puede mostrar el numero y eliminarlo";
	}

	void Reset()
	{

		int iElementsToErase = ElementsCounter();

		for (int i = 0; i < iElementsToErase; i++) //Itero tantas veces el Pop (Sacar primero de la Lista) como nodos tenga  
		{
			Pop();
		}

	}





};