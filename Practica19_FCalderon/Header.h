//#pragma once
//
//
//
//#include <iostream>
//#include <stdlib.h>
//
//
////#include "Node.h"
//template<typename T>
//class TList
//{
//public:
//	TList();
//	TList(TList*& other); //Constructor copia
//
//	~TList();
//
//	int ElementsCounter();
//
//	int GetCurrentElementID();
//	T GetCurrentElementData();
//	T Push(T _dataNewNode);
//
//	T GetFirstElement();
//	T GetPreviousElement();
//
//	T GetNextElement();
//	T GetLastElement();
//
//	//Node* GetCurrentElement(Node* _auxNode);
//	T Pop();
//	void Reset();
//
//	Node<T>::Node* m_headTList; //Guarda el primer nodo
//	Node<T>::Node* m_tailTList;
//	Node<T>::Node* m_ptrIterator; //auxiliar para operaciones
//	int m_num_nodes;
//
//
//	//static TList GetReverseList(TList _originalList);
//
//	//static TList GetReverseList(TList _originalList)
//	//{
//	//	//std::cout << "Creo una newTList Auxiliar\n";
//	//	TList auxReverseList; //Puntero auxiliar a la zona de memoria donde creo la nueva lista (NEW!) se deletea cuando en el destructor de la Lista
//
//
//	//	//std::cout << "Creo una newTList como puntero de _OriginalList\n";
//	//	TList* auxOriginList = new TList(_originalList);
//
//
//	//	auxOriginList->GetLastElement();
//	//	while (auxOriginList->m_ptrIterator) //Mientras que el id del nodo sea mayor o igual a 0 significa que aun no hemos llegado al principio de la lista 
//	//	{
//	//		auxReverseList.Push(auxOriginList->GetCurrentElementData());
//	//		auxOriginList->m_ptrIterator = auxOriginList->m_ptrIterator->m_previousNode;
//	//	}
//
//
//	//	delete auxOriginList;
//	//	auxOriginList = nullptr;
//	//	return auxReverseList;
//	//}
//
//
//	//----------------------
//
//	////TList::TList()
//	//TList()
//	//{
//	//	//std::cout << "\Constructor de TList\n";
//
//	//	m_headTList = nullptr;
//	//	m_tailTList = nullptr;
//	//	m_ptrIterator = nullptr;
//	//	m_num_nodes = 0;
//	//}
//
//	//TList(TList*& other)
//	//{
//	//	//std::cout << "\Constructor de COPIA TList\n";
//
//	//	m_num_nodes = 0;
//	//	m_headTList = nullptr;
//	//	m_tailTList = nullptr;
//
//	//	m_ptrIterator = nullptr;
//	//	Node* auxNode = nullptr;
//	//	if (!other->m_headTList)//Si la lista original esta vacia, seteo las variables para que tb lo esten
//	//	{
//	//		m_headTList = nullptr;
//	//		m_ptrIterator = nullptr;
//	//		m_num_nodes = 0;
//	//	}
//	//	else
//	//	{
//	//		Push(other->m_headTList->m_data);
//	//		auxNode = other->m_headTList->GetNextNode();
//	//	}
//
//	//	while (auxNode)
//	//	{
//	//		Push(auxNode->m_data);
//	//		auxNode = auxNode->GetNextNode();
//	//	}
//	//	m_num_nodes = ElementsCounter();
//
//
//	//	std::cout << "\nDESTRUIR EL AUXNODE DEL CONSTRUCTOR COPIA\n";
//	//	delete auxNode;
//	//	auxNode = nullptr;
//	//}
//
//	//~TList()
//	//{
//	//	std::cout << "\nDestructor de TList\n";
//	//	m_headTList = nullptr;
//	//	m_tailTList = nullptr;
//	//	m_ptrIterator = nullptr;
//
//	//	delete m_headTList;
//	//	delete m_tailTList;
//	//	delete m_ptrIterator;
//	//	//delete this;
//	//}
//
//
//
//
//};
//
//// CONSTRUCTORES Y DESTRUCTOR
//template<typename T>
//TList<T>::TList()
//{
//	//std::cout << "\Constructor de TList\n";
//
//	m_headTList = nullptr;
//	m_tailTList = nullptr;
//	m_ptrIterator = nullptr;
//	m_num_nodes = 0;
//}
//
//template<typename T>
//TList<T>::TList(TList*& other)
//{
//	//std::cout << "\Constructor de COPIA TList\n";
//
//	m_num_nodes = 0;
//	m_headTList = nullptr;
//	m_tailTList = nullptr;
//
//	m_ptrIterator = nullptr;
//	Node* auxNode = nullptr;
//	if (!other->m_headTList)//Si la lista original esta vacia, seteo las variables para que tb lo esten
//	{
//		m_headTList = nullptr;
//		m_ptrIterator = nullptr;
//		m_num_nodes = 0;
//	}
//	else
//	{
//		Push(other->m_headTList->m_data);
//		auxNode = other->m_headTList->GetNextNode();
//	}
//
//	while (auxNode)
//	{
//		Push(auxNode->m_data);
//		auxNode = auxNode->GetNextNode();
//	}
//	m_num_nodes = ElementsCounter();
//
//
//	std::cout << "\nDESTRUIR EL AUXNODE DEL CONSTRUCTOR COPIA\n";
//	delete auxNode;
//	auxNode = nullptr;
//}
//
//template<typename T>
//TList<T>::~TList()
//{
//	std::cout << "\nDestructor de TList\n";
//	m_headTList = nullptr;
//	m_tailTList = nullptr;
//	m_ptrIterator = nullptr;
//
//	delete m_headTList;
//	delete m_tailTList;
//	delete m_ptrIterator;
//	//delete this;
//}
//
//
//
////FUNCIONES!
//
//template<typename T>
//int TList<T>::ElementsCounter()
//{
//	//Node* auxCounter = m_ptrIterator; //Hace un new interno!
//	int iAuxCounter = 0;
//	if (m_headTList != nullptr)
//	{
//		m_ptrIterator = m_headTList;
//		iAuxCounter = 1;
//
//
//		while (m_ptrIterator->m_nextNode != nullptr)
//		{
//			m_ptrIterator = m_ptrIterator->m_nextNode;
//			++iAuxCounter;
//		}
//	}
//
//	//delete auxCounter; //Borro ese nuevo new
//	m_ptrIterator = m_headTList;
//	return iAuxCounter;
//}
//
//template<typename T>
//T TList<T>::Push(T _dataNewNode) //Incluye en Final de la TList
//{
//	//Node* newNode = new Node(_newNodeData);
//	Node* newNode = new Node(); //OJO DELETE. Quien llama lo destruye(?) EN este caso no. Cada Trozo de memoria donde se crea este NEW se libera con el pop.
//	newNode->m_data = _dataNewNode;
//	newNode->m_idNode = m_num_nodes;
//
//	if (m_headTList == nullptr) //Para el primer elemento que incluye 
//	{
//		m_headTList = newNode;
//		m_ptrIterator = m_headTList; //apunta al primer elemento de la lista;		
//		m_tailTList = m_headTList;
//	}
//	else
//	{
//		//Utilizo el iterado, que apunta a head para setear la variable auxiliar
//		while (m_ptrIterator->m_nextNode != nullptr)
//		{
//			m_ptrIterator = m_ptrIterator->m_nextNode;
//		}
//
//
//		newNode->m_previousNode = m_ptrIterator; //En el nuevo nodo, le digo que el iterador en ese momento sera su nodo previo
//		m_ptrIterator->m_nextNode = newNode; //Como al siguiente nodo del iterador le digo que sera el new node, la linea anterior cobra su sentido
//		m_tailTList = m_ptrIterator->m_nextNode;
//
//		m_ptrIterator = m_headTList; //Vuelvo a poner el iterador en su sitio
//	}
//
//	m_num_nodes++;
//	//std::cout << "NEW NODE ANTES " << newNode<<"\n";
//	newNode = nullptr;
//	//std::cout << "NEW NODE Deleted " << newNode<<"\n\n";
//	return 1;
//}
//
//template<typename T>
//int TList<T>::GetCurrentElementID()
//{
//	if (m_headTList != nullptr)
//	{
//		if (m_ptrIterator)
//		{
//			return m_ptrIterator->GetNodeID();
//		}
//		else
//		{
//			return -1; //NUNCA ENTRA POR AQUI, SIEMPRE QUE HAY UN HEADLIST EL ITERADOR SERA != NULL
//		}
//	}
//	else
//	{
//		return -1;
//
//	}
//
//}
//
//template<typename T>
//T TList<T>::GetCurrentElementData()
//{
//	if (m_headTList != nullptr)
//	{
//		if (m_ptrIterator != nullptr)
//		{
//			return m_ptrIterator->GetNodeData();
//		}
//		else
//		{
//			return "Error! Null prtIterator! (TList->GetCurrentElement() )\n";
//		}
//	}
//	else
//	{
//		return "NO CURRENT ELEMENT DATA. List is empty. (TList->GetCurrentElement() )\n";
//	}
//}
//
//template<typename T>
//T TList<T>::GetFirstElement()
//{
//	if (m_headTList != nullptr)
//	{
//		m_ptrIterator = m_headTList; //Muevo el iterador a la primera posicion
//		//Devuelvo el valor data almacenado en el Head de la lista
//		return m_ptrIterator->GetNodeData();
//	}
//	else
//	{
//		return "Error! NULL HEAD, lista vacia";
//	}
//}
//
//template<typename T>
//T TList<T>::GetLastElement()
//{
//	if (m_tailTList)
//	{
//		m_ptrIterator = m_tailTList; //Muevo el iterador a la ultima posicion
//		return m_ptrIterator->GetNodeData();
//	}
//	else
//	{
//		return "Error! NULL TAIL, lista vacia";
//	}
//}
//
//template<typename T>
//T TList<T>::GetNextElement()
//{
//	if (m_headTList != nullptr) //La lista no puede estar vacia! No habria un siguiente Element
//	{
//		if (m_ptrIterator->GetNextNode() != nullptr)
//		{
//			m_ptrIterator = m_ptrIterator->GetNextNode();
//			return m_ptrIterator->GetNodeData();
//
//		}
//		else
//		{
//			//De esta manera creo una lista circular
//			return GetFirstElement();
//		}
//
//	}
//	else
//	{
//		return "Error! NULL HEAD, lista vacia, no hay un Next Element";
//	}
//}
//
//template<typename T>
//T TList<T>::GetPreviousElement()
//{
//	if (m_headTList)
//	{
//		if (m_ptrIterator->GetPreviousNode()) //Si el iterador no encuentra un nodo previo significa que estamos en la primera posicion 
//		{
//			m_ptrIterator = m_ptrIterator->GetPreviousNode();
//			return m_ptrIterator->GetNodeData();
//		}
//		else
//		{
//			return "Error! Estas en el Primer Elemento de la Tabla, no hay anteriores!";
//		}
//	}
//
//	else //ESTA VACIA LA LISTA
//	{
//		return "Error! NULL HEAD, lista vacia, no hay Elementos";
//	}
//}
//
//
//template<typename T>
//T TList<T>::Pop()
//{
//	if (m_headTList != nullptr)
//	{
//		Node* auxElementErase = m_headTList;
//
//		//DevolverContenido del primer elemento
//		const char* firstElementBeforeDelet = GetFirstElement();
//		//Muevo el puntero head a la nueva primera posicion (El siguiente al anterior HEAD)
//		m_headTList = m_headTList->GetNextNode(); //Avanzo la posicion del puntero
//		m_ptrIterator = m_headTList;
//
//		delete auxElementErase;
//
//
//		return firstElementBeforeDelet;
//	}
//
//
//	return "ERROR! LISTA VACIA. No se puede mostrar el numero y eliminarlo";
//}
//
//template<typename T>
//void TList<T>::Reset()
//{
//
//	for (int i = 0; i < ElementsCounter(); i++) //Itero tantas veces el Pop (Sacar primero de la Lista) como nodos tenga  
//	{
//		Pop();
//	}
//
//}
//
////template<typename T>
////TList TList<T>::GetReverseList(TList _originalList)
////{
////	//std::cout << "Creo una newTList Auxiliar\n";
////	TList auxReverseList; //Puntero auxiliar a la zona de memoria donde creo la nueva lista (NEW!) se deletea cuando en el destructor de la Lista
////
////
////	//std::cout << "Creo una newTList como puntero de _OriginalList\n";
////	TList* auxOriginList = new TList(_originalList);
////
////
////	auxOriginList->GetLastElement();
////	while (auxOriginList->m_ptrIterator) //Mientras que el id del nodo sea mayor o igual a 0 significa que aun no hemos llegado al principio de la lista 
////	{
////		auxReverseList.Push(auxOriginList->GetCurrentElementData());
////		auxOriginList->m_ptrIterator = auxOriginList->m_ptrIterator->m_previousNode;
////	}
////
////
////	delete auxOriginList;
////	auxOriginList = nullptr;
////	return auxReverseList;
////}