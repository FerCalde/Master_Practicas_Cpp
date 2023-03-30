#pragma once

#include <iostream>
#include <stdlib.h>


#include "Node.h"
#include "Equipo.h"

class TList
{
public:
	TList();

	int ElementsCounter();
	
	int Push(IEquipo* _dataNewNode);
	
	IEquipo* FirstElement();
	IEquipo* NextElement();
	IEquipo* GetElement();
	IEquipo* Pop();
	void Reset();

	Node* m_headTList; //Guarda el primer nodo
	Node* m_ptrIterator; //auxiliar para operaciones
	int m_num_nodes;


};