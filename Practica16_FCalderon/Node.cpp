#include <iostream>
#include"Node.h"



Node::Node()
{
	m_nextNode = nullptr;
	m_data = nullptr;
}

Node::~Node()
{

		m_nextNode = nullptr;
		m_data = nullptr;
		delete m_nextNode;
		delete m_data;

		std::cout << "\tEliminadas las variables del node\n";
}


IEquipo* Node::GetNodeData()
{
	return m_data;
}


Node* Node::GetNextNode()
{
	return m_nextNode;
}