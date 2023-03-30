#pragma once
#include "Barcelona.h"


CFcBarcelona::CFcBarcelona()
{
	m_ptrTeamName = " -FC Cagalona- ";
	m_ptrMisterName = " -Mr. Satian, el cabrero- ";
	m_iPuntosLiga = 10;
}

CFcBarcelona::~CFcBarcelona()
{
}

const char* CFcBarcelona::GetTeamName()
{
	return m_ptrTeamName;
}

const char* CFcBarcelona::GetMisterName()
{
	return m_ptrMisterName;
}

int CFcBarcelona::GetPointLiga()
{
	return m_iPuntosLiga;
}

void CFcBarcelona::GanarPartido()
{
	std::cout << "El equipo -" << m_ptrTeamName << "- Ha ganado su partido!\n";
	m_iPuntosLiga += 3;
}
void CFcBarcelona::EmpatarPartido()
{
	std::cout << "El equipo -" << m_ptrTeamName << "- Ha empatado su partido!\n";
	m_iPuntosLiga += 1;
}