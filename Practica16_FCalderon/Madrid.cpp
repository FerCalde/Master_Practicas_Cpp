#pragma once
#include"Madrid.h"


RealMadrid::RealMadrid()
{
	m_ptrTeamName = " -Rial de Mandril- ";
	m_ptrMisterName = " -Z.Z. Calvito loteria- ";
	m_iPuntosLiga = 50;
}

RealMadrid::~RealMadrid()
{
}

const char* RealMadrid::GetTeamName()
{
	return m_ptrTeamName;
}

const char* RealMadrid::GetMisterName()
{
	return m_ptrMisterName;
}

int RealMadrid::GetPointLiga()
{
	return m_iPuntosLiga;
}

void RealMadrid::GanarPartido()
{
	std::cout << "El equipo -" << m_ptrTeamName << "- Ha ganado su partido!\n";
	m_iPuntosLiga += 3;
}
void RealMadrid::EmpatarPartido()
{
	std::cout << "El equipo -" << m_ptrTeamName << "- Ha empatado su partido!\n";
	m_iPuntosLiga += 1;
}