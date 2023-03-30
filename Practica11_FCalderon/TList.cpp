#include "TList.h"

TList::TList()
{
	//std::cout << "\Constructor de TList\n";

	m_headTList = nullptr;
	m_tailTList = nullptr;
	m_ptrIterator = nullptr;
	m_num_nodes = 0;
}
TList::TList(TList*& other)
{
	//std::cout << "\Constructor de COPIA TList\n";

	m_num_nodes = 0;
	m_headTList = nullptr;
	m_tailTList = nullptr;

	m_ptrIterator = nullptr;
	Node* auxNode = nullptr;
	if (!other->m_headTList)//Si la lista original esta vacia, seteo las variables para que tb lo esten
	{
		m_headTList = nullptr;
		m_ptrIterator = nullptr;
		m_num_nodes = 0;
	}
	else
	{
		Push(other->m_headTList->m_data);
		auxNode = other->m_headTList->GetNextNode();
	}

	while (auxNode)
	{
		Push(auxNode->m_data);
		auxNode = auxNode->GetNextNode();
	}
	m_num_nodes = ElementsCounter();
	
	
	std::cout<<"\nDESTRUIR EL AUXNODE DEL CONSTRUCTOR COPIA\n";
	delete auxNode;
	auxNode = nullptr;

	////if (!other->m_headTList) //Si la lista original esta vacia, seteo las variables para que tb lo esten
	////{
	////	m_headTList = nullptr;
	////	m_ptrIterator = nullptr;
	////	m_num_nodes = 0;
	////}
	////else
	////{
	////	while (!other->NextElement())  //Bucle que utiliza los metodos existentes para crear nuevos nodos y asignarlos a la nueva lista Utilizando la aritmetica de punteros sobre la lista original
	////	{
	////		//(EN LISTA ORIGINAL) En el primer nodo, ptrIterator seria igual a headtTlist. por tanto (EN NUEVA LISTA) hago un push con el valor que tiene el ptrIterator(OriginalList). 
	////		std::cout << "Elemento nuevo CONSTRUCTOR COPIA " <<Push(other->m_ptrIterator->GetNodeData())<<"\n";
	////		//Itero la lista original para que avance el ptrIterator al siguiente elemento.
	////		other->NextElement();
	////	}
	////	/*newNodeForList = other->m_headTList;
	////	
	////	if (!m_headTList)
	////	{
	////		m_headTList = other->m_headTList;
	////		Push()
	////	}
	////	Push()*/
	////}


}

TList::~TList()
{
	std::cout << "\nDestructor de TList\n";
	m_headTList = nullptr;
	m_tailTList = nullptr;
	m_ptrIterator = nullptr;

	delete m_headTList;
	delete m_tailTList;
	delete m_ptrIterator;
	//delete this;
}

