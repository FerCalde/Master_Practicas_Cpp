#pragma once


class Node
{
public:
	Node();
	//Node(const char* _data);
	~Node();


	Node* m_nextNode;
	Node* GetNextNode();

	Node* m_previousNode;
	Node* GetPreviousNode();

	int m_idNode;
	int GetNodeID();
	const char* m_data;
	const char* GetNodeData(); //Creado por cantidad de accesos a m_data
};

