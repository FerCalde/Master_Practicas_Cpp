#include "TList.h"

TList::TList()
{
	m_headTList = nullptr;
	m_ptrIterator = nullptr;
	m_num_nodes = 0;
}


int TList::ElementsCounter()
{
	//Node* auxCounter = m_ptrIterator; //Hace un new interno!
	int iAuxCounter = 0;
	if (m_headTList != nullptr)
	{
		iAuxCounter = 1;

		/*while (auxCounter->m_nextNode != nullptr)
		{
			auxCounter = auxCounter->m_nextNode;
			++iAuxCounter;
		}*/
		while (m_ptrIterator->m_nextNode != nullptr)
		{
			m_ptrIterator = m_ptrIterator->m_nextNode;
			++iAuxCounter;
		}
	}

	//delete auxCounter; //Borro ese nuevo new
	m_ptrIterator = m_headTList;
	return iAuxCounter;
}



int TList::Push(const char* _dataNewNode) //Incluye en Final de la TList
{
	//Node* newNode = new Node(_newNodeData);
	Node* newNode = new Node();
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

		//Node* auxNode = m_ptrIterator->GetNextNode(); 
		/*while (auxNode->m_nextNode != nullptr)
		{
			auxNode = auxNode->m_nextNode;
		}*/
		m_ptrIterator->m_nextNode = newNode;
		m_ptrIterator = m_headTList; //Vuelvo a poner el iterador en su sitio
	}

	m_num_nodes++;

	return 1;
}

const char* TList::FirstElement()
{
	if (m_headTList != nullptr)
	{
		m_ptrIterator = m_headTList; //Muevo el iterador a la primera posicion
		return m_headTList->GetNodeData();
	}
	else
	{
		return "Error! NULL HEAD, lista vacia";
	}
	//Devuelvo el valor data almacenado en el Head de la lista
}

const char* TList::NextElement()
{
	if (m_headTList != nullptr) //La lista no puede estar vacia! No habria un siguiente Element
	{

		if (m_ptrIterator->GetNextNode() != nullptr)
		{
			m_ptrIterator = m_ptrIterator->GetNextNode();
			//const char* auxNextData = m_ptrIterator->m_data;

			//
			//const char* auxNextData = m_ptrIterator->m_data; //Guardo en variable auxiliar para modificar el iterador antes de retornar el valor
			//m_ptrIterator->m_nextNode;
			////const char* auxNextData = m_ptrIterator->m_data; //Guardo en variable auxiliar para modificar el iterador antes de retornar el valor

			//return auxNextNode->m_data;
			return m_ptrIterator->GetNodeData();
			//return m_ptrIterator->m_data;
		}
		else
		{
			//m_ptrIterator = m_headTList;
			//return "No hay mas Elementos en la lista. Retorno al principio de la misma";

			//Hacer lista circular: Vuelve al inicio cuando se acaba la lista
			return FirstElement();

		}

	}
	else
	{
		return "Error! NULL HEAD, lista vacia, no hay un Next Element";
	}
}

const char* TList::Pop()
{
	if (m_headTList != nullptr)
	{
		Node* auxElementErase = m_headTList;

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

void TList::Reset() 
{
	/*while (m_headTList != nullptr)
	{
		Node* auxElementErase = m_headTList;

	}*/
	int iElementsToErase = ElementsCounter(); 

	for (int i = 0; i < iElementsToErase; i++) //Itero tantas veces el Pop (Sacar primero de la Lista) como nodos tenga  
	{
		Pop(); 
	}

}