#include <iostream>
#include"Node.h"



Node::Node()
{
	//std::cout << "\Constructor de Nodo\n";

	m_nextNode = nullptr;
	m_previousNode = nullptr;
	m_data = nullptr;
	m_idNode = 0;
}
//Node::Node(const char* _data)
//	: m_data(_data)
//{
//	m_nextNode = nullptr;
//}
Node::~Node()
{
	m_nextNode = nullptr;
	m_previousNode = nullptr;
	m_data = nullptr;

	delete m_nextNode;
	delete m_previousNode;
	delete m_data;

	//std::cout << "\tEliminadas las variables del node\n";
}


const char* Node::GetNodeData()
{
	if (m_data)
	{
		return m_data;
	}
	else
	{
		return "Error! Cant GetNodeData cause List is Empty";
	}
}
int Node::GetNodeID()
{
	
		 return m_idNode;
}

Node* Node::GetNextNode()
{
	return m_nextNode;
}

Node* Node::GetPreviousNode()
{
	return m_previousNode;
}