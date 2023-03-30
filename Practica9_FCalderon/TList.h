#pragma once

#include <iostream>
#include <stdlib.h>


#include "Node.h"

class TList
{
public:
	TList();

	int ElementsCounter();
	
	int Push(const char* _dataNewNode);
	
	const char* FirstElement();
	const char* NextElement();

	const char* Pop();
	void Reset();

	Node* m_headTList; //Guarda el primer nodo
	Node* m_ptrIterator; //auxiliar para operaciones
	int m_num_nodes;


};