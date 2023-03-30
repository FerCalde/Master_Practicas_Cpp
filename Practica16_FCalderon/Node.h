#pragma once
#include"Equipo.h"

class Node
{
public:
	Node();
	//Node(const char* _data);
	~Node();


	Node* m_nextNode;
	Node* GetNextNode();

	IEquipo* m_data;
	IEquipo* GetNodeData(); //Creado por cantidad de accesos a m_data
};

