#pragma once
#include "Equipo.h"

class RealMadrid : public IEquipo
{

public:
	RealMadrid();
	~RealMadrid();

	virtual const char* GetTeamName() override;
	virtual const char* GetMisterName() override;
	virtual int GetPointLiga() override;
	virtual void GanarPartido() override;
	virtual void EmpatarPartido() override;
};