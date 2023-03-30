#pragma once

#include <iostream>
#include <stdlib.h>


#include "Node.h"

class TList
{
public:
	TList();
	TList(TList*& other); //Constructor copia

	~TList();

	int ElementsCounter();

	int GetCurrentElementID();
	const char* GetCurrentElementData();
	int Push(const char* _dataNewNode);
	
	const char* GetFirstElement();
	const char* GetPreviousElement();
	
	const char* GetNextElement();
	const char* GetLastElement();

	//Node* GetCurrentElement(Node* _auxNode);
	const char* Pop();
	void Reset();

	Node* m_headTList; //Guarda el primer nodo
	Node* m_tailTList;
	Node* m_ptrIterator; //auxiliar para operaciones
	int m_num_nodes;


	static TList GetReverseList(TList _originalList);
};