int TList::ElementsCounter()
{
	//Node* auxCounter = m_ptrIterator; //Hace un new interno!
	int iAuxCounter = 0;
	if (m_headTList != nullptr)
	{
		m_ptrIterator = m_headTList;
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
	Node* newNode = new Node(); //OJO DELETE. Quien llama lo destruye(?) EN este caso no. Cada Trozo de memoria donde se crea este NEW se libera con el pop.
	newNode->m_data = _dataNewNode;
	newNode->m_idNode = m_num_nodes;

	if (m_headTList == nullptr) //Para el primer elemento que incluye 
	{
		m_headTList = newNode;
		m_ptrIterator = m_headTList; //apunta al primer elemento de la lista;		
		m_tailTList = m_headTList;
	}
	else
	{
		//Utilizo el iterado, que apunta a head para setear la variable auxiliar
		while (m_ptrIterator->m_nextNode != nullptr)
		{
			m_ptrIterator = m_ptrIterator->m_nextNode;
		}


		newNode->m_previousNode = m_ptrIterator; //En el nuevo nodo, le digo que el iterador en ese momento sera su nodo previo
		m_ptrIterator->m_nextNode = newNode; //Como al siguiente nodo del iterador le digo que sera el new node, la linea anterior cobra su sentido
		m_tailTList = m_ptrIterator->m_nextNode;

		m_ptrIterator = m_headTList; //Vuelvo a poner el iterador en su sitio

									 //Node* auxNode = m_ptrIterator->GetNextNode(); 
		/*while (auxNode->m_nextNode != nullptr)
		{
			auxNode = auxNode->m_nextNode;
		}*/

		/*if (m_ptrIterator->m_nextNode = nullptr)
		{

		}*/

	}

	m_num_nodes++;
	//std::cout << "NEW NODE ANTES " << newNode<<"\n";
	newNode = nullptr;
	//std::cout << "NEW NODE Deleted " << newNode<<"\n\n";
	return 1;
}

int TList::GetCurrentElementID()
{
	if (m_headTList != nullptr)
	{
		if (m_ptrIterator)
		{
			return m_ptrIterator->GetNodeID();
		}
		else
		{
			return -1; //NUNCA ENTRA POR AQUI, SIEMPRE QUE HAY UN HEADLIST EL ITERADOR SERA != NULL
		}
	}
	else
	{
		return -1;

	}

}

const char* TList::GetCurrentElementData()
{
	if (m_headTList != nullptr)
	{
		if (m_ptrIterator != nullptr)
		{
			return m_ptrIterator->GetNodeData();
		}
		else
		{
			return "Error! Null prtIterator! (TList->GetCurrentElement() )\n";
		}
	}
	else
	{
		return "NO CURRENT ELEMENT DATA. List is empty. (TList->GetCurrentElement() )\n";
	}
}

const char* TList::GetFirstElement()
{
	if (m_headTList != nullptr)
	{
		m_ptrIterator = m_headTList; //Muevo el iterador a la primera posicion
		//Devuelvo el valor data almacenado en el Head de la lista
		return m_ptrIterator->GetNodeData();
	}
	else
	{
		return "Error! NULL HEAD, lista vacia";
	}
}
const char* TList::GetLastElement()
{
	if (m_tailTList)
	{
		m_ptrIterator = m_tailTList; //Muevo el iterador a la ultima posicion
		return m_ptrIterator->GetNodeData();
	}
	else
	{
		return "Error! NULL TAIL, lista vacia";
	}
}
//Node* TList::GetElement(Node* _auxNode)
//{
//	if (m_headTList != nullptr) //La lista no puede estar vacia! No habria un siguiente Element
//	{
//		return _auxNode;
//	}
//	return  m_ptrIterator;
//}
//const char* TList::GetCurrentElement()
//{
//	if (m_headTList != nullptr) //La lista no puede estar vacia! No habria un siguiente Element
//	{
//		return m_ptrIterator.Get;
//	}
//	
//}
const char* TList::GetNextElement()
{
	if (m_headTList != nullptr) //La lista no puede estar vacia! No habria un siguiente Element
	{
		if (m_ptrIterator->GetNextNode() != nullptr)
		{
			m_ptrIterator = m_ptrIterator->GetNextNode();
			return m_ptrIterator->GetNodeData();
			//const char* auxNextData = m_ptrIterator->m_data;
			//
			//
			//const char* auxNextData = m_ptrIterator->m_data; //Guardo en variable auxiliar para modificar el iterador antes de retornar el valor
			//m_ptrIterator->m_nextNode;
			////const char* auxNextData = m_ptrIterator->m_data; //Guardo en variable auxiliar para modificar el iterador antes de retornar el valor
			//
			//return auxNextNode->m_data;
			//return m_ptrIterator->m_data;
		}
		else
		{
			//Hacer lista circular: Vuelve al inicio cuando se acaba la lista
			//m_ptrIterator = m_headTList;
			//De esta manera creo una lista circular
			return GetFirstElement();
			//return "No hay mas Elementos en la lista. Retorno al principio de la misma";
		}

	}
	else
	{
		return "Error! NULL HEAD, lista vacia, no hay un Next Element";
	}
}
const char* TList::GetPreviousElement()
{
	if (m_headTList)
	{
		if (m_ptrIterator->GetPreviousNode()) //Si el iterador no encuentra un nodo previo significa que estamos en la primera posicion 
		{
			m_ptrIterator = m_ptrIterator->GetPreviousNode();
			return m_ptrIterator->GetNodeData();
		}
		else
		{
			return "Error! Estas en el Primer Elemento de la Tabla, no hay anteriores!";
		}
	}

	else //ESTA VACIA LA LISTA
	{
		return "Error! NULL HEAD, lista vacia, no hay Elementos";
	}
}



const char* TList::Pop()
{
	if (m_headTList != nullptr)
	{
		Node* auxElementErase = m_headTList;

		//DevolverContenido del primer elemento
		const char* firstElementBeforeDelet = GetFirstElement();
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


TList TList::GetReverseList(TList _originalList)
{
	//std::cout << "Creo una newTList Auxiliar\n";
	TList auxReverseList; //Puntero auxiliar a la zona de memoria donde creo la nueva lista (NEW!) se deletea cuando en el destructor de la Lista
	
	
	//std::cout << "Creo una newTList como puntero de _OriginalList\n";
	TList* auxOriginList = new TList(_originalList);

	////auxOriginList->m_ptrIterator = auxOriginList->m_tailTList;
	////while (auxOriginList->m_ptrIterator) //Mientras que el id del nodo sea mayor o igual a 0 significa que aun no hemos llegado al principio de la lista 
	////{
	////	if (!auxReverseList.m_headTList)
	////	{
	////		auxReverseList.Push(auxOriginList->m_ptrIterator->m_data);//Situo la lista original en la ultima posicion.		 
	////		auxReverseList.m_headTList->m_nextNode = nullptr;
	////	}
	////	else
	////	{
	////		auxReverseList.Push(auxOriginList->m_ptrIterator->m_data); //le paso el valor que tenga ese nodo (Comienza con iterador en ultima posicion)
	////	}
	////	auxOriginList->m_ptrIterator = auxOriginList->m_ptrIterator->m_previousNode;
	////	
	////}

	auxOriginList->GetLastElement();
	while (auxOriginList->m_ptrIterator) //Mientras que el id del nodo sea mayor o igual a 0 significa que aun no hemos llegado al principio de la lista 
	{
		//if (!auxReverseList.m_headTList)
		//{
		//	auxReverseList.Push(auxOriginList->GetCurrentElementData());//Situo la lista original en la ultima posicion.		 
		//	//auxReverseList.m_headTList->m_nextNode = nullptr;
		//}
		//else
		//{
		//	auxReverseList.Push(auxOriginList->GetCurrentElementData());
		//	//auxReverseList.Push(auxOriginList->m_ptrIterator->m_data); //le paso el valor que tenga ese nodo (Comienza con iterador en ultima posicion)
		//	//auxReverseList.Push(auxOriginList->GetPreviousElement()); //le paso el valor que tenga ese nodo (Comienza con iterador en ultima posicion)
		//}
		auxReverseList.Push(auxOriginList->GetCurrentElementData());
		auxOriginList->m_ptrIterator = auxOriginList->m_ptrIterator->m_previousNode;

	}


	delete auxOriginList;
	auxOriginList = nullptr;
	return auxReverseList;
}