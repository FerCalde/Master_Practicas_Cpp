#pragma once
#include "Atletico.h"


AtMadrid::AtMadrid()
{
	m_ptrTeamName = " -Patetico de Madriz- ";
	m_ptrMisterName = " -OLE OLE OLE EL XHOLO SIMEONE- ";
	m_iPuntosLiga = 24;
}

AtMadrid::~AtMadrid()
{
}

const char* AtMadrid::GetTeamName()
{
	return m_ptrTeamName;
}

const char* AtMadrid::GetMisterName()
{
	return m_ptrMisterName;
}

int AtMadrid::GetPointLiga()
{
	return m_iPuntosLiga;
}

void AtMadrid::GanarPartido()
{
	std::cout << "El equipo -" << m_ptrTeamName << "- Ha ganado su partido!\n";
	m_iPuntosLiga += 3;
}
void AtMadrid::EmpatarPartido()
{
	std::cout << "El equipo -" << m_ptrTeamName << "- Ha empatado su partido!\n";
	m_iPuntosLiga += 1;
}