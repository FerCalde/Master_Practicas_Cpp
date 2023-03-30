#include <iostream>
#include"Node.h"



Node::Node()
{
	m_nextNode = nullptr;
	m_data = nullptr;
}

Node::~Node()
{
	/*if ((m_data != nullptr) && (m_nextNode != nullptr))
	{
	}*/
		m_nextNode = nullptr;
		m_data = nullptr;
		delete m_nextNode;

		delete m_data;
		std::cout << "\tEliminadas las variables del node\n";
}


const char* Node::GetNodeData()
{
	return m_data;
}


Node* Node::GetNextNode()
{
	return m_nextNode;
}