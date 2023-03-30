#pragma once


class Node
{
public:
	Node();
	//Node(const char* _data);
	~Node();


	Node* m_nextNode;
	Node* GetNextNode();

	const char* m_data;
	const char* GetNodeData(); //Creado por cantidad de accesos a m_data
};

